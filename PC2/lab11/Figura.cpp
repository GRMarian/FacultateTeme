#include "Figura.h"

bool Figura::operator<(Figura* a)
{
    if (this->perimetru() < a->perimetru())
    {
        return true;
    }
    return false;
}
