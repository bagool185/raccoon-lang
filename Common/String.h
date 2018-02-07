//
// Created by bagool on 07/02/2018.
//

#ifndef RACCOONLANG_STRING_H
#define RACCOONLANG_STRING_H
#include <string>
#include <vector>

namespace RCC {
    /* string with trim and split functionality */
    class String : public std::basic_string<char> {
        typedef std::basic_string<char> str;
        void _ltrim(String&);
        void _rtrim(String&);
    public:
        String() : str() {}
        explicit String(const char *s) : str(s) {}
        String(const char *s, size_t n) : str(s, n) {}
        String(size_t n, char c) : str(n, c) {}

        void trim();
        std::vector<String> split(char);

        explicit operator const char*() {
            return c_str();
        }
    };
}

#endif //RACCOONLANG_STRING_H
