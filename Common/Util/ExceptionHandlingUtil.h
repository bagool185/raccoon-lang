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

        E() = default;

    public:
        explicit
        E(const char *msg) : _msg(msg) {}

        const char *
        what() const throw() override { return _msg; }
    };
}

#endif //RACCOONLANG_EXCEPTIONHANDLINGUTIL_H
