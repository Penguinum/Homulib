/*
  ==============================================================================

    AllPass.cpp
    Created: 27 Dec 2015 16:59 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include <AllPass.h>

namespace homu {

void AllPass::start() {
    output = 0;
    delay.setSize(1);
    delay.start();
}

void AllPass::setGain(const double g) {
    gain = g;
}

void AllPass::setDelay(const double d) {
    delay.setSize(d);
}

double AllPass::nextSample(const double input) {
    const double in_mul_gain = input * (-gain);
    const double out_mul_gain = output * gain;
    const double output = in_mul_gain + delay.nextSample(input + out_mul_gain);
    return output;
}

}

