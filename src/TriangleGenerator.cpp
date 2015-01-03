/*
  ==============================================================================

    TriangleGenerator.cpp
    Created: 08 Dec 2014 18.41
    Author:  Penguinum-tea

  ==============================================================================
*/
#define _USE_MATH_DEFINES
#include "TriangleGenerator.h"
#include <cmath>
#include <stdio.h>

namespace homu {

void TriangleGenerator::start(float freq) {
    frequency   = freq;
    phase       = 2 * M_PI - w_up;
    sample_num  = 0;
    phase_delta = 2.0 * M_PI * frequency / (float)sample_rate;
    w_up        = M_PI * width;
    w_down      = M_PI * (1 - width);
}

float TriangleGenerator::nextSample() {
    if (phase >= 2 * M_PI) {
        phase -= 2 * M_PI;
    }
    phase += phase_delta;
    if (phase < 2 * w_down) {
        return 1 - phase / w_down;
    } else {
        return - 1 + (phase - M_PI) / w_up;
    }
}

void TriangleGenerator::setWidth(float w) {
    width = w;
    w_up        = M_PI * width;
    w_down      = M_PI * (1 - width);
}

}
