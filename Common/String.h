//
// Created by bagool on 07/02/2018.
//

#ifndef RACCOONLANG_STRING_H
#define RACCOONLANG_STRING_H
#include <string>

class String {
    static inline void _ltrim(std::string&);
    static inline void _rtrim(std::string&);
    // prevent the creation of default constructor
    String() {}
public:
    static void trim(std::string &s);
};


#endif //RACCOONLANG_STRING_H
