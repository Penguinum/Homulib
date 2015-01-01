/*
  ==============================================================================

    ringbuffer.h
    Created: 25 Nov 2014 8:08:00pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <vector>
#include <cstdlib>

namespace homu {

class RingBuffer : public std::vector<float> {
private:
    size_t currentPos, buf_size;

public:
    RingBuffer() : currentPos(0), buf_size(1) {}
    float getFromOffset(int i);
    void fill(float f);
    void apply(float f);
    void smartResize(size_t N);
};

}

#endif
