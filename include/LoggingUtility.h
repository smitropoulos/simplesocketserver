//
// Created by Stefanos Mitropoulos on 2019-05-17.
//

#ifndef TCP_SERVER_THREADED_LOGGINGUTILITY_H
#define TCP_SERVER_THREADED_LOGGINGUTILITY_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

class LoggingUtility {
private:
    LoggingUtility() = default;

public:
    static LoggingUtility &getInstance() {
        static LoggingUtility xInstance;
        return xInstance;
    }

    void initialise(int arg) const;
};


#endif //TCP_SERVER_THREADED_LOGGINGUTILITY_H
