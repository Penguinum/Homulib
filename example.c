#include <stdio.h>
#include "src/cwrapper.h"

int main() {
    void *gen = SinewaveGenerator_create(41000);
    void *adsr = ADSR_create(41000);

    ADSR_start(adsr);
    ADSR_setAttack(adsr, 0.2);
    ADSR_setDecay(adsr, 0.3);
    ADSR_setSustain(adsr, 0.7);
    ADSR_setRelease(adsr, 0.5);

    SinewaveGenerator_start(gen, 150);
    
    while(! ADSR_finished(adsr)) {
        if (ADSR_secondsPlayed(adsr) >= 0.7) {
            ADSR_stopSustain(adsr);
        }
        float sample = ADSR_nextSample(adsr) * SinewaveGenerator_nextSample(gen);
        printf("%f\n", sample);
    }

    SinewaveGenerator_destroy(gen);
    ADSR_destroy(adsr);
    return 0;
}
