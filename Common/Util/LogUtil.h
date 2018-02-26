//
// Created by bagool on 08/02/2018.
//

#ifndef RACCOONLANG_LOGUTIL_H
#define RACCOONLANG_LOGUTIL_H

#include <vector>
#include <cstdio>
#include <tuple>

namespace RCC {

    enum class LogLevel {
        INFO,
        WARNING,
        ERROR,
        DEBUG
    };

    typedef std::tuple<const LogLevel, const std::string, const std::string> log_message;

    class Log {
        static std::vector<log_message> _logs;
        static bool _logs_disabled;
        static const std::string _log_to_string(const log_message& log);
        Log() = default;
    public:
        ~Log();
        static void load_log(const log_message& log);
        static void clear_logs();
        static void save_logs(FILE* outputstream = stdout);
        static void set_logs_state(bool state);
    };
}
#endif //RACCOONLANG_LOGUTIL_H
