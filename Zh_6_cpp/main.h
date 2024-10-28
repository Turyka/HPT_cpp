#include <iostream>
#include "vector.h"
#include "ujVektor.h"

int main() {
    ujVektor uv1({1, 2, 3});
    ujVektor uv2({4, 5, 6, 7});

    if (uv1 < uv2)
        std::cout << "uv1 kisebb elemszámú, mint uv2" << std::endl;
    else
        std::cout << "uv2 kisebb vagy egyenlő elemszámú, mint uv1" << std::endl;

    return 0;
}