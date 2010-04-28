#include <assert.h>
#include "particle.h"

using namespace pengine;

void Particle::integrate(real duration)
{
    assert(duration > 0.0);

    //Update linear position
    position.addScaledVector(velocity, duration);

    //Calculate acceleration
    Vector3 resultingAcc = acceleration;
    resultingAcc.addScaledVector(forceAccum, inverseMass);

    //Update linear velocity from the acceleration
    velocity.addScaledVector(resultingAcc,duration);

    // Impose drag.
    velocity *= real_pow(damping, duration);

    // Clear the force
    clearAccumulator();
}

void Particle::clearAccumulator(){
    forceAccum.clear();
}

void Particle::addForce(const Vector3& force)
{
    forceAccum += force;
}

int Particle::hasFiniteMass()
{
    return inverseMass != 0;
}

int Particle::hasInfiniteMass()
{
    return inverseMass == 0;
}

int Particle::getMass()
{
    assert(inverseMass > 0);
    return 1/inverseMass;
}

void Particle::getVelocity(Vector3* result){
    *result = velocity;
}
