/*
  ==============================================================================

    KS_ext_filters.cpp
    Created: 23 Dec 2015 20:48 pm
    Author:  Penguinum-tea

  ==============================================================================
*/


#include <KS_ext_filters.h>
#include <math.h>

namespace homu {

void KS_H_a::start() {
    previous_sample = 0;
}

// H_a(z) = (1 + z^-1) / 2

double KS_H_a::nextSample(double s) {
    const double result = (previous_sample + s) / 2.0;
    previous_sample = s;
    return result;
}

}

