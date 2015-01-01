/*
  ==============================================================================

    SinusGenerator.h
    Created: 08 Dec 2014 00:29 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

// This generator is surely useless, but I think it must be here.

#ifndef SINUS_GENERATOR_H
#define SINUS_GENERATOR_H


#include "Generators.h"

namespace homu {

class SinusGenerator : public Generator {
public:
    SinusGenerator(size_t sr) : Generator(sr) {}
    virtual float nextSample();
};

}

#endif
