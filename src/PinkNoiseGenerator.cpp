/*
  ==============================================================================

    PinkNoiseGenerator.cpp
    Created: 13 Dec 2014 19:17
    Author:  Penguinum-tea

  ==============================================================================
*/

#include "PinkNoiseGenerator.h"
#include <cmath>
#include <cstdlib>

namespace homu {

void PinkNoiseGenerator::start(float freq) {
    frequency = freq;
    last_value = 0;
}

float PinkNoiseGenerator::nextSample() {
    float white = rand()/(float)RAND_MAX * 2.0 - 1;
    b0 = 0.99886 * b0 + white * 0.0555179;
    b1 = 0.99332 * b1 + white * 0.0750759;
    b2 = 0.96900 * b2 + white * 0.1538520;
    b3 = 0.86650 * b3 + white * 0.3104856;
    b4 = 0.55000 * b4 + white * 0.5329522;
    b5 = -0.7616 * b5 - white * 0.0168980;
    last_value = b0 + b1 + b2 + b3 + b4 + b5 + b6 + white * 0.5362;
    last_value *= 0.1;
    b6 = white * 0.115926; 
    return last_value;
}

}
