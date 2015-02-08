/*
  ==============================================================================

    Delay.h
    Created: 9 Jan 2015 12:00 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef DELAY_H
#define DELAY_H

#include "Generators.h"
#include "ringbuffer.h"

namespace homu {

class Delay : public Effect {
private:
    RingBuffer buffer;
    double decay;

public:
    Delay() : decay(0.5) {}
    void  setSize   (double v);
    void  setDecay  (double v);
    double nextSample(double v);
};

}

#endif
