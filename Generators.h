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

class Basegen {
protected:
    size_t sample_rate;
    size_t sample_num;

public:
    Basegen(size_t sr) : sample_rate(sr), sample_num(0) {}
    virtual ~Basegen() {}
    //void setFrequency(float freq);
};

class Generator : public Basegen {
protected:
    float frequency;

public:
    Generator(size_t sr) : Basegen(sr), frequency(200){}
    virtual float nextSample();
    virtual void start(float freq);
};

class Effect : public Basegen {
public:
    Effect(size_t sr) : Basegen(sr) {}
    virtual float nextSample(float current_sample);
    virtual void start();
};

}

#endif
