/*
  ==============================================================================

    ADSR.cpp
    Created: 5 Dec 2014 4:16:24pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include "ADSR.h"

namespace homu {

void ADSR::start() {
    state = attackState;
    current_sample = 0;
}

void ADSR::setAttack(float a) { attack = int(a * sample_rate); }

void ADSR::setDecay(float d) { decay = int(d * sample_rate); }

void ADSR::setSustain(float s) { sustain = s; }

void ADSR::setRelease(float r) { release = int(r * sample_rate); }

float ADSR::nextSample() {
    const int cur_state = state;
    switch (cur_state) {
    case attackState:
        if (attack == 0) {
            state++;
        } else {
            last_value = float(current_sample) / float(attack);
            if (current_sample >= attack) {
                state++;
                current_sample = 0;
            }
            break;
        }
    case decayState:
        if (decay == 0) {
            state++;
        } else {
            last_value =
                1 - (1 - sustain) * float(current_sample) / float(decay);
            if (current_sample >= decay) {
                state++;
                current_sample = 0;
            }
            break;
        }
    case sustainState:
        last_value = sustain;
        break;
    case releaseState:
        if (release == 0) {
            last_value = 0;
            state++;
        } else {
            last_value = release_max -
                         release_max * float(current_sample) / float(release);
            if (current_sample >= release) {
                state = finalState;
            }
        }
        break;
    default:
        last_value = 0;
        break;
    }
    current_sample++;
    return last_value;
}

float ADSR::nextSample(float s) {
    return s * nextSample();
}

void ADSR::stopSustain() {
    if (state < releaseState) {
        state = releaseState;
        release_max = last_value;
        current_sample = 0;
    }
}

bool ADSR::finished() const {
    return (state == finalState);
}

int ADSR::getState() {
    return state;
}

void ADSR::setState(int s) {
    state = s;
}

}
