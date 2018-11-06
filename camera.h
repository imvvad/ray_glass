#ifndef CAMERA_H
#define CAMERA_H
#include "vec3.h"
#include "ray.h"
class Camera {
    public:
        Vec3 camPos;
        Vec3 camForward;
        Vec3 camRight;
        Vec3 camUp;

        Camera(const Vec3& camPos, const Vec3& camForward) : camPos(camPos), camForward(camForward) {
            camRight = -1 * normalize(cross(camForward, Vec3(0, 1, 0)));
            camUp = normalize(cross(camRight, camForward));
        };

        Ray getRay(double u, double v) const {
            v = -v;
            Vec3 pinhole = camPos + camForward;
            Vec3 sensorPos = camPos + u*camRight + v*camUp;
            return Ray(camPos, normalize(pinhole - sensorPos)); //Ray(origin, direction);
        };
};
#endif