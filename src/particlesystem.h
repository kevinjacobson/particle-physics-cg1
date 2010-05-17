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

        int maxParticles;

    public:
        /**
         * Constructs a new system
         */
         ParticleSystem(const Vector3& origin, const real maxMagnitude, const Vector3& gravity){
             this->origin = origin;
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
             }
            
         }

         virtual void drawParticles() = 0;

         int getNumParticles() {
             return particles.size();
         }

         std::vector <Vector3> getPositions() {
             std::vector<Vector3> positions;
             std::vector <Particle>::iterator it = particles.begin();
             for(; it!=particles.end(); it++)
             {
                 positions.push_back(it->position);
             }
             return positions;
         }

    protected:
        
        void addParticle(const Vector3& velocity) {
            particles.push_back(Particle(origin,velocity,gravity,1));
            pruneParticles();
        }

        void pruneParticles() {
            if(particles.size() > maxParticles) {
                std::vector <Particle>::iterator it = particles.begin();
                particles.erase(it,it+(getNumParticles()-maxParticles));
            }
        }


    };
    
}



#endif /*__PARTICLESYSTEM_H__*/
