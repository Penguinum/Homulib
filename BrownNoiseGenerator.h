/*
  ==============================================================================

    BrownNoiseGenerator.h
    Created: 11 Dec 2014 18.07
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef BROWN_NOISE_GENERATOR_H
#define BROWN_NOISE_GENERATOR_H


#include "Generators.h"

namespace homu {

class BrownNoiseGenerator : public Generator {
private:
    float last_value;

public:
    BrownNoiseGenerator(size_t sr)
        : Generator(sr), last_value(0) {}
    virtual float nextSample();
    virtual void start(float freq);
};

}

#endif
