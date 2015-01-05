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

/**
 * Generator that produces brownian noise.
 */
class BrownNoiseGenerator : public Generator {
private:
    float last_value;

public:
    BrownNoiseGenerator(size_t sr)
        : Generator(sr), last_value(0) {}
    virtual float nextSample();
    /**
     * Start generator.
     * @param freq is useless here for now.
     */
    virtual void start(float freq);
};

}

#endif
