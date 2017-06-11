/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#pragma once

class abstract_frame {
public:
    virtual abstract_frame& operator=(const abstract_frame& other) = 0;
    virtual abstract_frame& operator*=(double num) = 0;
    virtual abstract_frame& operator+=(const abstract_frame& other) = 0;
};

