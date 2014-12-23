/*
  ==============================================================================

    BrownNoiseGenerator.cpp
    Created: 11 Dec 2014 18.07
    Author:  Penguinum-tea

  ==============================================================================
*/

#include "BrownNoiseGenerator.h"
#include <cmath>
#include <cstdlib>

namespace homu {

void BrownNoiseGenerator::start(float freq) {
    frequency = freq;
    last_value = 0;
}

float BrownNoiseGenerator::nextSample() {
    float white = rand()/float(RAND_MAX) * 2.0 - 1;
    last_value = (last_value + 0.02*white) / 1.02;
    return last_value;
}

}
