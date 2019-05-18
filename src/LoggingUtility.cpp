//
// Created by Stefanos Mitropoulos on 2019-05-17.
//

#include <iostream>
#include "LoggingUtility.h"

void LoggingUtility::initialise(int arg) const {

    switch (arg) {
        case 0:
            spdlog::set_level(spdlog::level::critical);
            break;
        case 1:
            spdlog::set_level(spdlog::level::err);
            break;
        case 2:
            spdlog::set_level(spdlog::level::warn);
            break;
        case 3:
            spdlog::set_level(spdlog::level::info);
            break;
        case 4:
            spdlog::set_level(spdlog::level::debug);
            break;
        default:
            spdlog::set_level(spdlog::level::off);
            break;
    }

}

