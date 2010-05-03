#ifndef __DRAWABLEPARTICLE_H__
#define __DRAWABLEPARTICLE_H__

#include "particle.h"

namespace pengine{
    
    class DrawableParticle : public Particle
    {
        //Field
        private:
            /**
             * Holds the values for RGBA colors
             * color[0] = red
             * color[1] = green
             * color[2] = blue
             * color[3] = alpha
             */
            real color[4];
            int age; 
        //Constructor
        public:
            DrawableParticle() : Particle(){
                color[0] = 0;
                color[1] = 0;
                color[2] = 0;
                color[3] = 0;
                age = 0;
            }

            DrawableParticle(const Vector3& position, 
                const Vector3& velocity,
                real mass,
                real* color) : 
                    Particle(position,velocity,mass),
                     age(0)
            {
                //Copy color
                int i;
                for(i = 0; i < 4; i++)
                {
                    (this->color)[i] = color[i];
                }
            }
        
        //Accessors
        public:

        /**
         * Returns a pointer to the first element of the color list
         */
        real* getColor();

        /**
         * Sets the color of the particle to a new color
         */ 
        void setColor(real* color);        
        
        /**
         * Points result to the color
         */
        void getColor(real* result);

        /**
         * Returns red value of color
         */
        real getRed();

        /**
         * Set red color component to new value
         * @return original red
         */
        real setRed(real red);

        /**
         * Returns green value of color
         */
        real getGreen();
        
        /**
         * Set green component to new value
         * @return original green
         */
        real setGreen(real green);

        /**
         * Set blue component to new value
         * @return original blue
         */
        real setBlue(real blue);
        /**
         * Returns blue value of color
         */
        real getBlue();

        /**
         * Returns alpha (transparency) value of color
         */
        real getAlpha();

                

            
    };

}


#endif /* __DRAWABLEPARTICLE_H__ */
