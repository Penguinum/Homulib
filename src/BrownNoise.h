/*
  ==============================================================================

    BrownNoise.h
    Created: 11 Dec 2014 18.07
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef BROWN_NOISE_H
#define BROWN_NOISE_H


#include "Generators.h"

namespace homu {

/**
 * Generator that produces brownian noise.
 */
class BrownNoise : public Generator {
private:
    double last_value;

public:
    BrownNoise(size_t sr)
        : Generator(sr), last_value(0) {}
    virtual double nextSample();
    /**
     * Start generator.
     * @param freq is useless here for now.
     */
    virtual void start(double freq);
};

}

#endif
