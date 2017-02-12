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

void Delay::setSizeInSamples(size_t s) {
    buffer.smartResize(s);
    buffer.fill(0);
}

size_t Delay::getSize() {
    return buffer.size();
}

void Delay::start() {
    buffer.fill(0);
}

double Delay::tick(double v) {
    double sample = buffer.getFromOffset(0);
    buffer.apply(v);
    return sample;
}

}

