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
    buf.smartResize((size_t)(SampleRate / frequency));
}

double KarplusStrong::nextSample() {
    double current_sample;
    if (sample_num < buf.size()) {
        current_sample = rand() / (double)RAND_MAX * 2 - 1;
    } else {
        current_sample = 0.5 * (buf.getFromOffset(0) + buf.getFromOffset(1));
    }
    sample_num++;
    buf.apply(current_sample);
    return current_sample;
}

}
