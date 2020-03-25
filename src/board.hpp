
#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
public:
    Board();
    ~Board();

    void newGameBoard();
    void playX(int y, int x);
    void playO(int y, int x);
    bool placeAvailable(int y, int x);
    char ** getBoard();
    const char getBoardSize();
    bool XWin();
    bool OWin();

private:
    char ** m_gameBoard;
    const char m_boardSize = 3;

};

#endif