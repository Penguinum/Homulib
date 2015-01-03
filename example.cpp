#include <stdio.h>
#include "src/SinewaveGenerator.h"
#include "src/ADSR.h"

int main() {
    const size_t sample_rate = 41000;
    // Create and init sinewave generator.
    homu::SinewaveGenerator g(sample_rate);
    // Create and init adsr effect.
    homu::ADSR adsr(sample_rate);
    // Set parameters.
    adsr.setAttack(0.2);
    adsr.setDecay(0.3);
    adsr.setSustain(0.7);
    adsr.setRelease(0.5);
    
    // Start producing sinewave with frequency 150 Hz.
    g.start(150);

    // Start ADSR.
    adsr.start();

    // Produce sine wave with adsr while adsr is not finished.
    while (! adsr.finished()) {
        // we stop sustain after 0.7 seconds of producing values
        if (adsr.secondsPlayed() >= 0.7) {
            adsr.stopSustain();
        }
        // we can use another form of it:
        // float sample = adsr.nextSample * g.nextSample();
        float sample = adsr.nextSample(g.nextSample());
        printf("%f\n", sample);
    }
    
    // I don't use any audio API here because I don't want to add dependencies
    // You can read output, for example, using python, and then draw a plot or write this into wavfile.
    return 0;
}
