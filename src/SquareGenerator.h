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

/**
 * Generator that produces a triangle wave.
 */
class SquareGenerator : public Generator {
private:
    float phase;
    float phase_delta;

public:
    SquareGenerator(size_t sr) : Generator(sr) {}
    virtual void start(float freq);
    virtual float nextSample();
};

}

#endif
