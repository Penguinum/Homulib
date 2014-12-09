/*
  ==============================================================================

    ADSR.h
    Created: 5 Dec 2014 4:16:24pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef ADSR_H
#define ADSR_H

#include <stdlib.h>
#include "Generators.h"

namespace homu {

class ADSR : public Basegen {
private:
    size_t attack;
    size_t decay;
    float sustain;
    size_t release;
    enum States {
        attackState,
        decayState,
        sustainState,
        releaseState,
        finalState
    };
    int state;
    size_t current_sample;
    float last_value, release_max;

public:
    void start();
    void setAttack(float value);
    void setDecay(float value);
    void setSustain(float value);
    void setRelease(float value);
    void stopSustain();
    float nextSample();
    bool finished();
};

}

#endif
