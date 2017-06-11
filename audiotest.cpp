/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#include <array>
#include <cstdlib>
#include <fstream>

#include "audiocpp/include/signals.hpp"
#include "audiocpp/include/tone_generator.hpp"
#include "audiocpp/include/mixer.hpp"


int main()
{
    const size_t size = 1000;
    const size_t duration = 10000;
    std::array<std::shared_ptr<abstract_signal>,
            size> signals;

    size_t current_freq = 100;
    tone_generator generator(44100);
    for (auto &signal: signals) {
        signal = generator(current_freq, duration);
        current_freq += std::rand() % 10;
    }

    mixer mixer;
    for (size_t i = 0; i < size; i++) {
        const double v = (rand() % 10000) / 10000.0;
        mixer.add_signal(v, signals[i]);
    }

    auto mixed_signal = mixer.mixed();

    std::ofstream file("mixed.out",
            std::ios_base::binary);

    auto mixed_raw = mixed_signal->raw_data();
    file.write(mixed_raw.first, mixed_raw.second);

    return 0;
}