#include <stdio.h>
#include "src/cwrapper.h"

int main() {
    void *gen = SinusGenerator_create(41000);
    void *adsr = ADSR_create(41000);

    ADSR_start(adsr);
    ADSR_setAttack(adsr, 0.2);
    ADSR_setDecay(adsr, 0.3);
    ADSR_setSustain(adsr, 0.7);
    ADSR_setRelease(adsr, 0.5);

    SinusGenerator_start(gen, 150);
    
    while(! ADSR_finished(adsr)) {
        if (ADSR_secondsPlayed(adsr) >= 0.7) {
            ADSR_stopSustain(adsr);
        }
        float sample = ADSR_nextSample(adsr) * SinusGenerator_nextSample(gen);
        printf("%f\n", sample);
    }

    SinusGenerator_destroy(gen);
    ADSR_destroy(adsr);
    return 0;
}
