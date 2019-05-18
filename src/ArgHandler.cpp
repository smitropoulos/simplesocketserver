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
                LoggingUtility::getInstance().initialise(std::stoi(optarg));
                break;
            default:
                LoggingUtility::getInstance().initialise(spdlog::level::off);
        }
    }
}
