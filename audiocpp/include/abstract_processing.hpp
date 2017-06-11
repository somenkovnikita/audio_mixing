/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#pragma once

#include <memory>

#include "abstract_frame.hpp"

class abstract_processing {
public:
    virtual void operator()(const abstract_frame &input,
                            abstract_frame &output) = 0;
};
