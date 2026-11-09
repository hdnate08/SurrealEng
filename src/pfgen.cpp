#include <surreal/pfgen.hpp>
#include <vector>

namespace surreal {

auto ParticleForceRegistry::update_forces(real duration) -> void
{
    for(const auto& reg : registrations)
    {
        reg.fg->update_force(reg.particle, duration);
    }
}

auto ParticleForceRegistry::add(Particle* particle, ParticleForceGenerator *fg) -> void
{
    ParticleForceRegistry::ParticleForceRegistration registration;
    registration.particle = particle;
    registration.fg = fg;
    registrations.push_back(registration);
}

auto ParticleForceRegistry::remove(Particle* particle, ParticleForceGenerator *fg) -> void
{
    std::erase_if(registrations, [particle, fg](const auto& reg)
    {
        return reg.particle == particle && reg.fg == fg;
    });
}

auto ParticleForceRegistry::clear() -> void
{
    registrations.clear();
}

auto ParticleGravity::update_force(Particle* particle, real duration) -> void
{
    (void)duration;
    // check for infinite mass
    if(!particle->has_finite_mass()) return;

    // Apply the mass-scaled force to the particle
    particle->add_force(gravity * particle->get_mass());
}

} // namespace surreal