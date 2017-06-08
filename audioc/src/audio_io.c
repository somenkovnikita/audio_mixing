/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   07 Jun 2017
*/

#include <stdio.h>

#include "../include/audio_io.h"

void from_file_raw_audio(void *data, size_t size, const void *args)
{
    const char *path = args;

    FILE *file = fopen(path, "rb");
    fread(data, sizeof(char), size, file);
    fclose(file);
}

void to_file_raw_audio(const void *data, size_t size, const void *args)
{
    const char *path = args;

    FILE *file = fopen(path, "wb");
    fwrite(data, sizeof(char), size, file);
    fclose(file);
}


void io_write(const struct io_device *device, const void *data, size_t size, const void *args)
{
    device->write(data, size, args);
}

void io_read(const struct io_device *device, void *data, size_t size, const void *args)
{
    device->read(data, size, args);
}
