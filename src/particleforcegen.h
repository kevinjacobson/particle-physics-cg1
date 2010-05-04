/* 
 * File:   particleforcegen.h
 * Author: Mark Willson
 * Author: Kevin Jacobson
 *
 * Created on April 27, 2010, 5:10 PM
 */

#ifndef _PARTICLEFORCEGEN_H
#define	_PARTICLEFORCEGEN_H

#include <vector>

#include "particle.h"


namespace pengine {
    /**
     * Intersface, can generator a force to add to one or more particles
     */
    class ParticleForceGenerator
    {
        public:

            /** Applies generated force a particle*/
            virtual void updateForce(Particle* particle, real duration) = 0;

    };

    class ParticleForceRegistry
    {
        //Fields
        protected:
            /**
             * Keeps track of one force generator and the particle
             * it applies to
             */
            struct ParticleForceRegistration
            {
                Particle* particle;
                ParticleForceGenerator* forcegen;
            };

            /**
             * Holds list of registrations
             */
            typedef std::vector<ParticleForceRegistration> Registry;
            Registry registrations;

        public:
            /**
             * Registers the given force generator to apply to the
             * given particle
             */
            void add(Particle* particle,ParticleForceGenerator *fg);

            /**
             * Remoes the given registered pair from the registery,
             * if they aren't in the registry, no side effect
             */
            void remove(Particle* particle,ParticleForceGenerator *fg);


            /**
             * Clears all registrations
             */
            void clear();

            /**
             * Calls all the force generators to update the forces on
             * their particles
             */
            void updateForces(real duration);

    };

    /**
     * A force generator that applies the force of gravity
     */
    class ParticleGravity : public ParticleForceGenerator
    {
        /** Holds the force of gravity as a vector on the particle */
        Vector3 gravity;

        public:
        ParticleGravity(const Vector3& gravity){
            this->gravity = gravity;
        }

        virtual void updateForce(Particle* particle, real duration);
    };

    /**
     * A force generator that applies the force of drag
     */
    class ParticleDrag : public ParticleForceGenerator
    {
        /** Holds the velocity drag coefficient */
        real k_1;

        /** Holds the velocity squared drag coefficient */
        real k_2;

        public:
            
            /** Constructor for generator */
            ParticleDrag(real k_1, real k_2) : 
                k_1(k_1), k_2(k_2) {}

            /** Applies the drag force to the given particle */
            virtual void updateForce(Particle* particle, real duration);
    };


}




#endif	/* _PARTICLEFORCEGEN_H */

