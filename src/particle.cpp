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

} // namespace surreal