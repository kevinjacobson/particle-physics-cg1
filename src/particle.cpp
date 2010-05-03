#include <assert.h>
#include "particle.h"

using namespace pengine;


Particle::Particle()
{
    position = Vector3();
    velocity = Vector3();
    acceleration = Vector3();
    forceAccum = Vector3();
    inverseMass = 1;
}

Particle::Particle(const Vector3& position, const Vector3& velocity, real mass) :
    position(position), velocity(velocity), acceleration(), forceAccum() 
{
    inverseMass = 1/mass;
    
}


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
    //velocity *= real_pow(damping, duration);

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
    return inverseMass != 0.0;
}

int Particle::hasInfiniteMass()
{
    return inverseMass == 0.0;
}

real Particle::getMass()
{
    assert(inverseMass > 0);
    return 1.0/inverseMass;
}

real Particle::getInverseMass()
{
    return inverseMass;
}

void Particle::getVelocity(Vector3* result){
    *result = velocity;
}

Vector3 Particle::getVelocity(){
    return velocity;
}

void Particle::getPosition(Vector3* result){
    *result = position;
}

Vector3 Particle::getPosition(){
    return position;
}

void Particle::getAcceleration(Vector3* result){
    *result = acceleration;
}

Vector3 Particle::getAcceleration(){
    return acceleration;
}
