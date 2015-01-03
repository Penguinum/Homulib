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

float SquareGenerator::nextSample() {
    if (phase >= TWO_M_PI) {
        phase -= TWO_M_PI;
    }
    return (phase < M_PI) ? 1 : -1;
}

}
