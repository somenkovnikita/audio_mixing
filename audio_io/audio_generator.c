/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   07 Jun 2017
*/

#include <math.h>

#include "audio_generator.h"

void generate_tone_d(const struct tone_generator_params *params,
                     double *output)
{
    static const double _2pi = 2.0 * M_PI;

    const double freq = params->frequency;
    const double rate = params->rate;
    const double dur = params->durations_ms;

    const size_t size = (size_t) round(rate * dur / 1000.0);

    for (size_t i = 0; i < size; i++)
    {
        const double x = i / rate;
        output[i] = sin(_2pi * freq * x);
    }
}
