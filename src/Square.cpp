/*
  ==============================================================================

    Square.cpp
    Created: 03 Jan 2014 18:20
    Author:  Penguinum-tea

  ==============================================================================
*/

#define _USE_MATH_DEFINES
#include "Square.h"
#include <cmath>
#include <stdio.h>

#define TWO_M_PI M_PI * 2

namespace homu {

void Square::start(double freq) {
    phase       = 0;
    sample_num  = 0;
    phase_delta = TWO_M_PI * freq / (double)sample_rate;
}

double Square::nextSample() {
    if (phase >= TWO_M_PI) {
        phase -= TWO_M_PI;
    }
    double sample = (phase < M_PI) ? 1 : -1;
    phase += phase_delta;
    return sample;
}

}
