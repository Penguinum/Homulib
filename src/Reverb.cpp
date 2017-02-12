/*
  ==============================================================================

    Reverb.cpp
    Created: 24 Dec 2015 20:25 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include <Reverb.h>

namespace homu {

Reverb::Reverb() {
    previous_sample = 0;
    delay.setSize(0.03);
}

void Reverb::start() {
    delay.start();
}

void Reverb::setGain(const double g) {
    gain = g;
}

double Reverb::tick(const double input) {
    const double out_mul_gain = previous_sample * gain;
    const double output = out_mul_gain + delay.tick(input + out_mul_gain);
    previous_sample = output;
    return output;
}

}

