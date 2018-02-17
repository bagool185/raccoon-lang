//
// Created by bagool on 07/02/2018.
//

#ifndef RACCOONLANG_TOKEN_H
#define RACCOONLANG_TOKEN_H

#include <string>
#include <regex>
#include <map>

namespace RCC {

    typedef const std::string ct_str;

    enum class OperatorTypes {
        // unary
        OT_INCREMENT, // ++
        OT_DECREMENT, // --
        OT_LSHIFT,    // <<
        OT_RSHIFT,    // >>
        // binary
        OT_PLUS,      // +
        OT_MINUS,     // -
        OT_DIV,       // / (division)
        OT_MULT,      // * (multiplication)
        OT_MOD,       // % (modulo)
        OT_ASSIGN,    // =
        // logical
        OT_GT,        // > (greater than)
        OT_GTET,      // >= (greater than or equal to)
        OT_LT,        // < (lesser than)
        OT_LTET,      // <= (lesser than or equal to)
        // braces
        OT_CURLY_OPEN,  // {
        OT_CURLY_CLOSE, // }
        OT_ROUND_OPEN,  // (
        OT_ROUND_CLOSE, // )
        // punctuation
        OT_EOS,         // ; (end of statement)
        OT_COMMA        // ,
    };

    enum class KeywordTypes {
        KT_DECL,	// let - declaration
        KT_FUNC,	// function
        KT_IF,		// if statement
        KT_WHILE,	// while statement
        KT_TRUE,	// true (1)
        KT_FALSE    // false (0)
    };

    enum class LiteralTypes {
        LT_ID,  // user defined identifier
        LT_STR, // string literal
        LT_INT, // integer literal
        LT_DEC  // decimal literal
    };
    /* comparator for std::map */
    struct comparator {
        bool operator() (ct_str& x, ct_str& y) const {
            return x < y;
        }
    };

    const std::map<ct_str, const OperatorTypes, comparator> mapped_operators {
        // unary
        { "++", OperatorTypes::OT_INCREMENT },    // ++
        { "--", OperatorTypes::OT_DECREMENT },    // --
        { "<<", OperatorTypes::OT_LSHIFT    },    // <<
        { ">>", OperatorTypes::OT_RSHIFT    },    // >>
        // binary
        { "+", OperatorTypes::OT_PLUS   },     // +
        { "-", OperatorTypes::OT_MINUS  },     // -
        { "/", OperatorTypes::OT_DIV    },     // / (division)
        { "*", OperatorTypes::OT_MULT   },     // * (multiplication)
        { "%", OperatorTypes::OT_MOD    },     // % (modulo)
        { "=", OperatorTypes::OT_ASSIGN },	   // =
        // logical
        { ">" , OperatorTypes::OT_GT   },    // > (greater than)
        { ">=", OperatorTypes::OT_GTET },	 // >= (greater than or equal to)
        { "<",  OperatorTypes::OT_LT   },    // < (lesser than)
        { "<=", OperatorTypes::OT_LTET },	 // <= (lesser than or equal to)
        // braces
        { "{", OperatorTypes::OT_CURLY_OPEN  },   // {
        { "}", OperatorTypes::OT_CURLY_CLOSE },   // }
        { "(", OperatorTypes::OT_ROUND_OPEN  },   // (
        { ")", OperatorTypes::OT_ROUND_CLOSE },   // )
        // punctuation
        { ";",  OperatorTypes::OT_EOS   },	    // ; (end of statement)
        { ",",  OperatorTypes::OT_COMMA },	    // ,
    };

    const std::map<ct_str, const KeywordTypes, comparator> mapped_keywords {
        { "let",      KeywordTypes::KT_DECL  },	 // let - declaration
        { "function", KeywordTypes::KT_FUNC  },	 // function
        { "if",       KeywordTypes::KT_IF	 },  // if statement
        { "while",    KeywordTypes::KT_WHILE },	 // while statement
        { "true",     KeywordTypes::KT_TRUE  },  // true
        { "false",    KeywordTypes::KT_FALSE }   // false
    };

    const std::regex decimal_literals("[0-9]*\\.?[0-9]+");
    const std::regex integer_literals("d+");
    const std::regex string_literal("\"\w+\"");
    const std::regex identifier_literal("(([A-Z]|[a-z]|_)([A-Z]|[0-9]|[a-z]|_)?)+");

    union TokenType {
        OperatorTypes operator_;
        KeywordTypes keyword_;
        LiteralTypes literal_;
    };

    class Token {
        // prevent the creation of default constructor
        Token() = default;
        // the token type and name will be set by the constructor
        std::string _token_name = "";
        TokenType _token_type;
    public:
        explicit Token(ct_str& token_type);
        const std::string get_token_name() { return _token_name; }
        const TokenType get_token_type() { return _token_type; }
        inline bool is_set();
        void print();
    };

}

#endif //RACCOONLANG_TOKEN_H
