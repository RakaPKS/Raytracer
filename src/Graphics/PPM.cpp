
#include "PPM.h"

    PPM::PPM(Canvas c){
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
                if (!line.empty())
                    line += " ";
                line += c.canvasPixels[i+j].getPPM() ;
            }
            lines.push_back(line);
        }
    }

    [[nodiscard]] std::string PPM::getPPM() const {
        std::string ppmLines;
        for (const std::string& entry : lines){
            ppmLines += entry + "\n";
        }
        return ppmLines;
    }
