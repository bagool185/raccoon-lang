//
// Created by bagool on 08/02/2018.
//
#include <cstdio>
#include <fstream>
#include <algorithm>

#include "LogUtil.h"

using namespace RCC;

std::vector< log_message > Log::_logs;

void Log::load_log(const log_message& log) {
    _logs.emplace_back(log);
}

const char* Log::_log_to_string(LogLevel log) {
    switch (log) {
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::DEBUG:
            return "DEBUG";
    }
}
/* save the logs into a file or print them to stdout if no parameter provided*/
void Log::save_logs(FILE* outputstream) {
    try {
        load_log({LogLevel::INFO, "iterating through logs..."});

        for (const auto &_ : _logs) {
            fprintf(outputstream, "%s: %s\n", _log_to_string(_.first), _.second);
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
/* clear the logs when terminated */
Log::~Log() {
    clear_logs();
}