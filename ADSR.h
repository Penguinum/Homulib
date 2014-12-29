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

class ADSR : public Effect {
private:
    size_t attack;
    size_t decay;
    float sustain;
    size_t release;
    int state;
    size_t current_sample;
    float last_value, release_max;

public:
    enum States {
        attackState,
        decayState,
        sustainState,
        releaseState,
        finalState
    };
    ADSR(size_t sr)
        : Effect(sr), attack(1), decay(1), sustain(1), release(1),
          state(attackState), current_sample(0), last_value(0), release_max(0) {}
    void start();
    void setAttack(float value);
    void setDecay(float value);
    void setSustain(float value);
    void setRelease(float value);
    void stopSustain();
    float nextSample(float s);
    float nextSample();
    bool finished() const;
    int getState();
    void setState(int state);
};

}

#endif
