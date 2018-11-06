#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
#include <cmath>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "vec3.h"

class Texture{
    public:
     int width;
     int height;
     float* texture_data;

     Texture(const std::string filename){
         int n;
         texture_data = stbi_loadf(filename.c_str(), &width, &height, &n, 0);
          };

    ~Texture(){
        stbi_image_free(texture_data);
    };

    Vec3 getNyan(const Vec3& dir) const{
        double phi = std::atan2(dir.z, dir.x);
        if(phi < 0) phi += 2 * M_PI;
        float theta = std::acos(dir.y);

        double u = phi / (2 * M_PI);
        double v = theta / M_PI;

        int w = (int)(u * width);
        int h = (int)(v * height);
        int adr = 3 * w + 3 * width * h;
        return Vec3(texture_data[adr], texture_data[adr + 1], texture_data[adr + 2]);

    };

};
#endif