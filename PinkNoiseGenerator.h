/*
  ==============================================================================

    PinkNoiseGenerator.h
    Created: 13 Dec 2014 19:17
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef PINK_NOISE_GENERATOR_H
#define PINK_NOISE_GENERATOR_H


#include "Generators.h"

namespace homu {

class PinkNoiseGenerator : public Generator {
private:
    float last_value;
    float b0, b1, b2, b3, b4, b5, b6;

public:
    PinkNoiseGenerator(size_t sr)
        : Generator(sr), last_value(0),
        b0(0), b1(0), b2(0), b3(0), b4(0), b5(0), b6(0) {}
    virtual float nextSample();
    virtual void start(float freq);
};

}

#endif
