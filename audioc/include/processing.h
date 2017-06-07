/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   07 Jun 2017
*/

#pragma once

#include "signal.h"
#include "audio_types.h"

void gain_mono_d(const struct mono_audio_d *input,
                 struct mono_audio_d *output,
                 const double *gain);

void gain_stereo_d(const struct stereo_audio_d *input,
                   struct stereo_audio_d *output,
                   const double *gain);
