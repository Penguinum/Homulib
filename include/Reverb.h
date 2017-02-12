/*
  ==============================================================================

    Reverb.h
    Created: 24 Dec 2015 20:25 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef REVERB_H
#define REVERB_H

#include <Generators.h>
#include <Delay.h>


/**
 * The very basic reverberation filter.
 */
namespace homu {
    
class Reverb : public Filter {
private:
    Delay delay;
    double previous_sample, gain;

public:
    Reverb();
    void start();
    void setGain(const double g);
    double tick(double input);
};

}

#endif // REVERB_H

