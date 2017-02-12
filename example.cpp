#include <stdio.h>
#include <Sinewave.h>
#include <ADSR.h>

int main() {
    // Just set sample rate
    homu::SampleRate = 44100;
    // Create and init sinewave generator.
    homu::Sinewave g;
    // Create and init adsr effect.
    homu::ADSR adsr;
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
        double sample = adsr.tick() * g.tick();
        printf("%f\n", sample);
    }
    
    // I don't use any audio API here because I don't want to add dependencies
    // You can read output, for example, using python, and then draw a plot or write this into wavfile.
    return 0;
}
