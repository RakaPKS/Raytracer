//
// Created by Raka Schipperheijn on 07/11/2021.
//

#include <iostream>
#include "RTuple.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    RTuple x = {12.0,12.0,12.0,1};
    std::cout << x.isVector() << x.isPoint();

    return 0;
}
