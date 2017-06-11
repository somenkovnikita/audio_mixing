/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#include "signals.hpp"

mono_signal::mono_signal() = default;

mono_signal::mono_signal(const std::vector<double> &signal)
        : frames(signal.size())
{
    for (size_t i = 0; i < frames.size(); i++) {
        frames[i] = mono{signal[i]};
    }
}

mono_signal &mono_signal::operator=(const mono_signal &signal) {
    const abstract_signal &b = signal;
    abstract_signal &a = *this;
    return static_cast<mono_signal &>(a = b);
}

abstract_signal &mono_signal::operator=(const abstract_signal &signal) {
    auto casted = static_cast<const mono_signal &>(signal);
    frames = casted.frames;
    return *this;
}

size_t mono_signal::frame_size() {
    return frames.size();
}

abstract_frame &mono_signal::operator[](size_t idx) {
    return frames[idx];
}

std::shared_ptr<abstract_signal> mono_signal::coped() {
    auto coped_signal =
            std::make_shared<mono_signal>();

    *coped_signal = *this;
    return std::move(coped_signal);
}

std::pair<const char *, size_t> mono_signal::raw_data() {
    const auto ptr = reinterpret_cast<
            const char *>(frames.data());
    return std::make_pair(ptr, sizeof(double) * frames.size());
}
