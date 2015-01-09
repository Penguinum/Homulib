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

/**
 * Class that implements ring buffer.
 */
class RingBuffer : public std::vector<double> {
private:
    size_t currentPos, buf_size;

public:
    RingBuffer() : currentPos(0), buf_size(1) {}
    /**
     * Get sample from offset. If current sample has number j
     * this method will return sample with numver j + i
     * @param i is an offset.
     */
    double getFromOffset(int i);
    /**
     * Fill all samples in buffer with double number f.
     * @param f is a number to fill ring buffer.
     */
    void fill(double f);
    /**
     * Pushes sample f into current sample and rotates buffer.
     * @param f is a number that will be written into current position.
     */
    void apply(double f);
    /**
     * Resize buffer and reinit some variables.
     * @param N is a new buffer size.
     */
    void smartResize(size_t N);
};

}

#endif
