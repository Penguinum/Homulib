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
 * ADSR envelope. Can also be used as generator.
 */
class ADSR : public Envelope {
private:
    size_t attack;
    size_t decay;
    double sustain;
    size_t release;
    int state;
    size_t current_sample;
    double last_value, release_max;

public:
    enum States {
        attackState,
        decayState,
        sustainState,
        releaseState,
        finalState
    };
    ADSR() : attack(1), decay(1), sustain(1), release(1),
          state(attackState), current_sample(0), last_value(0), release_max(0) {}
    void start() override;
    void stop() override;

    /**
     * @param value is an attack time (in seconds)
     */
    void setAttack(double value);
    /**
     * @param value is a decay time (in seconds)
     */
    void setDecay(double value);
    /**
     * @param value is a sustain (0 to 1 double)
     */
    void setSustain(double value);
    /**
     * @param value is a release time (in seconds)
     */
    void setRelease(double value);
    /**
     * @param attack is an attack time (in seconds)
     * @param decay is a decay time (in seconds)
     * @param sustain is a sustain (0 to 1)
     * @param release is a release time (in seconds)
     */
    void setADSR(double attack, double decay, double sustain, double release);
    /**
     * Stop sustain.
     */
    void stopSustain();
    /**
     * Get next sample; generator-style.
     */
    double nextSample() override;
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
