/*
  ==============================================================================

    SinusGenerator.cpp
    Created: 08 Dec 2014 00:29 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

// This generator is surely useless, but I think it must be here.

#include "SinusGenerator.h"
#include <cmath>
#include <stdio.h>

namespace homu {

float SinusGenerator::nextSample() {
    return std::sin((2*M_PI*frequency*(sample_num++))/(float(sample_rate)));
}

}
