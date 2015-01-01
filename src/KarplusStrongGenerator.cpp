/*
  ==============================================================================

    KarplusStrongGenerator.cpp
    Created: 5 Dec 2014 2:37:58pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include "KarplusStrongGenerator.h"

namespace homu {

void KarplusStrongGenerator::start(float freq) {
    Generator::start(freq);
    buf.smartResize(int(sample_rate / frequency));
}

float KarplusStrongGenerator::nextSample() {
    float current_sample;
    if (sample_num < buf.size()) {
        current_sample = rand() / float(RAND_MAX) * 2 - 1;
    } else {
        current_sample = 0.5 * (buf.getFromOffset(0) + buf.getFromOffset(1));
    }
    sample_num++;
    buf.apply(current_sample);
    return current_sample;
}

}
