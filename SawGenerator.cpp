/*
  ==============================================================================

    SawGenerator.cpp
    Created: 08 Dec 2014 18.41
    Author:  Penguinum-tea

  ==============================================================================
*/

#include "SawGenerator.h"
#include <cmath>
#include <stdio.h>

namespace homu {

void SawGenerator::start(float freq) {
    frequency = freq;
    phase = M_PI * 0.5;
    sample_num = 0;
    phase_delta = 2.0 * M_PI * frequency /float(sample_rate);
    coef_up = 2.0 / M_PI;
    coef_down = - 2.0 / M_PI;
}

float SawGenerator::nextSample() {
    if (phase >= 2 * M_PI) {
        phase -= 2 * M_PI;
    }
    sample_num++;
    phase += phase_delta;
    if (phase < M_PI) {
        return 1 + coef_down * phase;
    } else {
        return - 1 + coef_up * (phase - M_PI);
    }
}

}
