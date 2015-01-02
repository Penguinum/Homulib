#include <stdio.h>
#include "src/cwrapper.h"

int main() {
    void *gen = SinusGenerator_create(41000);
    SinusGenerator_start(gen, 100);
    for (int i = 0; i < 1000; i++) {
        printf("%f\n", (double)SinusGenerator_nextSample(gen));
    }
    SinusGenerator_destroy(gen);
    return 0;
}
