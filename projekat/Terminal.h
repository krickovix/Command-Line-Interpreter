#ifndef PROJEKAT_TERMINAL_H
#define PROJEKAT_TERMINAL_H

#include <iostream>

class Terminal{
public:
    static Terminal* Instance();

    [[noreturn]] void run();

    void setReadySign(std::string sign);
protected:
    Terminal();
private:
    std::string readySign;
};
inline Terminal::Terminal(): readySign("$") {}

#endif //PROJEKAT_TERMINAL_H
