/*
  ==============================================================================

    Distortion.h
    Created: 11 Jan 2015 21:33 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef DISTORTION_H
#define DISTORTION_H

#include "Generators.h"

namespace homu {

class Distortion : public Effect {
private:
    double level;

public:
    Distortion(size_t sr) : Effect(sr), level(0.5) {}
    void   setLevel  (double v);
    double nextSample(double v);
};

}

#endif
