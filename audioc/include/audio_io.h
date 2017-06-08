/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   07 Jun 2017
*/

#pragma once

#include <stddef.h>

typedef void (*read_operation)(void *data, size_t size, const void *args);
typedef void (*write_operation)(const void *data, size_t size, const void *args);

struct io_device {
    read_operation read;
    write_operation write;
};

void from_file_raw_audio(void *data, size_t size, const void *args);

void to_file_raw_audio(const void *data, size_t size, const void *args);

void io_write(const struct io_device *device, const void *data, size_t size, const void *args);

void io_read(const struct io_device *device, void *data, size_t size, const void *args);
