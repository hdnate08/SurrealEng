#include <surreal/pfgen.hpp>

namespace surreal {

auto ParticleForceRegistry::update_forces(real duration) -> void
{
    for(const auto& reg : registrations)
    {
        reg.fg->update_force(reg.particle, duration);
    }
}

} // namespace surreal