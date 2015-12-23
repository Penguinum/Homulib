/*
  ==============================================================================

    KarplusStrong.h
    Created: 5 Dec 2014 2:37:58pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef KARPLUS_H
#define KARPLUS_H

#include "Generators.h"
#include "WhiteNoise.h"
#include <stdlib.h>
#include <Delay.h>
#include <KS_ext_filters.h>

namespace homu {

/**
 * Generator that use Karplus-Strong algorithm to create
 * sound similar to guitar string.
 */
class KarplusStrong : public Generator {
private:
    double current_sample;
    size_t delay_len;
    Delay delay;
    WhiteNoise white_noise;
    KS_H_a H_a;

public:
    virtual double nextSample();
    virtual void start(double freq);
};

}

#endif // KARPLUS_H

