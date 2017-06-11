/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   07 Jun 2017
*/

#include <stdlib.h>
#include "memory.h"

#include "mixing.h"


void mono_summator_d(const struct mono_audio_d *input,
                     struct mono_audio_d *output,
                     const void *unused)
{
    (void) unused;

    output->amplitude += input->amplitude;
}

void mixing_signals(const struct mixing_parameters *parameters,
                    const struct signal * signals,
                    frame_transform_operation summator,
                    frame_transform_operation gainer,
                    struct signal *output)
{
    struct signal buffer = *output;
    buffer.frames = malloc(buffer.bytes);

    memset(output->frames, 0, output->bytes);

    for (size_t i = 0; i < parameters->size; i++)
    {
        const double gain = parameters->gaines[i];

        apply_transform(signals + i, &buffer, gainer, &gain);
        apply_transform(&buffer, output, summator, NULL);
    }

    free(buffer.frames);
}
