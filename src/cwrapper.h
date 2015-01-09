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

MODULE_API void *SinewaveGenerator_Create     (size_t sample_rate);
MODULE_API void  SinewaveGenerator_Destroy    (void *v);
MODULE_API void  SinewaveGenerator_Start      (void *v, float freq);
MODULE_API float SinewaveGenerator_NextSample (void *v);

MODULE_API void *TriangleGenerator_Create     (size_t sample_rate);
MODULE_API void  TriangleGenerator_Destroy    (void *v);
MODULE_API void  TriangleGenerator_Start      (void *v, float freq);
MODULE_API float TriangleGenerator_NextSample (void *v);
MODULE_API void  TriangleGenerator_SetWidth   (void *v, float w);

MODULE_API void *KarplusStrongGenerator_Create     (size_t sample_rate);
MODULE_API void  KarplusStrongGenerator_Destroy    (void *v);
MODULE_API void  KarplusStrongGenerator_Start      (void *v, float freq);
MODULE_API float KarplusStrongGenerator_NextSample (void *v);

MODULE_API void *WhiteNoiseGenerator_Create     (size_t sample_rate);
MODULE_API void  WhiteNoiseGenerator_Destroy    (void *v);
MODULE_API void  WhiteNoiseGenerator_Start      (void *v, float freq);
MODULE_API float WhiteNoiseGenerator_NextSample (void *v);

MODULE_API void *PinkNoiseGenerator_Create     (size_t sample_rate);
MODULE_API void  PinkNoiseGenerator_Destroy    (void *v);
MODULE_API void  PinkNoiseGenerator_Start      (void *v, float freq);
MODULE_API float PinkNoiseGenerator_NextSample (void *v);

MODULE_API void *BrownNoiseGenerator_Create     (size_t sample_rate);
MODULE_API void  BrownNoiseGenerator_Destroy    (void *v);
MODULE_API void  BrownNoiseGenerator_Start      (void *v, float freq);
MODULE_API float BrownNoiseGenerator_NextSample (void *v);

MODULE_API void *ADSR_Create        (size_t sample_rate);
MODULE_API void  ADSR_Destroy       (void *v);
MODULE_API void  ADSR_Start         (void *v);
MODULE_API float ADSR_NextSample    (void *v);
MODULE_API void  ADSR_SetAttack     (void *v, float a);
MODULE_API void  ADSR_SetDecay      (void *v, float d);
MODULE_API void  ADSR_SetSustain    (void *v, float s);
MODULE_API void  ADSR_SetRelease    (void *v, float r);
MODULE_API int   ADSR_Finished      (void *v);
MODULE_API float ADSR_SecondsPlayed (void *v);
MODULE_API void  ADSR_StopSustain   (void *v);

#ifdef __cplusplus
}
#endif

#endif
