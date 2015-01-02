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
