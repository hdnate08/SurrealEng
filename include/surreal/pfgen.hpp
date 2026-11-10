#ifndef PFGEN_HPP_
#define PFGEN_HPP_

#include <surreal/particle.hpp>
#include <vector>

namespace surreal {

// A force generator can be asked to add a force to one or more particles
class ParticleForceGenerator {
    public:
        virtual auto update_force(Particle *particle, real duration) -> void = 0;
};

// Holds all the force generators and the particles that they apply to
class ParticleForceRegistry {
    protected:
        // Keeps track of one force generator and the particle it applies to
        struct ParticleForceRegistration
        {
            Particle *particle;
            ParticleForceGenerator *fg;
        };

        // Holds list of registrations
        typedef std::vector<ParticleForceRegistration> Registry;
        Registry registrations;

    public:
        // Registers the given force generator to apply to the given particle
        auto add(Particle* particle, ParticleForceGenerator *fg) ->void;

        // Removes the given registered pair from the registry
        // If the pair is not registered, this method will have no effect
        auto remove(Particle* particle, ParticleForceGenerator *fg) -> void;

        // Clears all registrations from the registry. This will not delete the particles
        // or the force generators themselves, just the records of their connection
        auto clear() -> void;

        // Calls all the force generators to update the forces of their corresponding particles
        auto update_forces(real duration) -> void;
};

// A force generator that applies a gravitational force. One instance can be used for multiple
// particles
class ParticleGravity : public ParticleForceGenerator {
    // Holds acceleration due to gravity
    Vector3 gravity;

    public:
        // Creates the generator with the given acceleration
        ParticleGravity(const Vector3& _gravity) : gravity(_gravity) {};

        // Applies the gravitational force to the given particle
        virtual auto update_force(Particle* particle, real duration) -> void;
};

} // namspace surreal

#endif