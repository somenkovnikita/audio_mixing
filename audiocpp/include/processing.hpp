/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#pragma once

#include "abstract_processing.hpp"

class gain : public abstract_processing {
public:
    gain(double gain_value);

    void operator()(const abstract_frame &input, abstract_frame &output) override;

private:
    double gain_value;
};


class summator : public abstract_processing {
public:
    void operator()(const abstract_frame &input, abstract_frame &output) override;
};