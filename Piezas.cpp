#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    reset();
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    // 3 rows, 4 cols
    board.resize(3,std::vector<Piece>(4,Blank));
    turn = X;
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    turn = (turn==X)? O : X;

    if (column > 3)
        return Invalid;

    for (int i = 0; i < 3; i++)
    {
        Piece &p = board[i][column];
        if (p == Blank)
        {
            p = (turn==X)? O : X;
            return p;
        }
    }
    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if (row < 0 || row > 2)
        return Invalid;
    if (column < 0 || column > 3)
        return Invalid;
    return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    int xmax = 0;
    int omax = 0;

    for (int r = 0; r < 3; r++)
    {
        int xsum = 0;
        int osum = 0;
        for (int c = 0; c < 4; c++)
        {
            Piece &p = board[r][c];
            if (p==X)
                xsum++;
            if (p==O)
                osum++;
            if (p==Blank)
                return Invalid;
        }
        if (xsum>xmax)
            xmax = xsum;
        if (osum>omax)
            omax = osum;
    }

    for (int c = 0; c < 4; c++)
    {
        int xsum = 0;
        int osum = 0;
        for (int r = 0; r < 3; r++)
        {
            Piece &p = board[r][c];
            if (p==X)
                xsum++;
            if (p==O)
                osum++;
        }
        if (xsum>xmax)
            xmax = xsum;
        if (osum>omax)
            omax = osum;
    }

    if (xmax>omax)
        return X;
    if (omax>xmax)
        return O;
    return Blank;
}
