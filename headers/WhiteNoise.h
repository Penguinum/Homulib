/*
  ==============================================================================

    WhiteNoise.h
    Created: 11 Dec 2014 17.31
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef WHITE_NOISE_H
#define WHITE_NOISE_H


#include "Generators.h"

namespace homu {

/**
 * Generator that produces white noise.
 */
class WhiteNoise : public Generator {
public:
    WhiteNoise() {}
    virtual double nextSample();
    /**
     * Start generator.
     * @param freq is useless here for now.
     */
    virtual void start(double freq);
};

}

#endif
