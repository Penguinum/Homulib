/*
  ==============================================================================

    Delay.cpp
    Created: 9 Jan 2015 12:00 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include <Delay.h>

namespace homu {
    void Delay::setSize(double v) {
        buffer.smartResize((size_t)(v * SampleRate));
        buffer.fill(0);
    }

    void Delay::setDecay(double v) {
        decay = v;
    }

    double Delay::nextSample(double v) {
        double sample = 0.5 * (v + buffer.getFromOffset(0) * decay);
        buffer.apply(v);
        return sample;
    }
}
