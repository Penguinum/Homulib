#define BUILD_THIS_LIB
#include "cwrapper.h"
#include "SinewaveGenerator.h"
#include "TriangleGenerator.h"
#include "KarplusStrongGenerator.h"
#include "WhiteNoiseGenerator.h"
#include "PinkNoiseGenerator.h"
#include "BrownNoiseGenerator.h"
#include "ADSR.h"
#include "Delay.h"

// Sinewave section

void *SinewaveGenerator_Create(size_t sample_rate) {
    homu::SinewaveGenerator *gen = new homu::SinewaveGenerator(sample_rate);
    return static_cast<void*>(gen);
}

void SinewaveGenerator_Destroy(void *v) {
    homu::SinewaveGenerator *gen = static_cast<homu::SinewaveGenerator*>(v);
    delete gen;
}

void SinewaveGenerator_Start(void *v, float freq) {
    homu::SinewaveGenerator *gen = static_cast<homu::SinewaveGenerator*>(v);
    gen->start(freq);
}

float SinewaveGenerator_NextSample(void *v) {
    homu::SinewaveGenerator *gen = static_cast<homu::SinewaveGenerator*>(v);
    return gen->nextSample();
}

// Triangle section

void *TriangleGenerator_Create(size_t sample_rate) {
    homu::TriangleGenerator *gen = new homu::TriangleGenerator(sample_rate);
    return static_cast<void*>(gen);
}

void TriangleGenerator_Destroy(void *v) {
    homu::TriangleGenerator *gen = static_cast<homu::TriangleGenerator*>(v);
    delete gen;
}

void TriangleGenerator_Start(void *v, float freq) {
    homu::TriangleGenerator *gen = static_cast<homu::TriangleGenerator*>(v);
    gen->start(freq);
}

float TriangleGenerator_NextSample(void *v) {
    homu::TriangleGenerator *gen = static_cast<homu::TriangleGenerator*>(v);
    return gen->nextSample();
}

void TriangleGenerator_SetWidth(void *v, float w) {
    homu::TriangleGenerator *gen = static_cast<homu::TriangleGenerator*>(v);
    gen->setWidth(w);
}

//Karplus-Strong section

void *KarplusStrongGenerator_Create(size_t sample_rate) {
    homu::KarplusStrongGenerator *gen = new homu::KarplusStrongGenerator(sample_rate);
    return static_cast<void*>(gen);
}

void KarplusStrongGenerator_Destroy(void *v) {
    homu::KarplusStrongGenerator *gen = static_cast<homu::KarplusStrongGenerator*>(v);
    delete gen;
}

void KarplusStrongGenerator_Start(void *v, float freq) {
    homu::KarplusStrongGenerator *gen = static_cast<homu::KarplusStrongGenerator*>(v);
    gen->start(freq);
}

float KarplusStrongGenerator_NextSample(void *v) {
    homu::KarplusStrongGenerator *gen = static_cast<homu::KarplusStrongGenerator*>(v);
    return gen->nextSample();
}

//White noise section

void *WhiteNoiseGenerator_Create(size_t sample_rate) {
    homu::WhiteNoiseGenerator *gen = new homu::WhiteNoiseGenerator(sample_rate);
    return static_cast<void*>(gen);
}

void WhiteNoiseGenerator_Destroy(void *v) {
    homu::WhiteNoiseGenerator *gen = static_cast<homu::WhiteNoiseGenerator*>(v);
    delete gen;
}

void WhiteNoiseGenerator_Start(void *v, float freq) {
    homu::WhiteNoiseGenerator *gen = static_cast<homu::WhiteNoiseGenerator*>(v);
    gen->start(freq);
}

float WhiteNoiseGenerator_NextSample(void *v) {
    homu::WhiteNoiseGenerator *gen = static_cast<homu::WhiteNoiseGenerator*>(v);
    return gen->nextSample();
}

//Pink noise section

void *PinkNoiseGenerator_Create(size_t sample_rate) {
    homu::PinkNoiseGenerator *gen = new homu::PinkNoiseGenerator(sample_rate);
    return static_cast<void*>(gen);
}

void PinkNoiseGenerator_Destroy(void *v) {
    homu::PinkNoiseGenerator *gen = static_cast<homu::PinkNoiseGenerator*>(v);
    delete gen;
}

void PinkNoiseGenerator_Start(void *v, float freq) {
    homu::PinkNoiseGenerator *gen = static_cast<homu::PinkNoiseGenerator*>(v);
    gen->start(freq);
}

float PinkNoiseGenerator_NextSample(void *v) {
    homu::PinkNoiseGenerator *gen = static_cast<homu::PinkNoiseGenerator*>(v);
    return gen->nextSample();
}

//Brown noise section

void *BrownNoiseGenerator_Create(size_t sample_rate) {
    homu::BrownNoiseGenerator *gen = new homu::BrownNoiseGenerator(sample_rate);
    return static_cast<void*>(gen);
}

void BrownNoiseGenerator_Destroy(void *v) {
    homu::BrownNoiseGenerator *gen = static_cast<homu::BrownNoiseGenerator*>(v);
    delete gen;
}

void BrownNoiseGenerator_Start(void *v, float freq) {
    homu::BrownNoiseGenerator *gen = static_cast<homu::BrownNoiseGenerator*>(v);
    gen->start(freq);
}

float BrownNoiseGenerator_NextSample(void *v) {
    homu::BrownNoiseGenerator *gen = static_cast<homu::BrownNoiseGenerator*>(v);
    return gen->nextSample();
}

// ADSR section

void *ADSR_Create(size_t sample_rate) {
    homu::ADSR *gen = new homu::ADSR(sample_rate);
    return static_cast<void*>(gen);
}

void ADSR_Destroy(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    delete gen;
}

void ADSR_Start(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->start();
}

float ADSR_NextSample(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    return gen->nextSample();
}

void ADSR_SetAttack(void *v, float a) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->setAttack(a);
}

void ADSR_SetDecay(void *v, float d) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->setDecay(d);
}

void ADSR_SetSustain(void *v, float s) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->setSustain(s);
}

void ADSR_SetRelease(void *v, float r) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->setRelease(r);
}

int ADSR_Finished(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    return gen->finished() ? 1 : 0;
}

float ADSR_SecondsPlayed(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    return gen->secondsPlayed();
}

void ADSR_StopSustain(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->stopSustain();
}


// Reverb section


void *Delay_Create (size_t sample_rate) {
    homu::Delay *gen = new homu::Delay(sample_rate);
    return static_cast<void*>(gen);
}

void  Delay_Destroy (void *v) {
    homu::Delay *gen = static_cast<homu::Delay*>(v);
    delete gen;
}

void  Delay_Start (void *v) {
    homu::Delay *gen = static_cast<homu::Delay*>(v);
    gen->start();
}

float  Delay_NextSample (void *v, float value) {
    homu::Delay *gen = static_cast<homu::Delay*>(v);
    return gen->nextSample(value);
}

void Delay_SetSize (void *v, float value) {
    homu::Delay *gen = static_cast<homu::Delay*>(v);
    gen->setSize(value);
}

void Delay_SetDecay (void *v, float value) {
    homu::Delay *gen = static_cast<homu::Delay*>(v);
    gen->setDecay(value);
}
