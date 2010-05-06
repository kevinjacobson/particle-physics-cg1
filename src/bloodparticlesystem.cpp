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


BloodParticleSystem::BloodParticleSystem(const Vector3& origin, const Vector3& min, const Vector3& max, const real maxMagnitude, const Vector3& gravity)
: ParticleSystem(origin,min,max,maxMagnitude,gravity) {
    //Initialize random-ness
    bounciness = .09;

}

void BloodParticleSystem::spawnParticle() {
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

/*void BloodParticleSystem::updateSystem(real duration) {
    spawnParticle();
    std::vector <Particle>::iterator it = particles.begin();
   
    for (; it != particles.end(); it++) {
        it->integrate(duration);
        if(it->position.y < 0){
            it->velocity.y = -1 * it->velocity.y * bounciness;
            it->position.y = 0;
        }
    }

    pruneParticles();
}*/

/*void BloodParticleSystem::addParticle(const Vector3& velocity) {
    particles.push_back(Particle(origin, velocity, gravity, 1));
}*/

/*void BloodParticleSystem::pruneParticles() {
    if(particles.size() > MAX_SIZE){
        std::vector <Particle>::iterator it = particles.begin();
        particles.erase(it,it+(particles.size()-MAX_SIZE));
    }
}*/

void BloodParticleSystem::drawParticles(){
   // glPushMatrix();

    std::vector <Particle>::iterator it = particles.begin();
    glColor3f(1.0,0,0);
    for (; it != particles.end(); it++) {
//        int x = it->position.x;
//        int y = it->position.y;
//        glRecti(x,y,x+6,y+6);
        glBegin(GL_LINES);
            glVertex3f(it->position.x,
                       it->position.y,
                       0);
            glVertex3f(it->position.x - it->velocity.x,
                       it->position.y - it->velocity.y,
                       0);
       glEnd();
    }

  //  glPopMatrix();
}
