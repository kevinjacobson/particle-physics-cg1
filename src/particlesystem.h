#ifndef __PARTICLESYSTEM_H__
#define __PARTICLESYSTEM_H__

/*
 * File: particlesystem.h
 * Author: Kevin Jacobson
 * Author: Mark Willson
 *
 * Abstract class for managing a system of particles
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "pengine.h"
#include "GL/glut.h"

#define MAX_PARTICLES 10000

namespace pengine {
    
    class ParticleSystem
    {
    protected:

        Vector3 origin; //Point from which the particles spawn

        Vector3 min;

        Vector3 max; //Define the bounding rectangular prism!

        real maxMagnitude; //Max speed of a spawned particle

        std::vector<Particle> particles; //List of particles to manage

        Vector3 gravity; //Acceleration from gravity TODO remove this :(

        real bounciness;

    public:
        /**
         * Constructs a new system
         */
         ParticleSystem(const Vector3& origin, const Vector3& min, const Vector3& max, const real maxMagnitude, const Vector3& gravity){
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

             this->maxMagnitude = maxMagnitude;
             this->gravity = gravity;
             srand(time(NULL));
         }


         ParticleSystem() {}

         virtual void spawnParticle() = 0;

         void updateSystem(real duration) {
             spawnParticle();
             std::vector <Particle>::iterator it = particles.begin();

             for(; it!= particles.end(); it++) {
                 it->integrate(duration);
                 if (it->position.y < 0){
                     it->velocity.y = -1 * it->velocity.y * bounciness;
                     it->position.y = 0;
                 }
             }
            
         }

         virtual void drawParticles() = 0;

         int getNumParticles() {
             return particles.size();
         }
    protected:
        
        void addParticle(const Vector3& velocity) {
            particles.push_back(Particle(origin,velocity,gravity,1));
        }

        void pruneParticles() {
            if(particles.size() > MAX_PARTICLES) {
                std::vector <Particle>::iterator it = particles.begin();
                particles.erase(it,it+(getNumParticles()-MAX_PARTICLES));
            }
        }


    };
    
}

#endif /*__PARTICLESYSTEM_H__*/
