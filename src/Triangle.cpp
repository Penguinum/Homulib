/*
  ==============================================================================

    Triangle.cpp
    Created: 08 Dec 2014 18.41
    Author:  Penguinum-tea

  ==============================================================================
*/
#define _USE_MATH_DEFINES
#include "Triangle.h"
#include <cmath>
#include <iostream>

namespace homu {

void Triangle::start(double freq) {
    frequency   = freq;
    sample_num  = 0;
    phase_delta = 2.0 * M_PI * frequency / (double)SampleRate;
    w_up        = M_PI * width;
    w_down      = M_PI * (1 - width);
    phase       = 2 * M_PI - w_up;
}

double Triangle::nextSample() {
    if (phase >= 2 * M_PI) {
        phase -= 2 * M_PI;
    }

    double sample = 0;
    if (w_down == 0) {
        sample = -1 + 1.0/M_PI * phase;
    } else {
        if (phase < 2 * w_down) {
            sample =  1 - phase / w_down;
        } else {
            sample = - 1 + (phase - 2 * w_down) / w_up;
        }
    }
    phase += phase_delta;
    return sample;
}

void Triangle::setWidth(double w) {
    if (w < 0 || w > 1) {
        std::cerr << 
            "Error: Triangle::width should be in range [0, 1], "
            "but obtained value is " << w << std::endl;
        return;
    }
    width  = w;
    w_up   = M_PI * width;
    w_down = M_PI * (1 - width);
}

}
