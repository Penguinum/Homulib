/*
  ==============================================================================

    Sinewave.h
    Created: 08 Dec 2014 00:29 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef SINEWAVE_H
#define SINEWAVE_H


#include "Generators.h"

namespace homu {

/**
 * Generator that produces a sinewave.
 * This generator is surely useless, but I think it must be here.
 */
class Sinewave : public Generator {
public:
    Sinewave() {}
    virtual double nextSample();
};

}

#endif
