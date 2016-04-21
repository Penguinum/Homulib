/*
  ==============================================================================

    KarplusStrongBattery.h
    Created: 02 Jan 2016 13:37pm
    Author:  Penguinum-tea

  ==============================================================================
*/

// WARNING: weird stuff, needs fixing to be useful.

#ifndef KARPLUS_BATTERY_H
#define KARPLUS_BATTERY_H

#include <vector>
#include <map>
#include <KarplusStrongFilter.h>
#include <Generators.h>
#include <ADSR.h>


namespace homu {

/**
 * Extended version of a Karplus-Strong filter with built-in envelope.
 */
class KSADSRFilter : public KarplusStrongFilter {
private:
    ADSR adsr;

public:
    KSADSRFilter();
    double nextSample(const double input);
    void start();
    void stop();
    bool finished();
    void setADSR(double a, double d, double s, double r);
};


/**
 * Battery of Karplus-Strong filters.
 */
class KarplusStrongBattery : public Filter {
private:
    double magic_divide_number;
    std::map<double, homu::KSADSRFilter> battery;
    size_t battery_size;

public:
    void setTuning(const std::vector<double> &frequencies);
    void addString(const double freq);
    void removeString(const double freq);
    void start();
    double nextSample(double input);
};

}

#endif // KARPLUS_BATTERY_H

