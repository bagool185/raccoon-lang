# cmake_minimum_required(VERSION <specify CMake version here>)
project(RaccoonLang)

set(CMAKE_CXX_STANDARD 17)

add_executable(RaccoonLang main.cpp TrashPanda/Token.cpp TrashPanda/Token.h TrashPanda/Lexer.cpp TrashPanda/Lexer.h Common/String.cpp Common/String.h Tests/StringTest.h Common/Util/StringUtil.h)