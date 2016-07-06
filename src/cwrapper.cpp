#define BUILD_THIS_LIB
#include <cwrapper.h>
#include <Sinewave.h>
#include <Triangle.h>
#include <KarplusStrong.h>
#include <WhiteNoise.h>
#include <PinkNoise.h>
#include <BrownNoise.h>
#include <ADSR.h>
#include <Delay.h>
#include <Distortion.h>

// Just set sample rate
void h_set_sample_rate(size_t sr) {
    homu::SampleRate = sr;
}

// Generators
void hg_delete(void *ptr) {
    auto *gen = static_cast<homu::Generator*>(ptr);
    delete gen;
}

void hg_start(void *ptr, double freq) {
    auto *gen = static_cast<homu::Generator*>(ptr);
    gen->start(freq);
}

double hg_next_sample(void *ptr) {
    auto *gen = static_cast<homu::Generator*>(ptr);
    return gen->nextSample();
}

// Create sinewave generator
void *h_sinewave() {
    auto gen = new homu::Sinewave();
    return static_cast<void*>(gen);
}

// Create triangle wave generator
void *h_triangle() {
    auto gen = new homu::Triangle();
    return static_cast<void*>(gen);
}

void h_triangle_set_width(void *v, double w) {
    auto gen = static_cast<homu::Triangle*>(v);
    gen->setWidth(w);
}

//Karplus-Strong generator
void *h_karplus_strong() {
    auto gen = new homu::KarplusStrong();
    return static_cast<void*>(gen);
}

// White noise generator
void *h_white_noise() {
    auto gen = new homu::WhiteNoise();
    return static_cast<void*>(gen);
}

// Pink noise generator
void *h_pink_noise() {
    auto gen = new homu::PinkNoise();
    return static_cast<void*>(gen);
}

// Brownian noise generator
void *h_brown_noise() {
    auto gen = new homu::BrownNoise();
    return static_cast<void*>(gen);
}

// Envelopes
void he_delete(void *v) {
    auto env = static_cast<homu::Envelope*>(v);
    delete env;
}

void he_start(void *v) {
    auto env = static_cast<homu::Envelope*>(v);
    env->start();
}

double he_next_sample(void *v) {
    auto env = static_cast<homu::Envelope*>(v);
    return env->nextSample();
}

int he_finished(void *v) {
    auto env = static_cast<homu::Envelope*>(v);
    return env->finished() ? 1 : 0;
}

double he_seconds_played(void *v) {
    auto env = static_cast<homu::Envelope*>(v);
    return env->secondsPlayed();
}

// ADSR envelope
void *h_adsr() {
    auto env = new homu::ADSR();
    return static_cast<void*>(env);
}

void h_adsr_set_attack(void *v, double a) {
    auto env = static_cast<homu::ADSR*>(v);
    env->setAttack(a);
}

void h_adsr_set_decay(void *v, double d) {
    auto env = static_cast<homu::ADSR*>(v);
    env->setDecay(d);
}

void h_adsr_set_sustain(void *v, double s) {
    auto env = static_cast<homu::ADSR*>(v);
    env->setSustain(s);
}

void h_adsr_set_release(void *v, double r) {
    auto env = static_cast<homu::ADSR*>(v);
    env->setRelease(r);
}

void h_adsr_stop_sustain(void *v) {
    auto gen = static_cast<homu::ADSR*>(v);
    gen->stopSustain();
}


// Delay section
void *h_delay () {
    auto fil = new homu::Delay();
    return static_cast<void*>(fil);
}
void h_delay_set_size(void *v, double value) {
    auto fil = static_cast<homu::Delay*>(v);
    fil->setSize(value);
}


// Distortion section
void *h_distortion () {
    auto fil = new homu::Distortion();
    return static_cast<void*>(fil);
}

void h_distortion_set_level (void *v, double value) {
    auto gen = static_cast<homu::Distortion*>(v);
    gen->setLevel(value);
}
