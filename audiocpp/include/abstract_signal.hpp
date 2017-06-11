/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#pragma once

#include <memory>

#include "abstract_frame.hpp"
#include "abstract_processing.hpp"

class abstract_signal {
public:
    virtual std::pair<const char *, size_t> raw_data() = 0;
    virtual std::shared_ptr<abstract_signal> coped() = 0;
    virtual abstract_signal& operator=(const abstract_signal &signal) = 0;
    virtual size_t frame_size() = 0;
    virtual abstract_frame& operator[](size_t idx) = 0;
};

inline void apply_transform(const std::shared_ptr<abstract_signal> &input,
                            std::shared_ptr<abstract_signal> &output,
                            abstract_processing &processing)
{
    *output = *input;
    for (size_t i = 0; i < input->frame_size(); i++)
    {
        processing((*input)[i], (*output)[i]);
    }
}

