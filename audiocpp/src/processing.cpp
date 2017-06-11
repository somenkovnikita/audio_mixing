/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#include "processing.hpp"

gain::gain(double gain_value) : gain_value(gain_value) { }

void gain::operator()(const abstract_frame &input, abstract_frame &output) {
    output = input;
    output *= gain_value;
}

void summator::operator()(const abstract_frame &input, abstract_frame &output) {
    output += input;
}

