//
// Created by Stefanos Mitropoulos on 2019-05-17.
//

#include "LoggingUtility.h"

void LoggingUtility::initialise() const {
    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("Welcome to spdlog! This is a debug message.");

}
