/* 
 * File:   particle.h
 * Author: Kevin Jacobson
 *
 * Created on April 27, 2010, 4:39 PM
 */

#ifndef _PARTICLE_H
#define	_PARTICLE_H

#include "foundation.h"

namespace pengine{
    /**
     * Represents a particle a simple object in the physics engine
     */
    class Particle
    {

        //Fields
        public:
            /**
             * Holds the linear position of the particle in space
             */
            Vector3 position;

            /**
             * Holds the linear velocity of the particle
             */
            Vector3 velocity;

            /**
             * Holds the acceleration (ie. due to gravity)
             */
            Vector3 acceleration;

            /**
             * Holds the accumulated force to be applied
             *  in the next integration ONLY. Value is zeroed afterwards
             */
            Vector3 forceAccum;

            /**
             * Holds a factor by which the motion is dampened
             */
            real damping;

            /**
             * Holds the inverse of the mass of the particle
             * Helps speed up calculation speed and also allows
             * Infinite mass (set to 0)
             */
            real inverseMass;



            //Mutators
        public:
            /**
             * Updates the simulation, applying and then clearing the forces
             * @param duration time integrations should simulate
             */
            void integrate(real duration);

            /**
             * Resets the force accumulator
             */
            void clearAccumulator();

            /**
             * Adds a given force to a particle, only applied next integration
             */
            void addForce(const Vector3& force);

            /**
             * Returns non-zero if mass is finite, otherwise 0
             */
            int hasFiniteMass();

            /**
             * Returns non-zero if mass is finite, otherwise 0
             */
            int hasInfiniteMass();
            
            //Accessors
        public:
            /**
             * Returns the mass of the particle
             */
            int getMass();

            /**
             * Sets result to the velocity vector
             */
            void getVelocity(Vector3* result);

    };
}




#endif	/* _PARTICLE_H */

