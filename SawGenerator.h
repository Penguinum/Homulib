/*
  ==============================================================================

    SawGenerator.h
    Created: 08 Dec 2014 18:41
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef SAW_GENERATOR_H
#define SAW_GENERATOR_H


#include "Generators.h"

namespace homu {

class SawGenerator : public Generator {
private:
    float phase;
    float phase_delta;
    float coef_up, coef_down;

public:
    SawGenerator(size_t sr) : Generator(sr) {}
    virtual float nextSample();
    virtual void start(float freq);
};

}

#endif
