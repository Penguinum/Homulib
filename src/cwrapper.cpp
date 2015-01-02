#include "cwrapper.h"
#include "SinewaveGenerator.h"
#include "ADSR.h"

// Sinewave section

void *SinewaveGenerator_create(size_t sample_rate) {
    homu::SinewaveGenerator *gen = new homu::SinewaveGenerator(sample_rate);
    return static_cast<void*>(gen);
}

void SinewaveGenerator_destroy(void *v) {
    homu::SinewaveGenerator *gen = static_cast<homu::SinewaveGenerator*>(v);
    delete gen;
}

void SinewaveGenerator_start(void *v, float freq) {
    homu::SinewaveGenerator *gen = static_cast<homu::SinewaveGenerator*>(v);
    gen->start(freq);
}

float SinewaveGenerator_nextSample(void *v) {
    homu::SinewaveGenerator *gen = static_cast<homu::SinewaveGenerator*>(v);
    return gen->nextSample();
}


// ADSR section

void *ADSR_create(size_t sample_rate) {
    homu::ADSR *gen = new homu::ADSR(sample_rate);
    return static_cast<void*>(gen);
}

void ADSR_destroy(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    delete gen;
}

void ADSR_start(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->start();
}

float ADSR_nextSample(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    return gen->nextSample();
}

void ADSR_setAttack(void *v, float a) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->setAttack(a);
}

void ADSR_setDecay(void *v, float d) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->setDecay(d);
}

void ADSR_setSustain(void *v, float s) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->setSustain(s);
}

void ADSR_setRelease(void *v, float r) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->setRelease(r);
}

int ADSR_finished(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    return gen->finished() ? 1 : 0;
}

float ADSR_secondsPlayed(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    return gen->secondsPlayed();
}

void ADSR_stopSustain(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->stopSustain();
}

