#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <fstream>
#include "vec3.h"
#include "util.h"
class Image {
    public:
        int width; //横幅
        int height; //縦幅
        Vec3* data;

        Image(int _width, int _height) {
            width = _width;
            height = _height;
            data = new Vec3[width*height];
        };
        ~Image() {
            delete[] data;
        };

        //(i, j)のRGBを返す
        Vec3 getPixel(int i, int j) const {
            return data[width*i + j];
        };
        //(i, j)にRGBを書き込む
        void setPixel(int i, int j, const Vec3& color) {
            data[width*i + j] = color;
        };

        //PPM画像を出力する
        void ppm_output() const {
            std::ofstream file("output.ppm");
            
            file << "P3" << std::endl;
            file << width << " " << height << std::endl;
            file << "255" << std::endl;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    Vec3 color = 255*this->getPixel(j, i);
                    int r = clamp((int)color.x, 0, 255);
                    int g = clamp((int)color.y, 0, 255);
                    int b = clamp((int)color.z, 0, 255);
                    file << r << " " << g << " " << b << std::endl;
                }
            }
            file.close();
        };

        //ガンマ補正
        void gamma_correction() {
            for(int i = 0; i < width; i++) {
                for(int j = 0; j < height; j++) {
                    Vec3 col = this->getPixel(i, j);
                    col.x = std::pow(col.x, 1.0/2.2);
                    col.y = std::pow(col.y, 1.0/2.2);
                    col.z = std::pow(col.z, 1.0/2.2);
                    this->setPixel(i, j, col);
                }
            }
        };
};
#endif