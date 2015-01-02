#include "cwrapper.h"
#include "SinusGenerator.h"

void *SinusGenerator_create(size_t sample_rate) {
    homu::SinusGenerator *gen = new homu::SinusGenerator(sample_rate);
    return static_cast<void*>(gen);
}

void SinusGenerator_destroy(void *v) {
    homu::SinusGenerator *gen = static_cast<homu::SinusGenerator*>(v);
    delete gen;
}

void SinusGenerator_start(void *v, float freq) {
    homu::SinusGenerator *gen = static_cast<homu::SinusGenerator*>(v);
    gen->start(freq);
}

float SinusGenerator_nextSample(void *v) {
    homu::SinusGenerator *gen = static_cast<homu::SinusGenerator*>(v);
    return gen->nextSample();
}
