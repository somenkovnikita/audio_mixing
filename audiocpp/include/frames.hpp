/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#pragma once

#include "abstract_frame.hpp"

class mono : public abstract_frame {
public:
    mono();
    mono(double amplitude);

    mono &operator=(const mono &other);
    abstract_frame &operator=(const abstract_frame &other) override;

    abstract_frame &operator*=(double num) override;
    abstract_frame &operator+=(const abstract_frame &other) override;

private:
    double amplitude;
};

class stereo : public abstract_frame {

};

