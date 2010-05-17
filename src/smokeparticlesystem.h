/*
 * File: smokeparticlesystem.h
 * Author: Mark Willson
 *
 */

#ifndef _SMOKEPARTICLESYSTEM_H__
#define _SMOKEPARTICLESYSTEM_H__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "pengine.h"
#include "particlesystem.h"
#include "GL/glut.h"

namespace pengine {

    class SmokeParticleSystem : public ParticleSystem
   {
    public:
        /**
         * Constructs a new smoke spurting geiser
         * @param origin spawning point of the system
         * @param maxMagnitude max speed of spawned particle
         * @param gravity gravity acting on smoke (or smoke bouyancy)
         */
        SmokeParticleSystem(const Vector3& origin, const real maxMagnitude, const Vector3& gravity);

        SmokeParticleSystem() : ParticleSystem() {};
        
        /**
         * Spawns a new particle at the origin
         */
        virtual void spawnParticle();

        virtual void drawParticles();



    };


}


#endif /*_SMOKEPARTICLESYSTEM_H__*/
