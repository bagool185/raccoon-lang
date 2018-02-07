//
// Created by bagool on 07/02/2018.
//
#include <algorithm>
#include <iostream>

#include "String.h"

using namespace RCC;

/* trim the left-hand side of a string */
void String::_ltrim(String &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}
/* trim the right-hand side of a string */
void String::_rtrim(String &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}
/* trim a string */
void String::trim() {
    _ltrim(*this);
    _rtrim(*this);
}

std::vector<String> String::split(const char delimiter) {
    String temp = *this;
    String token;
    std::vector<String> return_vect;
    size_t pos = 0;

    while ((pos = temp.find(delimiter)) != String::npos) {
        token = temp.substr(0, pos);
        return_vect.push_back(token);
        temp.erase(0, pos + 1);
    }

    return return_vect;
}