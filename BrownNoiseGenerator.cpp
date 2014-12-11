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
    last_value = last_value + rand()/float(RAND_MAX);
    return last_value;
}

}
