//
// Created by bagool on 07/02/2018.
//

#ifndef RACCOONLANG_EXCEPTIONHANDLINGUTIL_H
#define RACCOONLANG_EXCEPTIONHANDLINGUTIL_H

#include <exception>
#include <iostream>
#include <cstdio>

namespace RCC {
    class E : public std::exception {
        const char *_msg;

        E() {}

    public:
        E(const char *msg) : _msg(msg) {}

        const char *what() const throw() { return _msg; }
    };
}

enum class LogLevel {
    LOG_ERROR,
    LOG_WARNING,
    LOG_INFO,
    LOG_DEBUG
};

class Log {

    LogLevel _message_level;

    Log(const Log&);
    Log& operator =(const Log&);
public:
    Log();
    virtual ~Log();
    std::ostream& Get(LogLevel level = LogLevel::LOG_INFO);

    static LogLevel& ReportingLevel();
protected:
    std::ostream& os;
};

inline const std::string to_string(LogLevel level) {
    switch (level) {
        case LogLevel::LOG_DEBUG:   return "DEBUG";
        case LogLevel::LOG_ERROR:   return "ERROR";
        case LogLevel ::LOG_INFO:   return "INFO";
        case LogLevel::LOG_WARNING: return "WARNING";
    }
}

std::ostream& Log::Get(LogLevel level) {
    os << to_string(level) << ": ";
    os << std::string(level > LogLevel::LOG_DEBUG ? 0 : (int)level - (int)LogLevel::LOG_DEBUG, '\t');
}

Log::~Log() {
    if (_message_level >= Log::ReportingLevel()) {
        os << std::endl;
        fprintf(stderr, "%s", os.str().c_str());
        fflush(stderr);
    }
}

#endif //RACCOONLANG_EXCEPTIONHANDLINGUTIL_H
