#define BUILD_THIS_LIB
#include "cwrapper.h"
#include "Sinewave.h"
#include "Triangle.h"
#include "KarplusStrong.h"
#include "WhiteNoise.h"
#include "PinkNoise.h"
#include "BrownNoise.h"
#include "ADSR.h"
#include "Delay.h"
#include "Distortion.h"

// Sinewave section

void *Sinewave_Create(size_t sample_rate) {
    homu::Sinewave *gen = new homu::Sinewave(sample_rate);
    return static_cast<void*>(gen);
}

void Sinewave_Destroy(void *v) {
    homu::Sinewave *gen = static_cast<homu::Sinewave*>(v);
    delete gen;
}

void Sinewave_Start(void *v, double freq) {
    homu::Sinewave *gen = static_cast<homu::Sinewave*>(v);
    gen->start(freq);
}

double Sinewave_NextSample(void *v) {
    homu::Sinewave *gen = static_cast<homu::Sinewave*>(v);
    return gen->nextSample();
}

// Triangle section

void *Triangle_Create(size_t sample_rate) {
    homu::Triangle *gen = new homu::Triangle(sample_rate);
    return static_cast<void*>(gen);
}

void Triangle_Destroy(void *v) {
    homu::Triangle *gen = static_cast<homu::Triangle*>(v);
    delete gen;
}

void Triangle_Start(void *v, double freq) {
    homu::Triangle *gen = static_cast<homu::Triangle*>(v);
    gen->start(freq);
}

double Triangle_NextSample(void *v) {
    homu::Triangle *gen = static_cast<homu::Triangle*>(v);
    return gen->nextSample();
}

void Triangle_SetWidth(void *v, double w) {
    homu::Triangle *gen = static_cast<homu::Triangle*>(v);
    gen->setWidth(w);
}

//Karplus-Strong section

void *KarplusStrong_Create(size_t sample_rate) {
    homu::KarplusStrong *gen = new homu::KarplusStrong(sample_rate);
    return static_cast<void*>(gen);
}

void KarplusStrong_Destroy(void *v) {
    homu::KarplusStrong *gen = static_cast<homu::KarplusStrong*>(v);
    delete gen;
}

void KarplusStrong_Start(void *v, double freq) {
    homu::KarplusStrong *gen = static_cast<homu::KarplusStrong*>(v);
    gen->start(freq);
}

double KarplusStrong_NextSample(void *v) {
    homu::KarplusStrong *gen = static_cast<homu::KarplusStrong*>(v);
    return gen->nextSample();
}

//White noise section

void *WhiteNoise_Create(size_t sample_rate) {
    homu::WhiteNoise *gen = new homu::WhiteNoise(sample_rate);
    return static_cast<void*>(gen);
}

void WhiteNoise_Destroy(void *v) {
    homu::WhiteNoise *gen = static_cast<homu::WhiteNoise*>(v);
    delete gen;
}

void WhiteNoise_Start(void *v, double freq) {
    homu::WhiteNoise *gen = static_cast<homu::WhiteNoise*>(v);
    gen->start(freq);
}

double WhiteNoise_NextSample(void *v) {
    homu::WhiteNoise *gen = static_cast<homu::WhiteNoise*>(v);
    return gen->nextSample();
}

//Pink noise section

void *PinkNoise_Create(size_t sample_rate) {
    homu::PinkNoise *gen = new homu::PinkNoise(sample_rate);
    return static_cast<void*>(gen);
}

void PinkNoise_Destroy(void *v) {
    homu::PinkNoise *gen = static_cast<homu::PinkNoise*>(v);
    delete gen;
}

void PinkNoise_Start(void *v, double freq) {
    homu::PinkNoise *gen = static_cast<homu::PinkNoise*>(v);
    gen->start(freq);
}

double PinkNoise_NextSample(void *v) {
    homu::PinkNoise *gen = static_cast<homu::PinkNoise*>(v);
    return gen->nextSample();
}

//Brown noise section

void *BrownNoise_Create(size_t sample_rate) {
    homu::BrownNoise *gen = new homu::BrownNoise(sample_rate);
    return static_cast<void*>(gen);
}

void BrownNoise_Destroy(void *v) {
    homu::BrownNoise *gen = static_cast<homu::BrownNoise*>(v);
    delete gen;
}

void BrownNoise_Start(void *v, double freq) {
    homu::BrownNoise *gen = static_cast<homu::BrownNoise*>(v);
    gen->start(freq);
}

double BrownNoise_NextSample(void *v) {
    homu::BrownNoise *gen = static_cast<homu::BrownNoise*>(v);
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

double ADSR_NextSample(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    return gen->nextSample();
}

void ADSR_SetAttack(void *v, double a) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->setAttack(a);
}

void ADSR_SetDecay(void *v, double d) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->setDecay(d);
}

void ADSR_SetSustain(void *v, double s) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->setSustain(s);
}

void ADSR_SetRelease(void *v, double r) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->setRelease(r);
}

int ADSR_Finished(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    return gen->finished() ? 1 : 0;
}

double ADSR_SecondsPlayed(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    return gen->secondsPlayed();
}

void ADSR_StopSustain(void *v) {
    homu::ADSR *gen = static_cast<homu::ADSR*>(v);
    gen->stopSustain();
}


// Delay section

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

double  Delay_NextSample (void *v, double value) {
    homu::Delay *gen = static_cast<homu::Delay*>(v);
    return gen->nextSample(value);
}

void Delay_SetSize (void *v, double value) {
    homu::Delay *gen = static_cast<homu::Delay*>(v);
    gen->setSize(value);
}

void Delay_SetDecay (void *v, double value) {
    homu::Delay *gen = static_cast<homu::Delay*>(v);
    gen->setDecay(value);
}


// Distortion section

void *Distortion_Create (size_t sample_rate) {
    homu::Distortion *gen = new homu::Distortion(sample_rate);
    return static_cast<void*>(gen);
}

void  Distortion_Destroy (void *v) {
    homu::Distortion *gen = static_cast<homu::Distortion*>(v);
    delete gen;
}

void  Distortion_Start (void *v) {
    homu::Distortion *gen = static_cast<homu::Distortion*>(v);
    gen->start();
}

double  Distortion_NextSample (void *v, double value) {
    homu::Distortion *gen = static_cast<homu::Distortion*>(v);
    return gen->nextSample(value);
}

void Distortion_SetLevel (void *v, double value) {
    homu::Distortion *gen = static_cast<homu::Distortion*>(v);
    gen->setLevel(value);
}
