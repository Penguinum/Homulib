/*
  ==============================================================================

    KarplusStrongBattery.cpp
    Created: 02 Jan 2016 13:37pm
    Author:  Penguinum-tea

  ==============================================================================
*/

// WARNING: weird stuff, needs fixing to be useful.

#include <KarplusStrongBattery.h>
#include <list>
#include <cmath>
#include <iostream>

namespace homu {

KSADSRFilter::KSADSRFilter() {
    adsr.setADSR(0, 0, 1, 0);
}

inline void KSADSRFilter::setADSR(double a, double d, double s, double r) {
    adsr.setADSR(a, d, s, r);
}

void KSADSRFilter::start() {
    KarplusStrongFilter::start();
    adsr.start();
}

inline void KSADSRFilter::stop() {
    adsr.stopSustain();
}

inline bool KSADSRFilter::finished() {
    return adsr.finished();
}

double KSADSRFilter::tick(const double sample) {
    if (adsr.finished()) {
        return 0;
    }
    return KarplusStrongFilter::tick(sample) * adsr.tick() * 0.2;
}

// --------------------------------------------------------

void KarplusStrongBattery::setTuning(const std::vector<double> &frequencies) {
    battery_size = frequencies.size();
    for (size_t i = 0; i < battery_size; i++) {
        addString(frequencies[i]);
    }

    for (std::map<double, KSADSRFilter>::iterator iter = battery.begin();
      iter != battery.end(); ++iter) {
          bool found = false;
          for (size_t i = 0; i < frequencies.size(); i++) {
              if (iter->first == frequencies[i]) {
                  found = true;
                  break;
              }
          }
          if (!found) {
              removeString(iter->first);
          }
          if (iter->second.finished()) {
              battery.erase(iter->first);
          }
    }
}

void KarplusStrongBattery::addString(const double freq) {
    if (battery.find(freq) == battery.end()) {
        battery[freq] = KSADSRFilter();
    }
}

void KarplusStrongBattery::removeString(const double freq) {
    battery[freq].stop();
}

void KarplusStrongBattery::start() {
    magic_divide_number = 15.0;
    for (std::map<double, KSADSRFilter>::iterator iter = battery.begin();
            iter != battery.end(); ++iter) {
        iter->second.setFrequency(iter->first);
        iter->second.start();
    }
}

double KarplusStrongBattery::tick(double input) {
    double output = 0;
    for (std::map<double, KSADSRFilter>::iterator iter = battery.begin();
            iter != battery.end(); ++iter) {
        output += iter->second.tick(input);
    }
    return std::tanh(output/magic_divide_number);
}

}

