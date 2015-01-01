/*
  ==============================================================================

    TriangleGenerator.h
    Created: 08 Dec 2014 18:41
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef SAW_GENERATOR_H
#define SAW_GENERATOR_H


#include "Generators.h"

namespace homu {

class TriangleGenerator : public Generator {
private:
    float phase;
    float phase_delta;
    float coef_up, coef_down;

public:
    TriangleGenerator(size_t sr)
        : Generator(sr), phase(0), phase_delta(0), coef_up(0), coef_down(0) {}
    virtual float nextSample();
    virtual void start(float freq);
};

}

#endif
