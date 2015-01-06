#include <stdio.h>
#include "src/cwrapper.h"

int main() {
    // Create and init sinewave generator.
    void *gen = SinewaveGenerator_Create(41000);
    // Create and init adsr effect.
    void *adsr = ADSR_Create(41000);
    // Set parameters.
    ADSR_SetAttack(adsr, 0.2);
    ADSR_SetDecay(adsr, 0.3);
    ADSR_SetSustain(adsr, 0.7);
    ADSR_SetRelease(adsr, 0.5);

    // Start producing sinewave with frequency 150 Hz.
    SinewaveGenerator_Start(gen, 150);

    // Start ADSR.
    ADSR_Start(adsr);
    
    // Produce sine wave with adsr while adsr is not finished.
    while(! ADSR_Finished(adsr)) {
        // we stop sustain after 0.7 seconds of producing values
        if (ADSR_SecondsPlayed(adsr) >= 0.7) {
            ADSR_StopSustain(adsr);
        }
        printf("%f\n", ADSR_NextSample(adsr) * SinewaveGenerator_NextSample(gen));
    }

    SinewaveGenerator_Destroy(gen);
    ADSR_Destroy(adsr);
    return 0;
}
