/*
  ==============================================================================

    KS_ext_filters.h
    Created: 23 Dec 2015 20:48 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

// Filters for use in Karplus-Strong algorithm

#ifndef KS_EXT_FILTERS_H
#define KS_EXT_FILTERS_H

#include <Generators.h>
#include <Delay.h>

namespace homu {

// H_a(z) = (1 + z^-1) / 2

class KS_H_a : public Filter {
private:
    double previous_sample;

public:
    void start();
    double nextSample(double s);
};

}

#endif // KS_EXT_FILTERS

