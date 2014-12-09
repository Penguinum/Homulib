/*
  ==============================================================================

    Generators.cpp
    Created: 08 Dec 2014 00:29 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include "Generators.h"

namespace homu {

void Generator::start(float freq) {
    frequency = freq;
    sample_num = 0;
}

void Effect::start() {
    sample_num = 0;
}

float Generator::nextSample() {
    return 0;
}

float Effect::nextSample(float current_sample) {
    return current_sample;
}

}
