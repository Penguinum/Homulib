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
    filtered_output = 0;
}

double KarplusStrong::tick() {
    double input = 0;
    if (sample_num < delay_len) {
        input = white_noise.tick();
    }
    const double input_plus_filtered = input + filtered_output;
    const double output = delay.tick(input_plus_filtered);
    filtered_output = H_a.tick(output);
    sample_num++;
    return output;
}

}

