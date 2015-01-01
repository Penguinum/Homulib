/*
  ==============================================================================

    KarplusStrongGenerator.h
    Created: 5 Dec 2014 2:37:58pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef KARPLUS_H
#define KARPLUS_H

#include "ringbuffer.h"
#include "Generators.h"
#include <stdlib.h>

namespace homu {

class KarplusStrongGenerator : public Generator {
private:
    RingBuffer buf;

public:
    KarplusStrongGenerator(size_t sr) : Generator(sr) {}
    virtual void start(float freq);
    virtual float nextSample();
};

}

#endif
