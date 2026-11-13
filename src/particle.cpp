#include <cassert>

#include <surreal/particle.hpp>

namespace surreal{

auto Particle::integrate(real duration) -> void 
{
    
    // We don't integrate objects with infinite mass
    if (inverse_mass <= 0) return;

    assert(duration > 0);

    // Update linear position
    position.add_scaled_vector(velocity, duration);

    // Work out acceleration from force
    auto resulting_acceleration = acceleration;
    resulting_acceleration.add_scaled_vector(resulting_acceleration, duration);

    // Update linear velocity from acceleration
    velocity.add_scaled_vector(resulting_acceleration, duration);

    // Impose drag
    velocity *= real_pow(damping, duration);

    clear_accumulator();
}

auto Particle::clear_accumulator() -> void 
{
    force_accumulation.clear();
}

auto Particle::add_force(const Vector3 &force) -> void
{
    force_accumulation += force;
}

auto Particle::get_mass() const -> real
{
    if(!(has_finite_mass()))
    {
        return std::numeric_limits<real>::max();
    }

    return static_cast<real>(1.0) / inverse_mass;
}

auto Particle::has_finite_mass() const -> bool
{
    return inverse_mass > 0.0;
}

auto Particle::get_velocity(Vector3* out_velocity) const -> void
{
    *out_velocity = velocity;
}

auto Particle::get_position(Vector3* out_position) const -> void
{
    *out_position = position;
}

auto Particle::get_position() const -> Vector3
{
    return position;
}

} // namespace surreal