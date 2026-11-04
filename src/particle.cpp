#include <assert>

#include "surreal/particle.hpp"

auto Particle::integrate(real duration) {
    
    // We don't integrate objects with infinite mass
    if (inverse_mass <= static_cast<surreal::real>(0.0)) return;

    assert(duration > static_cast<surreal::real>(0.0));

    // Update linear position
    position.add_scaled_vector(velocity, duration);

    // Work out acceleration from force
    auto resulting_acceleration = acceleration;

    // Update linear velocity from acceleration
    velocity.add_scaled_vector(resulting_acceleration, duration);

    // Impose drag
    velocity *= real_pow(damping, duration);

    // TODO: Clear forces
    //clear_accumulator();
}