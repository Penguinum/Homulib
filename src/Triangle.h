/*
  ==============================================================================

    Triangle.h
    Created: 08 Dec 2014 18:41
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "Generators.h"

namespace homu {

/**
 * Generator that produces a triangle wave.
   @verbatim
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
   @endverbatim
 */
class Triangle : public Generator {
private:
    double phase;
    double phase_delta;
    double w_up, w_down; // width1 + width2 = Pi
    double width; // width = width1 / Pi

public:
    Triangle(size_t sr)
        : Generator(sr), phase(0), phase_delta(0),
        w_up(0), w_down(0), width(0.5) {}
    virtual double nextSample();
    virtual void start(double freq);
    void setWidth(double width);
};

}

#endif
