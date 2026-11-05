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
        
    protected:
        // Holds the linear position of the particle in world space
        Vector3 position;

        // Holds the linear velocity of the particle in world space
        Vector3 velocity;

        // Holds the acceleration of the particle. This value can be used to set acceleration
        // due to gravity, or any other constant acceleration
        Vector3 acceleration;

        // Holds the amount of damping applied to linear motion. Damping is required to remove energy
        // added through numerical instability in the integrator
        real damping;

        // Holds the inverse of the mass of the particle. It is more useful
        // to hold the inverse mass because integration is simpler, and because
        // in real-time simulation it is more useful to have objects with infinite
        // mass (immovable) than zero mass (completely unstable)
        real inverse_mass;
};

} // namespace surreal

#endif