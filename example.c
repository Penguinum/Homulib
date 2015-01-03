#include <stdio.h>
#include "src/cwrapper.h"

int main() {
    // Create and init sinewave generator.
    void *gen = SinewaveGenerator_create(41000);
    // Create and init adsr effect.
    void *adsr = ADSR_create(41000);
    // Set parameters.
    ADSR_setAttack(adsr, 0.2);
    ADSR_setDecay(adsr, 0.3);
    ADSR_setSustain(adsr, 0.7);
    ADSR_setRelease(adsr, 0.5);

    // Start producing sinewave with frequency 150 Hz.
    SinewaveGenerator_start(gen, 150);

    // Start ADSR.
    ADSR_start(adsr);
    
    // Produce sine wave with adsr while adsr is not finished.
    while(! ADSR_finished(adsr)) {
        // we stop sustain after 0.7 seconds of producing values
        if (ADSR_secondsPlayed(adsr) >= 0.7) {
            ADSR_stopSustain(adsr);
        }
        printf("%f\n", ADSR_nextSample(adsr) * SinewaveGenerator_nextSample(gen));
    }

    SinewaveGenerator_destroy(gen);
    ADSR_destroy(adsr);
    return 0;
}
