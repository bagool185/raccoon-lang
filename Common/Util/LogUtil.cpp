//
// Created by bagool on 08/02/2018.
//
#include <cstdio>
#include <fstream>
#include <algorithm>

#include "LogUtil.h"

using namespace RCC;

/* static members definitions */
std::vector< log_message > Log::_logs;
/* logs are enabled by default */
bool Log::_logs_disabled = false;

void Log::load_log(const log_message& log) {
    // only load a log if the logs aren't disabled
    if (!_logs_disabled) {
        _logs.emplace_back(log);
    }
}

const char* Log::_log_to_string(log_message log) {
    std::string log_level;
    auto* full_message = (char*)malloc(255);

    switch (log.first) {
        case LogLevel::INFO:
            log_level = "INFO";
            break;
        case LogLevel::WARNING:
            log_level = "WARNING";
            break;
        case LogLevel::ERROR:
            log_level = "ERROR";
            break;
        case LogLevel::DEBUG:
            log_level = "DEBUG";
            break;
    }

    sprintf(full_message, "%s: %s\n", log_level.c_str(), log.second);

    return full_message;
}
/* save the logs into a file or print them to stdout if no parameter provided*/
void Log::save_logs(FILE* outputstream) {
    try {
        load_log({LogLevel::INFO, "iterating through logs..."});

        for (const auto& _ : _logs) {
            fputs(("%s", _log_to_string(_)), outputstream);
        }

        if (outputstream != stdout) {
            load_log({LogLevel::INFO, "file successfully created"});
            fclose(outputstream);
        }
    }
    catch (std::exception& e) {
        load_log({LogLevel::ERROR, e.what()});
    }
}
void Log::clear_logs() {
    _logs.clear();
}
/* toggle the enable/disabled state of the logs */
void Log::set_logs_state(const bool state) {
    /**
     * @param state: true for enabled, false for disabled
     */
    _logs_disabled = !state;
}
/* clear and disable the logs when terminated */
Log::~Log() {
    clear_logs();
    set_logs_state(false);
}
