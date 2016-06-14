/*
  ==============================================================================

    Delay.h
    Created: 9 Jan 2015 12:00 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef DELAY_H
#define DELAY_H

#include "Generators.h"
#include "util/ringbuffer.h"

namespace homu {

class Delay : public Filter {
protected:
    RingBuffer buffer;

public:
    Delay() {}
    void start();
    void setSize(double v);
    void setSizeInSamples(size_t s);
    size_t getSize();
    double nextSample(double v);
};

}

#endif // DELAY_H

