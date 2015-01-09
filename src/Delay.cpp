/*
  ==============================================================================

    Delay.cpp
    Created: 9 Jan 2015 12:00 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include "Delay.h"

namespace homu {
    void Delay::setSize(float v) {
        buffer.smartResize(v * sample_rate);
        buffer.fill(0);
    }

    void Delay::setDecay(float v) {
        decay = v;
    }

    float Delay::nextSample(float v) {
        float sample = 0.5 * (v + buffer.getFromOffset(0) * decay);
        buffer.apply(v);
        return sample;
    }
}
