/*
  ==============================================================================

    Sinewave.cpp
    Created: 08 Dec 2014 00:29 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#define _USE_MATH_DEFINES
#include "Sinewave.h"
#include <cmath>
#include <stdio.h>

namespace homu {

double Sinewave::nextSample() {
    return std::sin((2*M_PI*frequency*(sample_num++))/((double)SampleRate));
}

}
