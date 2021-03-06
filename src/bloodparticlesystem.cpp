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


BloodParticleSystem::BloodParticleSystem(const Vector3& origin, const real maxMagnitude, const Vector3& gravity)
: ParticleSystem(origin,maxMagnitude,gravity) {
    //Initialize random-ness
    bounciness = .09;
    maxParticles = 10000;

}

void BloodParticleSystem::spawnParticle() {
    if (rand() % 2 == 0) {
    real x, y, z, s;
    x = (real) (rand() % 1000 - 500);
    y = (real) (rand() % 1000 - 500);
    z = (real) (rand() % 1000 - 500);
    Vector3 v = Vector3(x, y, z);
    v.normalize();
    s = maxMagnitude;
    v *= s;
    addParticle(v);
    }

}

void BloodParticleSystem::drawParticles(){
    std::vector<Vector3> positions = getPositions();
    glColor4f(1.0f,0.0f,0.0f,.7f);
    for(int i=0;i < positions.size(); i++)
    {   
        Vector3 position = positions[i];
        glPushMatrix();
        glTranslatef(position.x,position.y,position.z);
        glutSolidSphere(.1f,6,6);
        glPopMatrix();
    }
}
