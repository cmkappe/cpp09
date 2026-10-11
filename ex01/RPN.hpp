#pragma once

#include <string>

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
