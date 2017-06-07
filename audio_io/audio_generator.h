/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   07 Jun 2017
*/

#pragma once

#include <stddef.h>

struct tone_generator_params {
    double frequency;
    size_t rate;
    size_t durations_ms;
};

void generate_tone_d(const struct tone_generator_params *params,
                     double *output);

