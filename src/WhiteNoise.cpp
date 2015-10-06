/*
  ==============================================================================

    WhiteNoise.cpp
    Created: 11 Dec 2014 17.31
    Author:  Penguinum-tea

  ==============================================================================
*/

#include <WhiteNoise.h>
#include <cmath>
#include <cstdlib>

namespace homu {

void WhiteNoise::start(double freq) {
    frequency = freq;
}

double WhiteNoise::nextSample() {
    return rand() / (double)RAND_MAX * 2.0 - 1;
}

}
