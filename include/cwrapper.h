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

MODULE_API void h_set_sample_rate(size_t sr);

// Generators
MODULE_API void hg_delete(void *v);
MODULE_API void hg_start(void *v, double freq);
MODULE_API double hg_next_sample(void *v);

MODULE_API void *h_sinewave();

MODULE_API void *h_triangle();
MODULE_API void h_triangle_set_width(void *v, double w);

MODULE_API void *h_karplus_strong();

MODULE_API void *h_white_noise();
MODULE_API void *h_pink_noise();
MODULE_API void *h_brown_noise();

// Envelopes
MODULE_API void he_delete(void *v);
MODULE_API void he_start(void *v);
MODULE_API double he_next_sample(void *v);
MODULE_API int he_finished(void *v);
MODULE_API double he_seconds_played(void *v);

MODULE_API void *h_adsr();
MODULE_API void h_adsr_start(void *v);
MODULE_API double h_adsr_next_sample(void *v);
MODULE_API void h_adsr_set_attack(void *v, double a);
MODULE_API void h_adsr_set_decay(void *v, double d);
MODULE_API void h_adsr_set_sustain(void *v, double s);
MODULE_API void h_adsr_set_release(void *v, double r);
MODULE_API void h_adsr_stop_sustain(void *v);

// Filters
MODULE_API void hf_delete(void *v);
MODULE_API void hf_start(void *v);
MODULE_API double hf_next_sample(void *v, double s);

MODULE_API void *h_delay();
MODULE_API void h_delay_set_size(void *v, double s);

MODULE_API void *h_distortion();
MODULE_API void h_distortion_set_level(void *v, double s);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CWRAPPER_H

