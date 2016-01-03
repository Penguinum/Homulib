/*
  ==============================================================================

    KarplusStrongFilter.h
    Created: 30 Dec 2015 20:17pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef KARPLUS_FILTER_H
#define KARPLUS_FILTER_H

#include "Generators.h"
#include <stdlib.h>
#include <Delay.h>
#include <KS_ext_filters.h>

namespace homu {

/**
 * Filter that works the same as Karplus-Strong generator does.
 * The only difference is that it does not fill delay line with noise,
 * you can manually send anything as input to it.
 */
class KarplusStrongFilter : public Filter {
private:
    size_t delay_len;
    double frequency, filtered_output;
    Delay delay;
    KS_H_a H_a;

public:
    double nextSample(const double input);
    void setFrequency(const double freq);
    void start();

};

}

#endif // KARPLUS_FILTER_H

