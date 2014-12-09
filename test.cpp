#include <stdio.h>
#include "SinusGenerator.h"
#include "KarplusStrongGenerator.h"
#include "SawGenerator.h"

int main() {
    //homu::KarplusStrongGenerator g(44100);
    //homu::SinusGenerator g(44100);
    homu::SawGenerator g(44100);
    g.start(20);
    for (size_t i = 0; i <= 44100; i++) {
        printf("%f\n", g.nextSample());
    }
    return 0;
}
