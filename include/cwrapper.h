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

MODULE_API void Homu_SetSampleRate(size_t sr);

MODULE_API void *Sinewave_Create     ();
MODULE_API void  Sinewave_Destroy    (void *v);
MODULE_API void  Sinewave_Start      (void *v, double freq);
MODULE_API double Sinewave_NextSample (void *v);

MODULE_API void *Triangle_Create     ();
MODULE_API void  Triangle_Destroy    (void *v);
MODULE_API void  Triangle_Start      (void *v, double freq);
MODULE_API double Triangle_NextSample (void *v);
MODULE_API void  Triangle_SetWidth   (void *v, double w);

MODULE_API void *KarplusStrong_Create     ();
MODULE_API void  KarplusStrong_Destroy    (void *v);
MODULE_API void  KarplusStrong_Start      (void *v, double freq);
MODULE_API double KarplusStrong_NextSample (void *v);

MODULE_API void *WhiteNoise_Create     ();
MODULE_API void  WhiteNoise_Destroy    (void *v);
MODULE_API void  WhiteNoise_Start      (void *v, double freq);
MODULE_API double WhiteNoise_NextSample (void *v);

MODULE_API void *PinkNoise_Create      ();
MODULE_API void  PinkNoise_Destroy     (void *v);
MODULE_API void  PinkNoise_Start       (void *v, double freq);
MODULE_API double PinkNoise_NextSample (void *v);

MODULE_API void *BrownNoise_Create      ();
MODULE_API void  BrownNoise_Destroy     (void *v);
MODULE_API void  BrownNoise_Start       (void *v, double freq);
MODULE_API double BrownNoise_NextSample (void *v);

MODULE_API void  *ADSR_Create        ();
MODULE_API void   ADSR_Destroy       (void *v);
MODULE_API void   ADSR_Start         (void *v);
MODULE_API double ADSR_NextSample    (void *v);
MODULE_API void   ADSR_SetAttack     (void *v, double a);
MODULE_API void   ADSR_SetDecay      (void *v, double d);
MODULE_API void   ADSR_SetSustain    (void *v, double s);
MODULE_API void   ADSR_SetRelease    (void *v, double r);
MODULE_API int    ADSR_Finished      (void *v);
MODULE_API double ADSR_SecondsPlayed (void *v);
MODULE_API void   ADSR_StopSustain   (void *v);

MODULE_API void  *Delay_Create     ();
MODULE_API void   Delay_Destroy    (void *v);
MODULE_API void   Delay_Start      (void *v);
MODULE_API double Delay_NextSample (void *v, double s);
MODULE_API void   Delay_SetSize    (void *v, double s);

MODULE_API void  *Distortion_Create    ();
MODULE_API void   Distortion_Destroy   (void *v);
MODULE_API void   Distortion_Start     (void *v);
MODULE_API double Distortion_NextSample(void *v, double s);
MODULE_API void   Distortion_SetLevel  (void *v, double s);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CWRAPPER_H

