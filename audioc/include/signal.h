/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   07 Jun 2017
*/

#pragma once

#include <stddef.h>
#include <stdarg.h>

typedef void abstract_frame;

struct signal {
    abstract_frame *frames;
    size_t frame_size;
    size_t bytes;
};

typedef void (*frame_transform_operation)(
        const void *input,
        void *output,
        const void *user_args);

int apply_transform(const struct signal *input,
                    struct signal *output,
                    frame_transform_operation operation,
                    const void *operation_args);

