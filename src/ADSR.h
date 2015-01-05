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

/**
 * Envelope effect. Can also be used as generator.
 */
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

    /**
     * @param value is an attack time (in seconds)
     */
    void setAttack(float value);
    /**
     * @param value is a decay time (in seconds)
     */
    void setDecay(float value);
    /**
     * @param value is a sustain (0 to 1 float)
     */
    void setSustain(float value);
    /**
     * @param value is a release time (in seconds)
     */
    void setRelease(float value);
    /**
     * Stop sustain.
     */
    void stopSustain();
    /**
     * Get next sample; effect-style.
     * @param s is an input sample
     */
    float nextSample(float s);
    /**
     * Get next sample; generator-style.
     */
    float nextSample();
    /**
     * Check is ADSR finished.
     */
    bool finished() const;
    /**
     * Get current state.
     * @return number of state (matches enum above)
     */
    int getState();
    /**
     * Set state. I don't know usecase of this method, but it can be useful, maybe.
     * @param state is a state to switch
     */
    void setState(int state);
};

}

#endif
