/* 
 * File:   precision.h
 * Author: Mark Willson
 * Author: Kevin Jacobsonn
 *
 * Created on April 27, 2010, 3:58 PM
 */

#ifndef _PRECISION_H
#define	_PRECISION_H

#include <math.h>
namespace pengine{

    /**
     * Defines the real number precision of the engine.
     * Changing this value allows the program to be compiled
     * with single- or double-precision floating points
     */    
    typedef float real;
    #define real_sqrt sqrtf
    #define real_pow powf
}


#endif	/* _PRECISION_H */

