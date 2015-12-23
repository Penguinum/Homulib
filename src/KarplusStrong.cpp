/*
  ==============================================================================

    KarplusStrong.cpp
    Created: 5 Dec 2014 2:37:58pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include <KarplusStrong.h>

namespace homu {

void KarplusStrong::start(double freq) {
    Generator::start(freq);
    delay_len = (size_t)(SampleRate / frequency);
    delay.setSizeInSamples(delay_len);
    delay.start();
    H_a.start();
    white_noise.start(1);
    current_sample = 0;
}

double KarplusStrong::nextSample() {
    double input = 0;
    if (sample_num < delay_len) {
        input = white_noise.nextSample();
    }
    const double input_plus_filtered = input + current_sample;
    const double output = delay.nextSample(input_plus_filtered);
    current_sample = H_a.nextSample(output);
    sample_num++;
    return output;
}

}

