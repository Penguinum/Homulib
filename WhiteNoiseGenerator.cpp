/*
  ==============================================================================

    WhiteNoiseGenerator.cpp
    Created: 11 Dec 2014 17.31
    Author:  Penguinum-tea

  ==============================================================================
*/

#include "WhiteNoiseGenerator.h"
#include <cmath>
#include <cstdlib>

namespace homu {

void WhiteNoiseGenerator::start(float freq) {
    frequency = freq;
}

float WhiteNoiseGenerator::nextSample() {
    return rand()/float(RAND_MAX);
}

}
