#ifndef CWRAPPER_H
#define CWRAPPER_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

void *SinewaveGenerator_create     (size_t sample_rate);
void  SinewaveGenerator_destroy    (void *v);
void  SinewaveGenerator_start      (void *v, float freq);
float SinewaveGenerator_nextSample (void *v);

void *ADSR_create        (size_t sample_rate);
void  ADSR_destroy       (void *v);
void  ADSR_start         (void *v);
float ADSR_nextSample    (void *v);
void  ADSR_setAttack     (void *v, float a);
void  ADSR_setDecay      (void *v, float d);
void  ADSR_setSustain    (void *v, float s);
void  ADSR_setRelease    (void *v, float r);
int   ADSR_finished      (void *v);
float ADSR_secondsPlayed (void *v);
void  ADSR_stopSustain   (void *v);

#ifdef __cplusplus
}
#endif

#endif
