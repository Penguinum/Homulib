/*
  ==============================================================================

    Distortion.cpp
    Created: 11 Jan 2015 21:33 pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include <Distortion.h>

namespace homu {
    void Distortion::setLevel(double v) {
        level = v;
    }

    double Distortion::nextSample(double v) {
        if (v > level) {
            return level;
        }
        if (v < -level) {
            return level;
        }
        return v;
    }
}
