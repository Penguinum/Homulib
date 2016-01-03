/*
  ==============================================================================

    KarplusStrongFilter.cpp
    Created: 30 Dec 2015 20:17pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include <KarplusStrongFilter.h>
#include <iostream>

namespace homu {

void KarplusStrongFilter::start() {
    Filter::start();
    H_a.start();
    delay.start();
    filtered_output = 0;
}
void KarplusStrongFilter::setFrequency(const double freq) {
    frequency = freq;
    delay_len = (size_t)(SampleRate / frequency);
    delay.setSizeInSamples(delay_len);
}

double KarplusStrongFilter::nextSample(const double input) {
    const double input_plus_filtered = input + filtered_output;
    const double output = delay.nextSample(input_plus_filtered);
    filtered_output = H_a.nextSample(output);
    return output;
}

}

