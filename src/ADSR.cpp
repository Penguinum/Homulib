/*
  ==============================================================================

    ADSR.cpp
    Created: 5 Dec 2014 4:16:24pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include <ADSR.h>
//#include <SampleRate.h>

namespace homu {

void ADSR::start() {
    state = attackState;
    current_sample = 0;
    sample_num = 0;
}

void ADSR::setAttack(double a) { attack = size_t(a * SampleRate); }

void ADSR::setDecay(double d) { decay = size_t(d * SampleRate); }

void ADSR::setSustain(double s) { sustain = s; }

void ADSR::setRelease(double r) { release = size_t(r * SampleRate); }

double ADSR::nextSample() {
    const int cur_state = state;
    switch (cur_state) {
    case attackState:
        if (attack == 0) {
            state++;
        } else {
            last_value = double(current_sample) / double(attack);
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
                1 - (1 - sustain) * double(current_sample) / double(decay);
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
                         release_max * current_sample / (double)release;
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
    sample_num++;
    return last_value;
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
