
#ifndef CLI_HPP
#define CLI_HPP

#include <iostream>
#include "board.hpp"

class CLI
{
public:
    CLI();
    ~CLI();
    void printBoard();
    void clearScreen();
    void printTitle();
    void mainLoop();

private:
    Board * m_gameBoard;
    bool m_turnX;

};

#endif