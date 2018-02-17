//
// Created by bagool on 08/02/2018.
//
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <ctime>

#include "LogUtil.h"

using namespace RCC;

std::vector< log_message > Log::_logs;

void Log::load_log(const log_message& log) {
    _logs.emplace_back(log);
}

const char *Log::_log_to_string(LogLevel log) {
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

void Log::print_logs() {
    for (const auto &_ : _logs) {
        printf("%s: %s\n", _log_to_string(_.first), _.second);
    }
}

void Log::clear_logs() {
    _logs.clear();
}
/* clear the logs when terminated */
Log::~Log() {
    clear_logs();
}

void Log::save_logs() {
    std::string log_filename;
    std::string crt_time;

    time_t rawtime;
    time (&rawtime);

    crt_time = ctime(&rawtime);
    // remove spaces
    crt_time.erase(std::remove_if(crt_time.begin(), crt_time.end(), isspace),
                   crt_time.end());

    try {
        load_log({LogLevel::INFO, "iterating through logs"});
        log_filename = "log_file";
        load_log({LogLevel::DEBUG, log_filename.c_str()});

        FILE* log_file = fopen(log_filename.c_str(), "w");

        for (const auto& _ : _logs) {
            fprintf(log_file, ("%s %s\n", _log_to_string(_.first), _.second ));
        }

        fclose(log_file);
    }
    catch (std::exception& e) {
        load_log({LogLevel::ERROR, e.what()});
        print_logs();
    }
}
