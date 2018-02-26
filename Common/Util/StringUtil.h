//
// Created by bagool on 07/02/2018.
//

#ifndef RACCOONLANG_STRINGUTIL_H
#define RACCOONLANG_STRINGUTIL_H

#include <string>
#include <vector>
#include <algorithm>

#include "types.h"

/* trim the left-hand side of a string */
static inline void ltrim(str_ref s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}
/* trim the right-hand side of a string */
static inline void rtrim(str_ref s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}
/* trim a string */
static inline void trim(str_ref s) {
    ltrim(s);
    rtrim(s);
}
/* split a string by a given delimiter */
static inline vect_s split(str_ref s, const char delimiter=' ') {
    /**
     * @param s: string to be split
     * @param delimiter: delimiter by which the string will be split
     */
    vect_s split_vect;
    size_t pos = 0;
    std::string token;

    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        split_vect.push_back(token);
        s.erase(0, pos + 1);
    }

    return split_vect;
}

#endif //RACCOONLANG_STRINGUTIL_H


