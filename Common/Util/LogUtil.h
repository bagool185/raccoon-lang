//
// Created by bagool on 08/02/2018.
//

#ifndef RACCOONLANG_LOGUTIL_H
#define RACCOONLANG_LOGUTIL_H

#include <vector>
#include <cstdio>

namespace RCC {

    enum class LogLevel {
        INFO,
        WARNING,
        ERROR,
        DEBUG
    };

    typedef std::pair<const LogLevel, const char *> log_message;

    class Log {
        static std::vector<log_message> _logs;
        static const char * _log_to_string(LogLevel log);
        Log() = default;
    public:
        ~Log();
        static void load_log(const log_message& log);
        static void clear_logs();
        static void save_logs(FILE* outputstream = stdout);
    };
}
#endif //RACCOONLANG_LOGUTIL_H
