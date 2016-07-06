/*
  ==============================================================================

    Generators.cpp
    Created: 08 Dec 2014 00:29 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include <Generators.h>
#include <iostream>

namespace homu {
void Generator::start(double freq) {
    frequency = freq;
    sample_num = 0;
}

void Filter::start() {
    sample_num = 0;
}

double Generator::nextSample() {
    return 0;
}

double Filter::nextSample(double current_sample) {
    return current_sample;
}

void Envelope::start() {
    finished_ = false;
    sample_num = 0;
}

void Envelope::stop() {
    finished_ = true;
}

double Envelope::nextSample() {
    return finished_ ? 0 : 1;
}

double Envelope::secondsPlayed() {
    return sample_num / (double)SampleRate;
}

bool Envelope::finished() const {
    return finished_;
}

}
