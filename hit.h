#ifndef HIT_H
#define HIT_H
#include "vec3.h"

class Sphere;

class Hit {
    public:
        double t;
        Vec3 hitPos;
        Vec3 hitNormal;
        
        const Sphere* hitSphere;

        Hit() {
            t = 1000000;
            hitSphere = nullptr;
        }
        Hit(double t, const Vec3& hitPos, const Vec3& hitNormal) : t(t), hitPos(hitPos), hitNormal(hitNormal) {};
};
#endif