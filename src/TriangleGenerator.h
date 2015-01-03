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
    /*
    Sort of explanation.
    1        /\
    |      /    \
    |    /       \
    |  /           \
    0/________._____\Pi______._______2*Pi
    | w_up     w_down \w_down w_up   /
    |                  \           /
    |                    \       /
    |                     \    /
    -1                      \/
    */
    float phase;
    float phase_delta;
    float w_up, w_down; // width1 + width2 = Pi
    float width; // width = width1 / Pi

public:
    TriangleGenerator(size_t sr)
        : Generator(sr), phase(0), phase_delta(0),
        w_up(0), w_down(0), width(0.5) {}
    virtual float nextSample();
    virtual void start(float freq);
    void setWidth(float width);
};

}

#endif
