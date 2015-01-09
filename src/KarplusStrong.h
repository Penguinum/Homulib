/*
  ==============================================================================

    KarplusStrong.h
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

/**
 * Generator that use Karplus-Strong algorithm to create
 * sound similar to guitar string.
 */
class KarplusStrong : public Generator {
private:
    RingBuffer buf;

public:
    KarplusStrong(size_t sr) : Generator(sr) {}
    virtual double nextSample();
    virtual void start(double freq);
};

}

#endif
