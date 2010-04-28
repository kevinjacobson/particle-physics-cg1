/* 
 * File:   foundation.h
 * Author: Kevin Jacobson
 *
 * Created on April 27, 2010, 4:00 PM
 */

#ifndef _FOUNDATION_H
#define	_FOUNDATION_H

#include "precision.h"

namespace pengine {

    /**
     * Handles a 3D vector
     */

    class Vector3 {

        //FIELDS
    public:
        real x;
        real y;
        real z;
    private:
        real padding; //Ensures 4-word alignment

    public:

        /* Default, constructs vector (0,0,0)*/
        Vector3() : x(0), y(0), z(0) {
        }

        /* Specify (x,y,z)*/
        Vector3(const real x, const real y, const real z)
        : x(x), y(y), z(z) {
        }


        //Accessors

        /** Gets magnitude of vector*/
        real magnitude() const {
            return real_sqrt(x*x+y*y+z * z);
        }

        /** Gets the square magnitude of this vector*/
        real squareMagnitude() const {
            return x * x + y * y + z*z;
        }

        //Mutators

        /*Negates all components of the vector*/
        void invert() {
            x = -x;
            y = -y;
            z = -z;
        }

        /** Turns a non-zero vector into a vector of unit length
         * (magnitude of 1)
         */
        void normalize() {
            real mag = magnitude();
            if (mag > 0) {
                (*this) *= ((real) 1) / mag;
            }
        }

        /** Sets all values to default*/
        void clear() {
            x = 0;
            y = 0;
            z = 0;
        }
        

        /** Scaler multiply the vector */
        void operator*=(const real s) {
            x *= s;
            y *= s;
            z *= s;
        }

        /** Returns copy of vector multiplied by scalar */
        Vector3 operator*(const real s) const {
            return Vector3(x*s, y*s, z * s);
        }

        /** Adds the given vector to this one */
        void operator+=(const Vector3& other) {
            x += other.x;
            y += other.y;
            z += other.z;
        }

        /** Returns this + other as a new vector */
        Vector3 operator*(const Vector3& other) const {
            return Vector3(x + other.x, y + other.y, z + other.z);
        }

        /** Subtracts other from this*/
        void operator-=(const Vector3& other) {
            x -= other.x;
            y -= other.y;
            z -= other.z;
        }

        /** Returns this - other as a new vector*/
        Vector3 operator-(const Vector3& other) const {
            return Vector3(x - other.x, y - other.y, z - other.z);
        }

        /** Adds to the given vector, s*other */
        void addScaledVector(const Vector3& other, real s) {
            x += other.x*s;
            y += other.y*s;
            z += other.z*s;
        }

        /** Calculates and returns component-wise product*/
        Vector3 componentProduct(const Vector3& other) const {
            return Vector3(x * other.x, y * other.y, z * other.z);
        }

        /**Self-mutating componentProduct*/
        void componentProductUpdate(const Vector3& other) {
            x *= other.x;
            y *= other.y;
            z *= other.z;
        }

        /** Calculates dot-product of this*other */
        real scalarProduct(const Vector3& other) const {
            return x * other.x + y * other.y + z * other.z;
        }

        /** Aliases the operator* to scalarProduct*/
/*        real operator *(const Vector3& other) const {
            return x * other.x + y * other.y + z * other.z;
        }
*/
        /** Calculate and returns cross product of this x other */
        Vector3 vectorProduct(const Vector3& other) const {
            return Vector3(y * other.z - z * other.y,
                    z * other.x - x * other.z,
                    x * other.y - y * other.x);
        }

        /** Alias '%=' to this x other*/
        void operator%=(const Vector3& other) {
            *this = vectorProduct(other);
        }

        /** Alias '%'*/
        Vector3 operator%(const Vector3& other) const {
            return Vector3(y * other.z - z * other.y,
                    z * other.x - x * other.z,
                    x * other.y - y * other.x);
        }


    };





}


#endif	/* _FOUNDATION_H */

