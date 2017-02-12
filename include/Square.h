/*
  ==============================================================================

    Square.h
    Created: 03 Jan 2014 18:20
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef SQUARE_H
#define SQUARE_H


#include "Generators.h"

namespace homu {

/**
 * Generator that produces a triangle wave.
 */
class Square : public Generator {
private:
    double phase;
    double phase_delta;

public:
    Square() : phase(0), phase_delta(0) {}
    virtual void start(double freq);
    virtual double tick();
};

}

#endif
