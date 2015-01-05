/*
  ==============================================================================

    WhiteNoiseGenerator.h
    Created: 11 Dec 2014 17.31
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef WHITE_NOISE_GENERATOR_H
#define WHITE_NOISE_GENERATOR_H


#include "Generators.h"

namespace homu {

/**
 * Generator that produces white noise.
 */
class WhiteNoiseGenerator : public Generator {
public:
    WhiteNoiseGenerator(size_t sr)
        : Generator(sr) {}
    virtual float nextSample();
    /**
     * Start generator.
     * @param freq is useless here for now.
     */
    virtual void start(float freq);
};

}

#endif
