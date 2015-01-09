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
    float decay;

public:
    Delay(size_t sr) : Effect(sr), decay(0.5) {}
    void  setSize   (float v);
    void  setDecay  (float v);
    float nextSample(float v);
};

}

#endif
