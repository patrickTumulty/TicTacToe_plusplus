#include <iostream>
#include "board.hpp"
#include "cli.hpp"

int main()
{
    CLI * interface = new CLI();
    interface->mainLoop();
    // interface->clearScreen();
    // interface->printBoard();

    return 0;
}