//
// Created by bagool on 07/02/2018.
//

#ifndef RACCOONLANG_STRINGUTIL_H
#define RACCOONLANG_STRINGUTIL_H

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

#include "types.h"
#include "LogUtil.h"

/* trim the left-hand side of a string */
static inline void
ltrim(str_ref s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}
/* trim the right-hand side of a string */
static inline void
rtrim(str_ref s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}
/* trim a string */
static inline void
trim(str_ref s) {
    ltrim(s);
    rtrim(s);
}
/* split a string by a given delimiter */
static inline vect_s
split(str_ref line, const char delimiter=' ') {
    /**
     * @param line: string to be split
     * @param delimiter: delimiter by which the string will be split
     */

    std::istringstream iss(line);
    vect_s split_vect{ std::istream_iterator<std::string>{iss},
                       std::istream_iterator<std::string>{}};

    /* logs for debugging
     * RCC::Log::load_log({RCC::LogLevel::INFO, line.c_str(), "splitting line"});
     *
     * for (ct_str_ref _ : split_vect) {
     *  RCC::Log::load_log({RCC::LogLevel::DEBUG, _.c_str(), "split token"});
     * }
     **/

    return split_vect;
}

#endif //RACCOONLANG_STRINGUTIL_H


