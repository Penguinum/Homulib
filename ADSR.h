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
    ADSR(size_t sr)
        : Basegen(sr), attack(1), decay(1), sustain(1), release(1),
          state(attackState), current_sample(0), last_value(0), release_max(0) {}
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
