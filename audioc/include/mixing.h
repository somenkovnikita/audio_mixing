/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   07 Jun 2017
*/

#pragma once

#include "signal.h"
#include "audio_types.h"

struct mixing_parameters {
    double *gaines;
    size_t size;
};

void mono_summator_d(const struct mono_audio_d *input,
                     struct mono_audio_d *output,
                     const void *unused);

void stereo_summator_d(const struct stereo_audio_d *input,
                       struct stereo_audio_d *output,
                       const void *unused);

void mixing_signals(const struct mixing_parameters *parameters,
                    const struct signal **signals,
                    frame_transform_operation summator,
                    frame_transform_operation gainer,
                    struct signal *output);
