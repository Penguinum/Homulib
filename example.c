#include <stdio.h>
#include <cwrapper.h>

int main() {
    // Just set sample rate
    h_set_sample_rate(44100);
    // Create and init sinewave generator.
    void *gen = h_sinewave();
    // Create and init adsr effect.
    void *adsr = h_adsr();
    // Set parameters.
    h_adsr_set_attack(adsr, 0.2);
    h_adsr_set_decay(adsr, 0.3);
    h_adsr_set_sustain(adsr, 0.7);
    h_adsr_set_release(adsr, 0.5);

    // Start producing sinewave with frequency 150 Hz.
    hg_start(gen, 150);

    // Start ADSR.
    he_start(adsr);

    // Produce sine wave with adsr while adsr is not finished.
    while(! he_finished(adsr)) {
        // we stop sustain after 0.7 seconds of producing values
        if (he_seconds_played(adsr) >= 0.7) {
            h_adsr_stop_sustain(adsr);
        }
        printf("%f\n", he_next_sample(adsr) * hg_next_sample(gen));
    }

    hg_delete(gen);
    he_delete(adsr);
    return 0;
}
