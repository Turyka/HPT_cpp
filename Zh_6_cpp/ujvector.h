#pragma once
#include vector.h

class ujVektor final  public Vector {
public
    using VectorVector;  Örökli a szülő osztály összes konstruktorát

      operátor, amely a vektorok elemeinek darabszáma alapján hasonlít össze
    bool operator(const ujVektor &other) const {
        return elements.size()  other.elements.size();
    }
};