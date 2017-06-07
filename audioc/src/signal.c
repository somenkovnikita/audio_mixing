/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   07 Jun 2017
*/

#include "signal.h"

int apply_transform(const struct signal *input,
                    struct signal *output,
                    frame_transform_operation operation,
                    const void *operation_args)
{
    const size_t step = input->frame_size;
    for (size_t i = 0; i < input->bytes; i += step)
    {
        const void *in_frame = input->frames + i;
        void *out_frame = output->frames + i;
        operation(in_frame, out_frame, operation_args);
    }
    return 0;
}