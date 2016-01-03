/*
  ==============================================================================

    KarplusStrongBattery.h
    Created: 02 Jan 2016 13:37pm
    Author:  Penguinum-tea

  ==============================================================================
*/

#ifndef KARPLUS_BATTERY_H
#define KARPLUS_BATTERY_H

#include <vector>
#include <KarplusStrongFilter.h>
#include <Generators.h>


namespace homu {

class KarplusStrongBattery : public Filter {
private:
    std::vector<homu::KarplusStrongFilter> battery;
    size_t battery_size;

public:
    void setTuning(const std::vector<double> &frequencies);
    void start();
    double nextSample(double input);
};

}

#endif // KARPLUS_BATTERY_H

