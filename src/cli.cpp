#include <iostream>
#include "cli.hpp"

CLI::CLI()
{
    this->m_gameBoard = new Board();
}

CLI::~CLI()
{
    delete m_gameBoard;
}

void CLI::printBoard()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == 0 && j == 0)
            {
                if (this->m_turnX)
                {
                    std::cout << " X";
                }
                else
                {
                    std::cout << " O";
                }
            }
            else if (i == 0)
            {
                std::cout << " | " << j;
            }
            else if (j == 0)
            {
                std::cout << " " << i;
            }
            else 
            {
                std::cout << " | " << this->m_gameBoard->getBoard()[i-1][j-1];
            }
        }
        if (i == 3)
        {
            std::cout << "\n";
        }
        else
        {
            std::cout << "\n---+---+---+---\n";
        }
        
    }
}

void CLI::clearScreen()
{
    for (int i = 0; i < 100; i++)
    {
        std::cout << '\n';
    }
}

void CLI::printTitle()
{
    std::cout << "   [ Tic Tac Toe ]  " << std::endl;
    std::cout << " O    X |   |      X" << std::endl;
    std::cout << " X   ---+---+---   O" << std::endl;
    std::cout << " O      | X |      X" << std::endl;
    std::cout << " X   ---+---+---   O" << std::endl;
    std::cout << " O      |   | X    X" << std::endl; 
    std::cout << "   [ Press Enter ]  " << std::endl;
    std::cin.get();  
}

void CLI::mainLoop()
{
    bool running = true;
    bool titleOnce = true;
    m_turnX = true;
    std::string UserInputX;
    std::string UserInputY;
    while (running)
    {
        this->clearScreen();
        if (titleOnce)
        {
            this->printTitle();
            titleOnce = false;
            this->clearScreen();
        }
        this->printBoard();
        std::cout << "Enter Y coordinate : ";
        std::cin >> UserInputY;
        std::cout << "Enter X coordinate : ";
        std::cin >> UserInputX;
        if (this->m_turnX)
        {
            this->m_gameBoard->playX(std::stoi(UserInputY), std::stoi(UserInputX));
            this->m_turnX = false;
        }
        else
        {
            this->m_gameBoard->playO(std::stoi(UserInputY), std::stoi(UserInputX));
            this->m_turnX = true;
        }
        if (this->m_gameBoard->XWin() == true)
        {
            this->clearScreen();
            running = false;
            std::cout << "!!! WINNER X !!!" << std::endl;
        }
        else if (this->m_gameBoard->OWin() == true)
        {
            this->clearScreen();
            running = false;
            std::cout << "!!! WINNER O !!!" << std::endl;
        }
    }
}