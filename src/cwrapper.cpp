#define BUILD_THIS_LIB
#include "cwrapper.h"
#include "SinewaveGenerator.h"
#include "TriangleGenerator.h"
#include "KarplusStrongGenerator.h"
#include "WhiteNoiseGenerator.h"
#include "PinkNoiseGenerator.h"
#include "BrownNoiseGenerator.h"
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

// Triangle section

void *TriangleGenerator_create(size_t sample_rate) {
    homu::TriangleGenerator *gen = new homu::TriangleGenerator(sample_rate);
    return static_cast<void*>(gen);
}

void TriangleGenerator_destroy(void *v) {
    homu::TriangleGenerator *gen = static_cast<homu::TriangleGenerator*>(v);
    delete gen;
}

void TriangleGenerator_start(void *v, float freq) {
    homu::TriangleGenerator *gen = static_cast<homu::TriangleGenerator*>(v);
    gen->start(freq);
}

float TriangleGenerator_nextSample(void *v) {
    homu::TriangleGenerator *gen = static_cast<homu::TriangleGenerator*>(v);
    return gen->nextSample();
}

void TriangleGenerator_setWidth(void *v, float w) {
    homu::TriangleGenerator *gen = static_cast<homu::TriangleGenerator*>(v);
    gen->setWidth(w);
}

//Karplus-Strong section

void *KarplusStrongGenerator_create(size_t sample_rate) {
    homu::KarplusStrongGenerator *gen = new homu::KarplusStrongGenerator(sample_rate);
    return static_cast<void*>(gen);
}

void KarplusStrongGenerator_destroy(void *v) {
    homu::KarplusStrongGenerator *gen = static_cast<homu::KarplusStrongGenerator*>(v);
    delete gen;
}

void KarplusStrongGenerator_start(void *v, float freq) {
    homu::KarplusStrongGenerator *gen = static_cast<homu::KarplusStrongGenerator*>(v);
    gen->start(freq);
}

float KarplusStrongGenerator_nextSample(void *v) {
    homu::KarplusStrongGenerator *gen = static_cast<homu::KarplusStrongGenerator*>(v);
    return gen->nextSample();
}

//White noise section

void *WhiteNoiseGenerator_create(size_t sample_rate) {
    homu::WhiteNoiseGenerator *gen = new homu::WhiteNoiseGenerator(sample_rate);
    return static_cast<void*>(gen);
}

void WhiteNoiseGenerator_destroy(void *v) {
    homu::WhiteNoiseGenerator *gen = static_cast<homu::WhiteNoiseGenerator*>(v);
    delete gen;
}

void WhiteNoiseGenerator_start(void *v, float freq) {
    homu::WhiteNoiseGenerator *gen = static_cast<homu::WhiteNoiseGenerator*>(v);
    gen->start(freq);
}

float WhiteNoiseGenerator_nextSample(void *v) {
    homu::WhiteNoiseGenerator *gen = static_cast<homu::WhiteNoiseGenerator*>(v);
    return gen->nextSample();
}

//Pink noise section

void *PinkNoiseGenerator_create(size_t sample_rate) {
    homu::PinkNoiseGenerator *gen = new homu::PinkNoiseGenerator(sample_rate);
    return static_cast<void*>(gen);
}

void PinkNoiseGenerator_destroy(void *v) {
    homu::PinkNoiseGenerator *gen = static_cast<homu::PinkNoiseGenerator*>(v);
    delete gen;
}

void PinkNoiseGenerator_start(void *v, float freq) {
    homu::PinkNoiseGenerator *gen = static_cast<homu::PinkNoiseGenerator*>(v);
    gen->start(freq);
}

float PinkNoiseGenerator_nextSample(void *v) {
    homu::PinkNoiseGenerator *gen = static_cast<homu::PinkNoiseGenerator*>(v);
    return gen->nextSample();
}

//Brown noise section

void *BrownNoiseGenerator_create(size_t sample_rate) {
    homu::BrownNoiseGenerator *gen = new homu::BrownNoiseGenerator(sample_rate);
    return static_cast<void*>(gen);
}

void BrownNoiseGenerator_destroy(void *v) {
    homu::BrownNoiseGenerator *gen = static_cast<homu::BrownNoiseGenerator*>(v);
    delete gen;
}

void BrownNoiseGenerator_start(void *v, float freq) {
    homu::BrownNoiseGenerator *gen = static_cast<homu::BrownNoiseGenerator*>(v);
    gen->start(freq);
}

float BrownNoiseGenerator_nextSample(void *v) {
    homu::BrownNoiseGenerator *gen = static_cast<homu::BrownNoiseGenerator*>(v);
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

