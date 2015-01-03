/*
  ==============================================================================

    SquareGenerator.h
    Created: 03 Jan 2014 18:20
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef SINUS_GENERATOR_H
#define SINUS_GENERATOR_H


#include "Generators.h"

namespace homu {

class SquareGenerator : public Generator {
private:
    float phase;

public:
    SquareGenerator(size_t sr) : Generator(sr) {}
    virtual float nextSample();
};

}

#endif
