#pragma once

#include <string>

static const char* RESET = "\033[0m";
// static const char* BOLD = "\033[1m";
// static const char* CYAN = "\033[36m";
// static const char* GREEN = "\033[32m";
static const char* RED = "\033[31m";
// static const char* YELLOW = "\033[33m";

class RPN {

    private:
        RPN(const std::string &str);
        RPN(const RPN &other) = delete;
        RPN operator=(const RPN &other) = delete;
    
    public:
        RPN();
        ~RPN();
        int calculate(const std::string &expression) const;

};
