#ifndef PFGEN_HPP_
#define PFGEN_HPP_

#include <surreal/particle.hpp>

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
            ParticleForceGnerator *fg;
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

} // namspace surreal

#endif