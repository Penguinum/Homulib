/*
  ==============================================================================

    AllPass.h
    Created: 27 Dec 2015 16:59 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef ALLPASS_H
#define ALLPASS_H

#include <Generators.h>
#include <Delay.h>

/**
 * All-pass filter. Not sure does it work or does not...
 */
namespace homu {

class AllPass : public Filter {
private:
    double gain, output;
    Delay delay;

public:
    AllPass();
    void start();
    void setGain(const double g);
    void setDelay(const double d);
    double tick(const double input);
};

}

#endif // ALLPASS_H

