/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#pragma once

#include <memory>

#include "signals.hpp"

class tone_generator {
public:
    tone_generator(size_t rate);

    std::shared_ptr<mono_signal> operator()(
            double freq, size_t durations_ms);

private:
    size_t rate;
};
