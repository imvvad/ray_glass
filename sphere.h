#ifndef SPHERE_H
#define SPHERE_H
#include "vec3.h"
#include "ray.h"
#include "hit.h"
class Sphere {
    public:
        Vec3 center;
        double radius;
        Vec3 color;
        int material;

        Sphere(const Vec3& center, double radius, const Vec3& color, int material) : center(center), radius(radius), color(color), material(material) {};

        bool intersect(const Ray& ray, Hit& hit) const {
            double a = ray.direction.length2();
            double b = 2*dot(ray.direction, ray.origin - center);
            double c = (ray.origin - center).length2() - radius*radius;
            double D = b*b - 4*a*c;
            if(D < 0) return false;

            double t1 = (-b - std::sqrt(D))/(2*a);
            double t2 = (-b + std::sqrt(D))/(2*a);
            
            double t = t1;
            if(t < 0) {
                t = t2;
                if(t < 0) return false;
            }


            hit.t = t;

            hit.hitPos = ray.origin + t*ray.direction;

            hit.hitNormal = normalize(hit.hitPos - center);

            hit.hitSphere = this;
            return true;
        };
};
#endif