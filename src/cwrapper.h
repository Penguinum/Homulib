#ifndef CWRAPPER_H
#define CWRAPPER_H

#include <stdlib.h>

#ifdef _WIN32
#  ifdef BUILD_THIS_LIB
#    define MODULE_API __declspec(dllexport)
#  else
#    define MODULE_API __declspec(dllimport)
#  endif
#else
#  define MODULE_API
#endif

#ifdef __cplusplus
extern "C"
{
#endif

MODULE_API void *SinewaveGenerator_create     (size_t sample_rate);
MODULE_API void  SinewaveGenerator_destroy    (void *v);
MODULE_API void  SinewaveGenerator_start      (void *v, float freq);
MODULE_API float SinewaveGenerator_nextSample (void *v);

MODULE_API void *TriangleGenerator_create     (size_t sample_rate);
MODULE_API void  TriangleGenerator_destroy    (void *v);
MODULE_API void  TriangleGenerator_start      (void *v, float freq);
MODULE_API float TriangleGenerator_nextSample (void *v);
MODULE_API void  TriangleGenerator_setWidth   (float w);

MODULE_API void *KarplusStrongGenerator_create     (size_t sample_rate);
MODULE_API void  KarplusStrongGenerator_destroy    (void *v);
MODULE_API void  KarplusStrongGenerator_start      (void *v, float freq);
MODULE_API float KarplusStrongGenerator_nextSample (void *v);

MODULE_API void *WhiteNoiseGenerator_create     (size_t sample_rate);
MODULE_API void  WhiteNoiseGenerator_destroy    (void *v);
MODULE_API void  WhiteNoiseGenerator_start      (void *v, float freq);
MODULE_API float WhiteNoiseGenerator_nextSample (void *v);

MODULE_API void *PinkNoiseGenerator_create     (size_t sample_rate);
MODULE_API void  PinkNoiseGenerator_destroy    (void *v);
MODULE_API void  PinkNoiseGenerator_start      (void *v, float freq);
MODULE_API float PinkNoiseGenerator_nextSample (void *v);

MODULE_API void *BrownNoiseGenerator_create     (size_t sample_rate);
MODULE_API void  BrownNoiseGenerator_destroy    (void *v);
MODULE_API void  BrownNoiseGenerator_start      (void *v, float freq);
MODULE_API float BrownNoiseGenerator_nextSample (void *v);

MODULE_API void *ADSR_create        (size_t sample_rate);
MODULE_API void  ADSR_destroy       (void *v);
MODULE_API void  ADSR_start         (void *v);
MODULE_API float ADSR_nextSample    (void *v);
MODULE_API void  ADSR_setAttack     (void *v, float a);
MODULE_API void  ADSR_setDecay      (void *v, float d);
MODULE_API void  ADSR_setSustain    (void *v, float s);
MODULE_API void  ADSR_setRelease    (void *v, float r);
MODULE_API int   ADSR_finished      (void *v);
MODULE_API float ADSR_secondsPlayed (void *v);
MODULE_API void  ADSR_stopSustain   (void *v);

#ifdef __cplusplus
}
#endif

#endif
