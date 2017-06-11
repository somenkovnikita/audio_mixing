/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#pragma once

#include <vector>

#include "frames.hpp"
#include "abstract_signal.hpp"

class mono_signal : public abstract_signal {
public:
    mono_signal();

    mono_signal(const std::vector<double> & signal);

    std::shared_ptr<abstract_signal> coped() override;

    mono_signal &operator=(const mono_signal &signal);

    abstract_signal &operator=(const abstract_signal &signal) override;

    size_t frame_size() override;

    abstract_frame &operator[](size_t idx) override;

    std::pair<const char *, size_t> raw_data() override;

private:
    std::vector<mono> frames;
};

