//
// Created by Stefanos Mitropoulos on 2019-05-17.
//

#include "ArgHandler.h"

void ArgHandler::handleArg(int argc, char *argv[]) {

    int opt;

// Retrieve the options:
    while ((opt = getopt(argc, argv, "v:")) != -1) {  // for each option...
        switch (opt) {  //NOLINT
            case 'v':
                switch (std::stoi(optarg)) {
                    case 0:
                        spdlog::set_level(spdlog::level::critical); // Set global log level to debug
                        break;
                    case 1:
                        spdlog::set_level(spdlog::level::err); // Set global log level to debug
                        break;
                    case 2:
                        spdlog::set_level(spdlog::level::warn); // Set global log level to debug
                        break;
                    case 3:
                        spdlog::set_level(spdlog::level::info); // Set global log level to debug
                        break;
                    case 4:
                        spdlog::set_level(spdlog::level::debug); // Set global log level to debug
                        break;
                    case 5:
                        spdlog::set_level(spdlog::level::off); // Set global log level to debug
                        break;
                }

                break;
        }
    }
}
