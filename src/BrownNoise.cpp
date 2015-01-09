/*
  ==============================================================================

    BrownNoise.cpp
    Created: 11 Dec 2014 18.07
    Author:  Penguinum-tea

  ==============================================================================
*/

#include "BrownNoise.h"
#include <cmath>
#include <cstdlib>

namespace homu {

void BrownNoise::start(double freq) {
    frequency = freq;
    last_value = 0;
}

double BrownNoise::nextSample() {
    double white = rand() / (double)RAND_MAX * 2.0 - 1;
    last_value = (last_value + 0.02 * white) / 1.02;
    return last_value;
}

}
