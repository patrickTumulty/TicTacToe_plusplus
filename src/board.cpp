
#include <iostream>
#include "board.hpp"

Board::Board()
{
    this->newGameBoard();
}

Board::~Board()
{
    delete m_gameBoard;
}

void Board::newGameBoard()
{    
    const char boardSize = this->m_boardSize;
    this->m_gameBoard = new char *[boardSize]; 
    for (int i = 0; i < boardSize; i++)
        this->m_gameBoard[i] = new char [boardSize];
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            this->m_gameBoard[i][j] = ' ';
        }
    }
}

void Board::playX(int y, int x)
{
    this->m_gameBoard[y-1][x-1] = 'X';
}

void Board::playO(int y, int x)
{
    this->m_gameBoard[y-1][x-1] = 'O';
}

bool Board::XWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (
        this->m_gameBoard[i][0] == 'X' &&
        this->m_gameBoard[i][1] == 'X' &&
        this->m_gameBoard[i][2] == 'X'
        )
        {
            return true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (
        this->m_gameBoard[0][i] == 'X' &&
        this->m_gameBoard[1][i] == 'X' &&
        this->m_gameBoard[2][i] == 'X'
        )
        {
            return true;
        }
    }
    if (
    this->m_gameBoard[0][0] == 'X' &&
    this->m_gameBoard[1][1] == 'X' &&
    this->m_gameBoard[2][2] == 'X'
    )
    {
        return true;
    }
    else if (
    this->m_gameBoard[0][2] == 'X' &&
    this->m_gameBoard[1][1] == 'X' &&
    this->m_gameBoard[2][0] == 'X'
    )
    {
        return true;
    }
    return false;
}

bool Board::OWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (
        this->m_gameBoard[i][0] == 'O' &&
        this->m_gameBoard[i][1] == 'O' &&
        this->m_gameBoard[i][2] == 'O'
        )
        {
            return true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (
        this->m_gameBoard[0][i] == 'O' &&
        this->m_gameBoard[1][i] == 'O' &&
        this->m_gameBoard[2][i] == 'O'
        )
        {
            return true;
        }
    }
    if (
    this->m_gameBoard[0][0] == 'O' &&
    this->m_gameBoard[1][1] == 'O' &&
    this->m_gameBoard[2][2] == 'O'
    )
    {
        return true;
    }
    else if (
    this->m_gameBoard[0][2] == 'O' &&
    this->m_gameBoard[1][1] == 'O' &&
    this->m_gameBoard[2][0] == 'O'
    )
    {
        return true;
    }
    return false;
}

char ** Board::getBoard()
{
    return this->m_gameBoard;
}