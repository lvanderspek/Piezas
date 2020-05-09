/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}


/* test the reset function */









/* test the dropPiece function */

// single drop
TEST(PiezasTest, singleDrop)
{
    Piezas p;
    Piece piece = p.dropPiece(0);
    ASSERT_TRUE(piece==X);
}

// double drop
TEST(PiezasTest, doubleDrop)
{
    Piezas p;
    p.dropPiece(0);
    Piece piece = p.dropPiece(0);
    ASSERT_TRUE(piece==O);
}

// dual column double drop
TEST(PiezasTest, dualColumnDoubleDrop)
{
    Piezas p;
    p.dropPiece(0);
    Piece piece = p.dropPiece(1);
    ASSERT_TRUE(piece==O);
}

// triple drop
TEST(PiezasTest, tripleDrop)
{
    Piezas p;
    p.dropPiece(0);
    p.dropPiece(0);
    Piece piece = p.dropPiece(0);
    ASSERT_TRUE(piece==X);
}

// dual column triple drop
TEST(PiezasTest, dualColumnTripleDrop)
{
    Piezas p;
    p.dropPiece(0);
    p.dropPiece(1);
    Piece piece = p.dropPiece(0);
    ASSERT_TRUE(piece==X);
}

// out of bounds
TEST(PiezasTest, outOfBounds)
{
    Piezas p;
    Piece piece = p.dropPiece(4);
    ASSERT_TRUE(piece==Invalid);
}

// full column
TEST(PiezasTest, fullColumn)
{
    Piezas p;
    p.dropPiece(0);
    p.dropPiece(0);
    p.dropPiece(0);
    Piece piece = p.dropPiece(0);
    ASSERT_TRUE(piece==Blank);
}










/* test the pieceAt function */











/* test the gameState function */









