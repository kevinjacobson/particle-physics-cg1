#include "particleforcegen.h"

using namespace pengine;

void ParticleForceRegistry::updateForces(real duration)
{
    Registry::iterator i = registrations.begin();

    for(; i != registrations.end(); i++)
    {
        i->forcegen->updateForce(i->particle, duration);
    }
}


void ParticleGravity::updateForce(Particle* particle, real duration)
{
    //Check that mass is not infinite
    if(particle->hasInfiniteMass()) return;

    //Apply mas-scaled force in the particle
    particle->addForce(gravity * particle->getMass());
}

void ParticleDrag::updateForce(Particle* particle, real duration)
{
    Vector3 force;
    particle->getVelocity(&force);

    real dragCoeff = force.magnitude();
    dragCoeff = k_1 * dragCoeff + k_2 * dragCoeff * dragCoeff;

    //Calculate the final force and apply it.
    force.normalize();
    force *= -dragCoeff;
    particle->addForce(force);
}
