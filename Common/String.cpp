//
// Created by bagool on 07/02/2018.
//
#include <algorithm>

#include "String.h"

/* trim the left-hand side of a string */
static inline void String::_ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}
/* trim the right-hand side of a string */
static inline void String::_rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}
/* trim a string */
static inline void String::trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}