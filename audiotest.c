#include <stdlib.h>

#include <include/signal.h>
#include <include/audio_types.h>
#include <include/audio_generator.h>
#include <include/audio_io.h>
#include <include/mixing.h>
#include <include/processing.h>

struct signal generate_44100_10000(double freq)
{
    struct tone_generator_params params;
    params.durations_ms = 10000;
    params.rate = 44100;
    params.frequency = freq;

    const size_t sec = params.durations_ms / 1000;
    const size_t samples = params.rate * sec;
    const size_t mem_size = sizeof(double) * samples;

    double *mono_signal = (double *) malloc(mem_size);
    // mem check
    generate_tone_d(&params, mono_signal);

    struct signal output;
    output.frames = mono_signal;
    output.frame_size = sizeof(double);
    output.bytes = mem_size;

    return output;
}

double *gainers(size_t size)
{
    const size_t mem_size = size * sizeof(double);
    double *mono_signal = (double *) malloc(mem_size);

    for (size_t i = 0; i < size; i++) {
        mono_signal[i] = (rand() % 10000) / 10000.0;
    }

    return mono_signal;
}

int main() {
    const size_t tracks = 1000;
    struct signal signals[tracks];

    double current_freq = 100;
    for (size_t i = 0; i < tracks; i++) {
        signals[i] = generate_44100_10000(current_freq);
        current_freq += rand() % 10;
    }

    struct mixing_parameters parameters;
    parameters.size = tracks;
    parameters.gaines = gainers(tracks);

    struct signal mixed;
    mixed.frames = malloc(signals->bytes);
    mixed.frame_size = signals->frame_size;
    mixed.bytes = signals->bytes;

    mixing_signals(&parameters,
                   signals,
                   (frame_transform_operation) mono_summator_d,
                   (frame_transform_operation) gain_mono_d,
                   &mixed);

    struct io_device file_io;
    file_io.read = from_file_raw_audio;
    file_io.write = to_file_raw_audio;

    io_write(&file_io, mixed.frames, mixed.bytes, "out.raw_mono_d");

    for (size_t i = 0; i < tracks; i++) {
        free(signals[i].frames);
    }
    free(parameters.gaines);
    free(mixed.frames);

    return 0;
}