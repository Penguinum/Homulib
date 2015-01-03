/*
  ==============================================================================

    SquareGenerator.cpp
    Created: 03 Jan 2014 18:20
    Author:  Penguinum-tea

  ==============================================================================
*/

#define _USE_MATH_DEFINES
#include "SquareGenerator.h"
#include <cmath>
#include <stdio.h>

#define TWO_M_PI M_PI * 2

namespace homu {

void SquareGenerator::start(float freq) {
    phase       = 0;
    sample_num  = 0;
    phase_delta = 2.0 * M_PI * freq / (float)sample_rate;
}

float SquareGenerator::nextSample() {
    if (phase >= TWO_M_PI) {
        phase -= TWO_M_PI;
    }
    float sample = (phase < M_PI) ? 1 : -1;
    phase += phase_delta;
    return sample;
}

}
