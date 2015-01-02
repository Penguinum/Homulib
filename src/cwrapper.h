#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

void *SinusGenerator_create(size_t sample_rate);

void SinusGenerator_destroy(void *v);

void SinusGenerator_start(void *v, float freq);

float SinusGenerator_nextSample(void *v);

#ifdef __cplusplus
}
#endif
