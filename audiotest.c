#include <stdio.h>

#include <include/signal.h>
#include <include/audio_types.h>

int main() {
    struct signal input;
    input.frame_size = sizeof(struct mono_audio_d);
    input.bytes = input.frame_size *
}