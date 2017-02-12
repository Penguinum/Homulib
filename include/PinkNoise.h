/*
  ==============================================================================

    PinkNoise.h
    Created: 13 Dec 2014 19:17
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef PINK_NOISE_H
#define PINK_NOISE_H


#include "Generators.h"

namespace homu {

/**
 *  that produces pink noise.
 */
class PinkNoise : public Generator {
private:
    double last_value;
    double b0, b1, b2, b3, b4, b5, b6;

public:
  PinkNoise()
      : last_value(0), b0(0), b1(0), b2(0), b3(0), b4(0), b5(0), b6(0) {}
    virtual double tick();
    /**
     * Start generator.
     * @param freq is useless here for now.
     */
    virtual void start(double freq);
};

}

#endif
