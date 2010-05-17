/**
 * File: smokeparticlesystem.cpp
 * Author: Kevin Jacobson
 * Author: Mark Willson
 */

#include "smokeparticlesystem.h"
#include "GL/glut.h"
#include <assert.h>
#include <math.h>
using namespace pengine;
using namespace std;


SmokeParticleSystem::SmokeParticleSystem(const Vector3& origin, const real maxMagnitude, const Vector3& gravity)
: ParticleSystem(origin,maxMagnitude,gravity) {
    //Initialize random-ness
    bounciness = .09;
    maxParticles = 300;
}

void SmokeParticleSystem::spawnParticle() {
    if( rand() % 2 == 0){
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


void SmokeParticleSystem::drawParticles(){
    std::vector<Vector3> positions = getPositions();
    float alpha = 0.0f;
    for(int i=0;i < positions.size(); i++)
    {   
        glColor4f(.4f,.4f,.4f,alpha);;
        alpha += 1.0f/positions.size();
        Vector3 position = positions[i];
        glPushMatrix();
        glTranslatef(position.x,position.y,position.z);
        glutSolidSphere(0.5f,10,10);
        glPopMatrix();
    }
}
