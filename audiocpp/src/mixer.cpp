/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   11 Jun 2017
*/

#include "mixer.hpp"
#include "processing.hpp"

void mixer::add_signal(double volume,
                       std::shared_ptr<abstract_signal> signal) {
    signals.push_back(std::make_pair(volume, signal));
}

std::shared_ptr<abstract_signal> mixer::mixed() {
    auto it = signals.begin();

    auto output = it->second->coped();
    auto buffer = it->second->coped();

    gain volume(it->first);
    apply_transform(output, output, volume);

    summator summator;
    for (++it; it != signals.end(); ++it) {
        gain vol(it->first);
        apply_transform(it->second, buffer, vol);
        apply_transform(buffer, output, summator);
    }

    return output;
}
