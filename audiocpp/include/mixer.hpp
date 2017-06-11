/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#pragma once

#include <list>
#include <memory>

#include "abstract_signal.hpp"

class mixer {
public:
    std::shared_ptr<abstract_signal> mixed();

    void add_signal(double volume, std::shared_ptr<abstract_signal> signal);
private:
    std::list<std::pair<double, std::shared_ptr<abstract_signal> > > signals;
};