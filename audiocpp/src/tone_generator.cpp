/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#include <cmath>

#include "tone_generator.hpp"

tone_generator::tone_generator(size_t rate) : rate(rate) { }

std::shared_ptr<mono_signal> tone_generator::operator()(
        double freq, size_t durations_ms)
{
    const double _2pi = 2.0 * M_PI;
    const size_t sec = durations_ms / 1000;
    const size_t samples = rate * sec;

    std::vector<double> signal(samples);

    for (size_t i = 0; i < signal.size(); i++)
    {
        const double x = i / static_cast<double>(rate);
        signal[i] = std::sin(_2pi * freq * x);
    }

    return std::make_shared<mono_signal>(signal);
}
