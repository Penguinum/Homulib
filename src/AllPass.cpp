/*
  ==============================================================================

    AllPass.cpp
    Created: 27 Dec 2015 16:59 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include <AllPass.h>

namespace homu {

AllPass::AllPass() {
    delay.setSize(1);
}

void AllPass::start() {
    output = 0;
    delay.start();
}

void AllPass::setGain(const double g) {
    gain = g;
}

void AllPass::setDelay(const double d) {
    delay.setSize(d);
}

double AllPass::tick(const double input) {
    const double in_mul_gain = input * (-gain);
    const double out_mul_gain = output * gain;
    const double output = in_mul_gain + delay.tick(input + out_mul_gain);
    return output;
}

}

