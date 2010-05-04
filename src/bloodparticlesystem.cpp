/**
 * File: bloodparticlesystem.cpp
 * Author: Kevin Jacobson
 * Author: Mark Willson
 */

#include "bloodparticlesystem.h"
#include "GL/glut.h"
#include <assert.h>
#include <math.h>
using namespace pengine;
using namespace std;


BloodParticleSystem::BloodParticleSystem(const Vector3& origin, const Vector3& min, const Vector3& max, const real maxMagnitude) {

    this->origin = origin;



    if (min.x > max.x) {
        this->min.x = max.x;
        this->max.x = min.x;
    }
    if (min.y > max.y) {
        this->min.y = max.y;
        this->max.y = min.y;
    }
    if (min.z > max.z) {
        this->min.z = max.z;
        this->max.z = min.z;
    }


    MAX_SIZE = 100000;

    this-> maxMagnitude = maxMagnitude;
    gravity = Vector3(0, -.01, 0);
    //Initialize random-ness
    srand(time(NULL));

}

BloodParticleSystem::BloodParticleSystem()
{
}

void BloodParticleSystem::spawnParticle() {
    real x, y, z, s;
    x = (real) (rand() % 50 - 25);
    y = (real) (rand() % 50 - 25);
    z = (real) (rand() % 50 - 25);
    Vector3 v = Vector3(x, y, z);
    v.normalize();
    s = maxMagnitude;
    v *= s;
                     
    addParticle(v);

}

void BloodParticleSystem::updateSystem(real duration) {
    spawnParticle();
    std::vector <Particle>::iterator it = particles.begin();
   
    for (; it != particles.end(); it++) {
        it->integrate(duration);
    }

    pruneParticles();
}

void BloodParticleSystem::addParticle(const Vector3& velocity) {
    particles.push_back(Particle(origin, velocity, gravity, 1));
}

void BloodParticleSystem::pruneParticles() {
    if(particles.size() > MAX_SIZE){
        std::vector <Particle>::iterator it = particles.begin();
        particles.erase(it,it+(particles.size()-MAX_SIZE));
    }
}

void BloodParticleSystem::drawParticles(){

   // glPushMatrix();

    std::vector <Particle>::iterator it = particles.begin();
    glColor3f(1.0,0,0);
    for (; it != particles.end(); it++) {
        int x = it->position.x;
        int y = it->position.y;
        glRecti(x,y,x+6,y+6);
    }

  //  glPopMatrix();
}
