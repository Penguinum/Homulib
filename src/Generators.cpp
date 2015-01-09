/*
  ==============================================================================

    Generators.cpp
    Created: 08 Dec 2014 00:29 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include "Generators.h"

namespace homu {

void Generator::start(double freq) {
    frequency = freq;
    sample_num = 0;
}

void Effect::start() {
    sample_num = 0;
}

double Generator::nextSample() {
    return 0;
}

double Effect::nextSample(double current_sample) {
    return current_sample;
}

void Envelope::start() {
    sample_num = 0;
}

double Envelope::nextSample() {
    return 1;
}

double Envelope::secondsPlayed() {
    return sample_num / (double)sample_rate;
}

}
