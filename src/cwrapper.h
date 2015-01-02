#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

void *SinusGenerator_create     (size_t sample_rate);
void  SinusGenerator_destroy    (void *v);
void  SinusGenerator_start      (void *v, float freq);
float SinusGenerator_nextSample (void *v);

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
