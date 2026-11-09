#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <surreal/precision.hpp>
#include <surreal/core.hpp>

namespace surreal {

// A particle is the simplest object that can be simulated in the physics system
class Particle
{
    public:
        // Integrates the particle forward in time by the given amount. This function uses
        // a Newton-Euler integration method, which is a linear approximation to the correct
        // integral. For this reason it may be innaccurate in some cases
        auto integrate(real duration) -> void;

        // Adds the given force to the particle to be applied at the next iteration only
        auto add_force(const Vector3 &force) -> void;

        // Returns this particle's mass
        auto get_mass() const -> real;

        // Returns true if particle has infinite mass
        auto has_finite_mass() const -> bool;
        
    protected:
        // Holds the linear position of the particle in world space
        Vector3 position;

        // Holds the linear velocity of the particle in world space
        Vector3 velocity;

        // Holds the acceleration of the particle. This value can be used to set acceleration
        // due to gravity, or any other constant acceleration
        Vector3 acceleration;

        // Holds the accumulated force to be applied at the next simulation iteration only. This value
        // is zeroed after each integration step
        Vector3 force_accumulation;

        // Holds the amount of damping applied to linear motion. Damping is required to remove energy
        // added through numerical instability in the integrator
        real damping;

        // Holds the inverse of the mass of the particle. It is more useful
        // to hold the inverse mass because integration is simpler, and because
        // in real-time simulation it is more useful to have objects with infinite
        // mass (immovable) than zero mass (completely unstable)
        real inverse_mass;

        // Clears the forces applied to the particle. This will be called automatically after each
        // integration step
        auto clear_accumulator() -> void;
};

} // namespace surreal

#endif