/*
  ==============================================================================

    ringbuffer.cpp
    Created: 25 Nov 2014 8:08:00pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include <ringbuffer.h>
#include <cstdlib>

namespace homu {

double RingBuffer::getFromOffset(int i) {
    if ((int)currentPos + i < 0) {
        return at(buf_size + i - currentPos);
    } else if (currentPos + i >= buf_size) {
        return at(currentPos + i - buf_size);
    } else {
        return at(currentPos + i);
    }
}

void RingBuffer::fill(double f) {
    for (size_t i = 0; i < buf_size; i++) {
        (*this)[i] = f;
    }
}

void RingBuffer::apply(double f) {
    (*this)[currentPos] = f;
    if (currentPos == buf_size - 1) {
        currentPos = 0;
    } else {
        currentPos++;
    }
}

void RingBuffer::smartResize(size_t N) {
    resize(N);
    buf_size = N;
    currentPos = 0;
}

}
