/*
  ==============================================================================

    KarplusStrongBattery.cpp
    Created: 02 Jan 2016 13:37pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#include <KarplusStrongBattery.h>


namespace homu {

void KarplusStrongBattery::setTuning(const std::vector<double> &frequencies) {
    battery_size = frequencies.size();
    battery.resize(battery_size);
    for (size_t i = 0; i < battery_size; i++) {
        battery[i].setFrequency(frequencies[i]);
    }
}

void KarplusStrongBattery::start() {
    for (size_t i = 0; i < battery_size; i++) {
        battery[i].start();
    }
}

double KarplusStrongBattery::nextSample(double input) {
    double output = 0;
    for (size_t i = 0; i < battery_size; i++) {
        output += battery[i].nextSample(input);
    }
    output /= (double)battery_size;
    return output;
}

}

