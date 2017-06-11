/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#include "frames.hpp"

mono::mono() = default;

mono::mono(double amplitude) : amplitude(amplitude) { }

mono &mono::operator=(const mono &other) {
    const abstract_frame &b = other;
    abstract_frame &a = *this;
    return static_cast<mono &>(a = b);
}

abstract_frame &mono::operator=(const abstract_frame &other) {
    auto other_casted = static_cast<const mono&>(other);
    amplitude = other_casted.amplitude;
    return *this;
}

abstract_frame &mono::operator*=(double num) {
    amplitude *= num;
    return *this;
}

abstract_frame &mono::operator+=(const abstract_frame& other) {
    auto other_casted = static_cast<const mono&>(other);
    amplitude += other_casted.amplitude;
    return *this;
}
