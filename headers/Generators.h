/*
  ==============================================================================

    Generators.h
    Created: 08 Dec 2014 00:29 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdlib.h>
#include "SampleRate.h"

namespace homu {

/**
 * Base class for all things producing samples.
 */
class Basegen {
protected:
    size_t sample_num;

public:
    Basegen() : sample_num(0) {}
    virtual ~Basegen() {};
};

/**
 * Base class for generators.
 * Generators don't have input samples.
 */
class Generator : public Basegen {
protected:
    double frequency;

public:
    Generator() : frequency(200) {}
    /**
     * Get next sample.
     */
    virtual double nextSample();
    /**
     * Start generator.
     * @param freq is a desired frequency.
     */
    virtual void start(double freq);
};

/**
 * Base class for effects.
 * Effects have input samples.
 */
class Effect : public Basegen {
public:
    Effect() {}
    /**
     * Get next sample
     */
    virtual double nextSample(double current_sample);
    /**
     * Start generator.
     */
    virtual void start();
};

/**
 * Base class for things like ADSR envelope.
 * Envelopes don't have input samples.
 */
class Envelope : public Basegen {
public:
    Envelope() {}
    /**
     * Get next sample.
     */
    virtual double nextSample();
    /**
     * Start generator.
     */
    virtual void start();
    double secondsPlayed();
};

}

#endif
