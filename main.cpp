// MAIN del Trabajo Practico de Implementacion
#include <iostream>
#include "gtest/gtest.h"

using namespace std;
int main(int argc, char **argv) {
    std::cout << "Implementando TPI!!" << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
