/*
 * File: bloodparticlesystem.h
 * Author: Mark Willson
 *
 */

#ifndef _BLOODPARTICLESYSTEM_H__
#define _BLOODPARTICLESYSTEM_H__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "pengine.h"
#include "GL/glut.h"

namespace pengine {

    class BloodParticleSystem
    {
        Vector3 origin; //Point from which all blood spawns

        Vector3 min; 

        Vector3 max;  //Define the bounding rectangular prism!
        
        real maxMagnitude; //Max speed of spawned particle
        
        std::vector<Particle> particles; //List of particles to spawn

        Vector3 gravity;

        int MAX_SIZE;

        real bounciness;

        real height;

    public:
        /**
         * Constructs a new blood spurting geiser
         * @param origin spawning point of the system
         * @param min bottom-left corner of bounds
         * @param max top-right corner of bounds
         * @param maxMagnitude max speed of spawned particle
         */
        BloodParticleSystem(const Vector3& origin, const Vector3& min, const Vector3& max, const real maxMagnitude);

        BloodParticleSystem();
        
        /**
         * Spawns a new particle at the origin
         */
        void spawnParticle();

        /**
         * Updates all particles in the system
         */
        void updateSystem(real duration);
        
        /*
         * Uses OpenGL to draw each particle
         */
        void drawParticles();

        int getNumParticles(){
            return particles.size();
        }
    private:

        void addParticle(const Vector3& velocity);

        void pruneParticles();

    


    };


}


#endif /*_BLOODPARTICLESYSTEM_H__*/
