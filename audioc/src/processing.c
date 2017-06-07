/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   07 Jun 2017
*/

#include "processing.h"

void gain_mono_d(const struct mono_audio_d *input,
                 struct mono_audio_d *output,
                 const double *gain)
{
    const double g = *gain;
    const double a = input->amplitude;

    output->amplitude = g * a;
}

void gain_stereo_d(const struct stereo_audio_d *input,
                   struct stereo_audio_d *output,
                   const double *gain)
{
    const double g = *gain;

    const double l = input->left_amplitude;
    const double r = input->right_amplitude;

    output->left_amplitude = g * l;
    output->right_amplitude = g * r;
}



