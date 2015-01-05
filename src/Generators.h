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

namespace homu {

/**
 * Base class for all things producing samples.
 * Accepts sample rate in constructor.
 */
class Basegen {
protected:
    size_t sample_rate;
    size_t sample_num;

public:
    Basegen(size_t sr) : sample_rate(sr), sample_num(0) {}
    virtual ~Basegen() {}
    float secondsPlayed();
};

/**
 * Base class for generators.
 * Generators don't have input samples.
 */
class Generator : public Basegen {
protected:
    float frequency;

public:
    Generator(size_t sr) : Basegen(sr), frequency(200) {}
    /**
     * Get next sample.
     */
    virtual float nextSample();
    /**
     * Start generator.
     * @param freq is a desired frequency.
     */
    virtual void start(float freq);
};

/**
 * Base class for effects.
 * Effects have input samples.
 */
class Effect : public Basegen {
public:
    Effect(size_t sr) : Basegen(sr) {}
    /**
     * Get next sample
     */
    virtual float nextSample(float current_sample);
    /**
     * Start generator.
     */
    virtual void start();
};

}

#endif
