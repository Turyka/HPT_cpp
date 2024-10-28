#pragma once
#include <vector>
#include <initializer_list>

class Vector {
protected:
    std::vector<int> elements;

public:
    // Konstruktor, amely inicializáló listát fogad el
    Vector(std::initializer_list<int> list) : elements(list) {}
};
