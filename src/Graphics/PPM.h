#ifndef RAYTRACER_PPM_H
#define RAYTRACER_PPM_H

#include "Canvas.h"
#include <vector>
#include <string>

class PPM{
private:
    const int max_size = 70;
public:
    std::vector<std::string> lines;
    int size;

    PPM(Canvas c){
        this->size = c.width;
        lines.emplace_back("P3");
        lines.push_back(std::to_string(c.width) + " " + std::to_string(c.height));
        lines.emplace_back("255");
        for (int i = 0; i < c.length; i+=size){
            std::string line;
            for(int j = 0; j < size; j++){
                if (line.size() + c.canvasPixels[i+j].getPPM().size() + 1 > 70){
                    lines.push_back(line);
                    line = "";
                }
                if (line.size() > 0)
                    line += " ";
                line += c.canvasPixels[i+j].getPPM() ;
            }
            lines.push_back(line);
        }
    }

    [[nodiscard]] std::string getPPM() const {
        std::string ppmLines;
        for (const std::string& entry : lines){
            ppmLines += entry + "\n";
        }
        return ppmLines;
    }

};

#endif //RAYTRACER_PPM_H
