/*
  ==============================================================================

    Square.cpp
    Created: 03 Jan 2014 18:20
    Author:  Penguinum-tea

  ==============================================================================
*/

#include <Square.h>
#include <cmath>
#include <util/constants.h>
#include <stdio.h>


namespace homu {

void Square::start(double freq) {
    phase       = 0;
    sample_num  = 0;
    phase_delta = TWO_M_PI * freq / (double)SampleRate;
}

double Square::tick() {
    if (phase >= TWO_M_PI) {
        phase -= TWO_M_PI;
    }
    double sample = (phase < M_PI) ? 1 : -1;
    phase += phase_delta;
    return sample;
}

}
