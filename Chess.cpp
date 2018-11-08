// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Windows.h"
using namespace std;



class ChessPiece
{
protected:

	//MOVES* movementArray;


public:
	bool isValid;
	bool has_moved;
	virtual bool isValidMove()
	{
		return isValid;
	}
	virtual void setisValid(bool titty)
	{
		isValid = titty;
	}
	ChessPiece **board;
	char color;
	string name;
	pair <int,int>location;
	char symbol;
	ChessPiece()
	{
		symbol = 'x';
		name = "bullshit";
		location = make_pair(-1,-1);
		color = '=';
		setisValid(true);

	}
	ChessPiece(string Name, char Color, pair<int,int> loc)
		:name(Name),color(Color),location(loc)
	{
		symbol = 'x';
		setisValid(true);
	}

	virtual pair<char,char> draw()
	{
		return make_pair(color,symbol) ;
	}
	virtual char getColor()
	{
		return color;
	}
	virtual pair<int,int> getLocation()
	{
		return location;
	}
	virtual void setLocation(pair<int,int> newLoc)
	{
		location = newLoc;
	}
	virtual string getName()
	{

		return name;
	}
	virtual pair<int,int> moveLEFT(pair<int,int> cords,int i =1)
	{
		return make_pair(cords.first, cords.second-i);
	}
	virtual pair<int,int> moveRIGHT(pair<int,int> cords,int i =1)
	{
		return make_pair(cords.first, cords.second+i);
	}
	virtual pair<int,int> moveUP(pair<int,int> cords,int i =1)
	{
		return make_pair(cords.first+i, cords.second);
	}
	virtual pair<int,int> moveDOWN(pair<int,int> cords,int i =1)
	{
		return make_pair(cords.first-i, cords.second);
	}
	virtual pair<int,int> moveUPLEFT(pair<int,int> cords,int i =1)
	{
		return make_pair(cords.first+i, cords.second-i);
	}
	virtual pair<int,int> moveUPRIGHT(pair<int,int> cords,int i =1)
	{
		return make_pair(cords.first+i, cords.second+i);
	}
	virtual pair<int,int> moveDOWNLEFT(pair<int,int> cords,int i =1)
	{
		return make_pair(cords.first-i, cords.second-i);
	}
	virtual pair<int,int> moveDOWNRIGHT(pair<int,int> cords,int i =1)
	{
		return make_pair(cords.first-i, cords.second+i);
	}

	virtual pair<int,int> move1(ChessPiece *** board,int i = 0){return make_pair(-1,8);}
	virtual pair<int,int> move2(ChessPiece *** board,int i = 0){return make_pair(-1,8);}
	virtual pair<int,int> move3(ChessPiece *** board,int i = 0){return make_pair(-1,8);}
	virtual pair<int,int> move4(ChessPiece *** board,int i = 0){return make_pair(-1,8);}
	virtual pair<int,int> move5(ChessPiece *** board,int i = 0){return make_pair(-1,8);}
	virtual pair<int,int> move6(ChessPiece *** board,int i = 0){return make_pair(-1,8);}
	virtual pair<int,int> move7(ChessPiece *** board,int i = 0){return make_pair(-1,8);}
	virtual pair<int,int> move8(ChessPiece *** board,int i = 0){return make_pair(-1,8);}


	virtual pair<int,int> move1(){return make_pair(-1,8);}
	virtual pair<int,int> move2(){return make_pair(-1,8);}
	virtual pair<int,int> move3(){return make_pair(-1,8);}
	virtual pair<int,int> move4(){return make_pair(-1,8);}
	virtual pair<int,int> move5(){return make_pair(-1,8);}
	virtual pair<int,int> move6(){return make_pair(-1,8);}
	virtual pair<int,int> move7(){return make_pair(-1,8);}
	virtual pair<int,int> move8(){return make_pair(-1,8);}

	virtual void cpy(ChessPiece& cpp, ChessPiece& cp)
	{
		cpp.name = cp.name;
		cpp.color = cp.color;
		cpp.symbol = cp.symbol;
		cpp.location = cp.location;
	}
	virtual bool checkMove(ChessPiece*** board, pair<int,int> move)
	{
		return true;
	}
	~ChessPiece()
	{
	}
};

class Knight :public ChessPiece
{
public:

	Knight(){}
	Knight(string Name, char color, pair<int,int> loc) :ChessPiece(Name,color,loc)

	{
		symbol = 'k';
	}
	pair <int,int> move1()override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveUPRIGHT(moveUP(loc));
	}
	pair <int,int> move2()override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveUPLEFT(moveUP(loc));
	}
	pair <int,int> move3()override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveUPRIGHT(moveRIGHT(loc));
	}
	pair <int,int> move4()override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveUPLEFT(moveLEFT(loc));
	}
	pair <int,int> move5()override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveDOWNRIGHT(moveDOWN(loc));
	}
	pair <int,int> move6()override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveDOWNLEFT(moveDOWN(loc));
	}
	pair <int,int> move7()override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveDOWNRIGHT(moveRIGHT(loc));
	}
	pair <int,int> move8()override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveDOWNLEFT(moveLEFT(loc));
	}
	virtual bool checkMove(ChessPiece*** board,pair<int,int> move)override
	{

		if (board[move.first][move.second]->symbol == '=')
			return true;
		if ((board[move.first][move.second]->color != color)&&board[move.first][move.second]->symbol!= 'x')
			return true;
		else
			return false;
	}

};
class Rook :public ChessPiece
{
public:
	Rook(){}
	Rook(string Name,char color, pair<int,int> loc) :ChessPiece(Name,color,loc)

	{
		symbol = 'R';
	}



	virtual pair <int,int> move1(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{

			pair<int,int> move = moveUP(loc,i);


			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{}
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveUP(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveUP(loc,magnitude);
	}
	virtual pair <int,int> move2(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{
			pair<int,int> move = moveDOWN(loc,i);

			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{

			}
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveDOWN(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveDOWN(loc,magnitude);
	}
	virtual pair <int,int> move3(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{
			pair<int,int> move = moveLEFT(loc,i);

			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{}
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveLEFT(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveLEFT(loc,magnitude);
	}
	virtual pair <int,int> move4(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{
			pair<int,int> move = moveRIGHT(loc,i);

			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{}
			// checks if theres a piece in the way of the opposite color then returns that location
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveRIGHT(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveRIGHT(loc,magnitude);
	}
	virtual bool checkMove(ChessPiece*** board,pair<int,int> move)override
	{
		return true;
	}
	~Rook()
	{
	}
};
class King :public ChessPiece
{
public:
	King(){}
	King(string Name,char color, pair<int,int> loc) :ChessPiece(Name,color,loc)

	{
		symbol = 'K';
	}

	pair <int,int> move1()
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveUP(loc);
	}
	pair <int,int> move2()
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveDOWN(loc);
	}
	pair <int,int> move3()
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveLEFT(loc);
	}
	pair <int,int> move4()
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveRIGHT(loc);
	}
	pair <int,int> move5()
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveUPLEFT(loc);
	}
	pair <int,int> move6()
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveUPRIGHT(loc);
	}
	pair <int,int> move7()
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveDOWNLEFT(loc);
	}
	pair <int,int> move8()
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		return moveDOWNRIGHT(loc);
	}
	virtual bool checkMove(ChessPiece*** board,pair<int,int> move)override
	{

		if (board[move.first][move.second]->symbol == '='&&(board[move.first][move.second]->color != color)&&board[move.first][move.second]->symbol!= 'x')
			return true;
		if (board[move.first][move.second]->symbol != '='&&(board[move.first][move.second]->color != color)&&board[move.first][move.second]->symbol!= 'x')
			return true;
		else
			return false;
	}
	~King()
	{
	}
};
class Queen :public ChessPiece
{
public:
	Queen(){}
	Queen(string Name,char color, pair<int,int> loc) :ChessPiece(Name,color,loc)

	{
		symbol = 'Q';
	}
	virtual pair <int,int> move1(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{

			pair<int,int> move = moveUP(loc,i);


			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{}
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveUP(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveUP(loc,magnitude);
	}
	virtual pair <int,int> move2(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{
			pair<int,int> move = moveDOWN(loc,i);

			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{

			}
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveDOWN(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveDOWN(loc,magnitude);
	}
	virtual pair <int,int> move3(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{
			pair<int,int> move = moveLEFT(loc,i);

			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{}
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveLEFT(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveLEFT(loc,magnitude);
	}
	virtual pair <int,int> move4(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{
			pair<int,int> move = moveRIGHT(loc,i);

			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{}
			// checks if theres a piece in the way of the opposite color then returns that location
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveRIGHT(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveRIGHT(loc,magnitude);
	}
	virtual pair <int,int> move5(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{

			pair<int,int> move = moveDOWNRIGHT(loc,i);


			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{}
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveDOWNRIGHT(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveDOWNRIGHT(loc,magnitude);
	}
	virtual pair <int,int> move6(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{
			pair<int,int> move = moveDOWNLEFT(loc,i);

			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{

			}
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveDOWNLEFT(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveDOWNLEFT(loc,magnitude);
	}
	virtual pair <int,int> move7(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{
			pair<int,int> move = moveUPLEFT(loc,i);

			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{}
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveUPLEFT(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveUPLEFT(loc,magnitude);
	}
	virtual pair <int,int> move8(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{
			pair<int,int> move = moveUPRIGHT(loc,i);

			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{}
			// checks if theres a piece in the way of the opposite color then returns that location
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveUPRIGHT(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveUPRIGHT(loc,magnitude);
	}
	virtual bool checkMove(ChessPiece*** board,pair<int,int> move)override
	{
		return true;
	}
	~Queen()
	{
	}

};
class Bishop :public ChessPiece
{
public:
	Bishop(){}
	Bishop(string Name,char color, pair<int,int> loc) :ChessPiece(Name,color,loc)

	{
		symbol = 'B';
	}

	virtual pair <int,int> move1(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{

			pair<int,int> move = moveDOWNRIGHT(loc,i);


			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{}
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveDOWNRIGHT(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveDOWNRIGHT(loc,magnitude);
	}
	virtual pair <int,int> move2(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{
			pair<int,int> move = moveDOWNLEFT(loc,i);

			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{

			}
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveDOWNLEFT(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveDOWNLEFT(loc,magnitude);
	}
	virtual pair <int,int> move3(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{
			pair<int,int> move = moveUPLEFT(loc,i);

			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{}
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveUPLEFT(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveUPLEFT(loc,magnitude);
	}
	virtual pair <int,int> move4(ChessPiece*** board,int magnitude)override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		for (int i = 1; i <=magnitude; i++)
		{
			pair<int,int> move = moveUPRIGHT(loc,i);

			if (board[move.first][move.second]->symbol == '='&&board[move.first][move.second]->symbol != 'x')
			{}
			// checks if theres a piece in the way of the opposite color then returns that location
			else if (board[move.first][move.second]->symbol != '=' && board[move.first][move.second]->color != color&&board[move.first][move.second]->symbol != 'x')
			{
				//setisValid(true);
				return moveUPRIGHT(loc,i);
			}
			else
			{
				//setisValid(false);
				return make_pair(-1,-1);
			}
		}
		//setisValid(true);
		return moveUPRIGHT(loc,magnitude);
	}

	virtual bool checkMove(ChessPiece*** board,pair<int,int> move)override
	{
		return true;
	}
	~Bishop()
	{
	}

};
class Pawn :public ChessPiece
{
public:
	
	Pawn(){}

	Pawn(string Name,char color, pair<int,int> loc) :ChessPiece(Name,color,loc)

	{
		has_moved = false;
		symbol = 'P';
	}

	pair <int,int> move1()override
	{

		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		if (this->color == '+')
		{
		
			return moveDOWN(loc);
		}
		else
		{
		
			return moveUP(loc);
		}

	}
	pair <int,int> move2()override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		if (!has_moved)
		{

		if (this->color == '+')
		{
			
			return moveDOWN(loc,2);
		}
		else
		{
	
			return moveUP(loc,2);
		}
		}
		else
		{
			return make_pair(-1,-1);
		}
	}
	pair <int,int> move3()override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		if (this->color == '+')
		{

			return moveDOWN(moveLEFT(loc));
		}
		else
		{
	
			return moveUP(moveLEFT(loc));
		}
	}
	pair <int,int> move4()override
	{
		int x,y;
		pair<int,int> loc = getLocation();
		y = loc.first;
		x =loc.second;
		if (this->color == '+')
		{

			return moveDOWN(moveRIGHT(loc));
		}
		else
		{
			
			return moveUP(moveRIGHT(loc));
		}
	}

	virtual bool checkMove(ChessPiece*** board,pair<int,int> move)override
	{
		if (move == make_pair(-1,-1))
			return false;
		if ((move == move3() )&&(board[move.first][move.second]->color != color)&&(board[move.first][move.second]->symbol!='='))
			return true;
		if ((move == move4() )&&(board[move.first][move.second]->color != color)&&(board[move.first][move.second]->symbol!='='))
			return true;
		if (( move == move2())&&(board[move.first][move.second]->symbol=='='))
			return true;
		if (( move == move1())&&(board[move.first][move.second]->symbol=='='))
			return true;
		else
			return false;
	}
	~Pawn()
	{
	}

};
class Empty :public ChessPiece
{
public:

	Empty(string Name,char color, pair<int,int> loc) :ChessPiece(Name,color,loc)
	{
		symbol = '=';
	}
	Empty() :ChessPiece()

	{
		symbol = '=';
	}
	~Empty()
	{
	}

};
class Check :public ChessPiece
{
	public:

		Check(string Name, char color, pair<int, int> loc) :ChessPiece(Name, color, loc)
		{
			symbol = 'C';
		}
		Check() :ChessPiece()

		{
			symbol = 'C';
		}
		~Check()
		{
		}

};
class ChessGame
{
private:
	bool gameWon;
	ChessPiece*** board;
	char* piecesLeft;
	char* piecesTaken;
	bool checkMate;
	char currentPlayer;
	bool inCheck;
	int checkmate;
	ChessPiece* blackPieces[16];
	ChessPiece* whitePieces[16];
public:

	ChessGame() :CP(), bp1("bp1", '-',make_pair(3,2)), bp2("bp2",'-',make_pair(3,3)), bp3("bp3", '-',make_pair(3,4)), bp4("bp4",'-',make_pair(3,5)), bp5("bp5",'-',make_pair(3,6)), bp6("bp6",'-',make_pair(3,7)), bp7("bp7",'-',make_pair(3,8)), bp8("bp8", '-',make_pair(3,9)), bK("bK", '-',make_pair(2,6)),bk1("bk1", '-',make_pair(2,8)), bk("bk", '-',make_pair(2,3)), bQ("bQ",'-',make_pair(2,5)), bB1("bB1",'-',make_pair(2,7)), bB("bB",'-',make_pair(2,4)), bR("bR",'-',make_pair(2,2)), bR1("bR1",'-',make_pair(2,9)),
		wp1("wp1", '+',make_pair(8,2)), wp2("wp2",'+',make_pair(8,3)), wp3("wp3", '+',make_pair(8,4)), wp4("wp4",'+',make_pair(8,5)), wp5("wp5",'+',make_pair(8,6)), wp6("wp6",'+',make_pair(8,7)), wp7("wp7",'+',make_pair(8,8)), wp8("wp8", '+',make_pair(8,9)), wK("wK", '+',make_pair(9,6)),wk1("wk1", '+',make_pair(9,8)), wk("wk", '+',make_pair(9,3)), wQ("wQ",'+',make_pair(9,5)), wB1("wB1",'+',make_pair(9,7)), wB("wB",'+',make_pair(9,4)), wR("wR",'+',make_pair(9,2)), wR1("wR1",'+',make_pair(9,9)), E("E",'=',make_pair(-1,-1)), C("C",'=',make_pair(-1,-1))
	{
		inCheck = false;
		gameWon = false;
		currentPlayer = '+';
		board = createBoard();
		blackPieces[0] = &bp1; blackPieces[1] = &bp2; blackPieces[2] = &bp3; blackPieces[3] = &bp4; blackPieces[4] = &bp5; blackPieces[5] = &bp6; blackPieces[6] = &bp7; blackPieces[7] = &bp8; blackPieces[8] = &bB; blackPieces[9] = &bB1; blackPieces[10] = &bR; blackPieces[11] = &bR1; blackPieces[12] = &bk; blackPieces[13] = &bk1; blackPieces[14] = &bK; blackPieces[15] = &bQ;
		whitePieces[0] = &wp1; whitePieces[1] = &wp2; whitePieces[2] = &wp3; whitePieces[3] = &wp4; whitePieces[4] = &wp5; whitePieces[5] = &wp6; whitePieces[6] = &wp7; whitePieces[7] = &wp8; whitePieces[8] = &wB; whitePieces[9] = &wB1; whitePieces[10] = &wR; whitePieces[11] = &wR1; whitePieces[12] = &wk; whitePieces[13] = &wk1; whitePieces[14] = &wK; whitePieces[15] = &wQ;
	}
	void switchPlayer()
	{
		if(currentPlayer == '-')
		{
			currentPlayer = '+';
		}
		else
		{
			currentPlayer = '-';
		}
	}
	char oppositePlayer()
	{
		if(currentPlayer == '-')
		{
			return '+';
		}
		else
		{
			return '-';
		}
	}
	//piece initialized
	Pawn bp1; Pawn bp2;Pawn bp3; Pawn bp4; Pawn bp5; Pawn bp6; Pawn bp7; Pawn bp8; Pawn wp1; Pawn wp2; Pawn wp3; Pawn wp4; Pawn wp5; Pawn wp6; Pawn wp7; Pawn wp8; 
	King wK;King bK;
	Queen bQ;Queen wQ;
	Bishop bB;Bishop bB1;Bishop wB;Bishop wB1;
	Rook bR;Rook bR1;Rook wR;Rook wR1;
	Knight bk;Knight bk1;Knight wk;Knight wk1;
	Empty E;
	Check C;
	ChessPiece CP;

	int GetAnyInput()
	{
		int thisinput = -1;
		while (thisinput == -1)	// Wait till users presses 1-9
		{
			if (GetAsyncKeyState('1') || GetAsyncKeyState(VK_NUMPAD1))
				thisinput = 1;
			else if (GetAsyncKeyState('2') || GetAsyncKeyState(VK_NUMPAD2))
				thisinput = 2;
			else if (GetAsyncKeyState('3') || GetAsyncKeyState(VK_NUMPAD3))
				thisinput = 3;
			else if (GetAsyncKeyState('4') || GetAsyncKeyState(VK_NUMPAD4))
				thisinput = 4;
			else if (GetAsyncKeyState('5') || GetAsyncKeyState(VK_NUMPAD5))
				thisinput = 5;
			else if (GetAsyncKeyState('6') || GetAsyncKeyState(VK_NUMPAD6))
				thisinput = 6;
			else if (GetAsyncKeyState('7') || GetAsyncKeyState(VK_NUMPAD7))
				thisinput = 7;
			else if (GetAsyncKeyState('8') || GetAsyncKeyState(VK_NUMPAD8))
				thisinput = 8;
			else if (GetAsyncKeyState('9') || GetAsyncKeyState(VK_NUMPAD9))
				thisinput = 9;
		}

		while (GetAsyncKeyState('0' + thisinput) || GetAsyncKeyState(VK_NUMPAD0 + thisinput))	// wait till they release it before continuing.
		{
			Sleep(1);
		};

		return thisinput;
	}
	int GetNumInput()
	{
		int input = -1;
		while (input < 0 || input >8)	// Wait till users presses 1-9
		{
			cin >> input;
		}
		if(input == 0)
		{
			DrawBoard();
			PlayTurn();
		}
		else
		{
		cout << "									    			  input accepted: " << input<<endl;
		return input;
		}

	}
	pair <int,int> GetInput()

	{
		int row,col;
		cout <<"									    		    choose row 1-8 or 0 to cancel"<<endl;
		row =GetNumInput() + 1;
		cout <<"											    choose col 1-8 or 0 to cancel"<<endl;
		col = GetNumInput() + 1;
		return make_pair(row,col);
	}

	ChessPiece*** createBoard()
	{
		ChessPiece*** board = new ChessPiece**[12];

		for (int i = 0; i < 12; i++)
		{
			board[i] = new ChessPiece*[12];

			for (int j = 0; j < 12; j++)
			{
				board[i][j] = &E;
			}
		}

		board[2][2] = &bR; board[2][2+1] = &bk; board[2][2+2] = &bB; board[2][2+3] = &bQ; board[2][2+4] = &bK; board[2][2+5] = &bB1; board[2][2+6] = &bk1; board[2][2+7] = &bR1; 
		board[2+6][2] = &wp1; board[2+6][2+1] = &wp2; board[2+6][2+2] = &wp3; board[2+6][2+3] = &wp4; board[2+6][2+4] = &wp5; board[2+6][2+5] = &wp6; board[2+6][2+6] = &wp7; board[2+6][2+7] = &wp8; 
		board[3][2] = &bp1; board[3][2+1] = &bp2; board[3][2+2] = &bp3; board[3][2+3] = &bp4; board[3][2+4] = &bp5; board[3][2+5] = &bp6; board[3][2+6] = &bp7; board[3][2+7] = &bp8; 
		board[3+6][2] = &wR; board[3+6][2+1] = &wk; board[3+6][2+2] = &wB; board[3+6][2+3] = &wQ; board[3+6][2+4] = &wK; board[3+6][2+5] = &wB1; board[3+6][2+6] = &wk1; board[3+6][2+7] = &wR1; 
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				board[i][j] = &CP;
			}
		}
		for (int i = 10; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				board[i][j] = &CP;
			}
		}
		for (int i = 2; i < 10; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				board[i][j] = &CP;
			}
		}
		for (int i = 2; i < 10; i++)
		{
			for (int j = 10; j < 12; j++)
			{
				board[i][j] = &CP;
			}
		}
		return board;
	}
	bool isWinner(pair<int,int> move, ChessPiece *cp)
	{
		if (board[move.first][move.second]->symbol == 'K')
		{
			return true;
		}
		else
			return false;
	}

	string getPlayerTurn()
	{
		if (currentPlayer == '-')
			return "Black";
		else
			return "White";
	}
	bool Update()
	{
		DrawBoard();
		cout << "									    			It is ( "<< getPlayerTurn() << " )'s turn."<<endl;
		if(inCheck)
		{
			cout << "       									    			  You are in check, enter 1 to play, or 0 if you are in Checkmate" <<endl;
			cin >> checkmate;
			if (checkmate == 1)
			{
				PlayTurn();
			}
			else if (checkmate == 0)
			{
				switchPlayer();
				inCheck = false;
				return false;
			}
		}
		else
		{
			PlayTurn();
		}
		if(gameWon)
		{
			cout << "												winner";
			GetAnyInput();
			return true;
		}
		else
		{
			switchPlayer();
			return false;
		}
	}

	void cpy(ChessPiece* cpp, ChessPiece* cp)
	{
		cpp->name = cp->name;
		cpp->color = cp->color;
		cpp->symbol = cp->symbol;
		cpp->location = cp->location;
	}

	void DrawBoard()
	{
		printf(     "			      			      			         1      2      3      4      5      6      7      8    \n");
		for (int i = 2; i < 10; i++)
		{
			int j = 2;
			cout << "			      			      			      +=======================================================+"<<endl;
			cout << "			      			      			      |      |      |      |      |      |      |      |      |"<<endl;

			printf( "			      			      			    %d |  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |\n",i-1,board[i][j]->draw().first, board[i][j]->draw().second, board[i][j+1]->draw().first,board[i][j+1]->draw().second,board[i][j+2]->draw().first,board[i][j+2]->draw().second,board[i][j+3]->draw().first,board[i][j+3]->draw().second,board[i][j+4]->draw().first,board[i][j+4]->draw().second,board[i][j+5]->draw().first,board[i][j+5]->draw().second,board[i][j+6]->draw().first,board[i][j+6]->draw().second,board[i][j+7]->draw().first,board[i][j+7]->draw().second);
			cout << "			      			      			      |      |      |      |      |      |      |      |      |"<<endl;
		}
		cout <<     "			      			      			      +=======================================================+"<<endl;
	}
	void DrawBoard(ChessPiece ***board)
	{
		printf(     "			      			      			         1      2      3      4      5      6      7      8    \n");
		for (int i = 2; i < 10; i++)
		{
			int j = 2;
			cout << "			      			      			      +=======================================================+"<<endl;
			cout << "			      			      			      |      |      |      |      |      |      |      |      |"<<endl;

			printf( "			      			      			    %d |  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |  %c%c  |\n",i-1,board[i][j]->draw().first, board[i][j]->draw().second, board[i][j+1]->draw().first,board[i][j+1]->draw().second,board[i][j+2]->draw().first,board[i][j+2]->draw().second,board[i][j+3]->draw().first,board[i][j+3]->draw().second,board[i][j+4]->draw().first,board[i][j+4]->draw().second,board[i][j+5]->draw().first,board[i][j+5]->draw().second,board[i][j+6]->draw().first,board[i][j+6]->draw().second,board[i][j+7]->draw().first,board[i][j+7]->draw().second);
			cout << "			      			      			      |      |      |      |      |      |      |      |      |"<<endl;
		}
		cout << "				      			      		      +=======================================================+"<<endl;
	}

	pair<int,int> getPiece()
	{
		cout << "									    		       choose a piece position: "<<endl;
		pair<int,int> piece;
		piece= GetInput();
		if(board[piece.first][piece.second]->color != currentPlayer)
		{
			cout<< "								   		   Invalid space selected, please select another"<<endl;
			DrawBoard();
			piece = getPiece();
		}
		else
		{

		}

		return piece;
	}
	pair<int,int> getMove()
	{
		cout << "										     					          choose a move position: "<<endl;
		pair<int,int> move;
		move = GetInput();
		return move;
	}

	ChessPiece* setEqual(ChessPiece *cp)
	{
		if (cp->symbol == 'P')
		{
			Pawn p; 
			cpy(&p,cp);

			return &p;
		}
		if (cp->symbol == 'K')
		{
			King p; 
			cpy(&p,cp);

			return &p;
		}
		if (cp->symbol == 'k')
		{
			Knight p; 
			cpy(&p,cp);

			return &p;
		}
		if (cp->symbol == 'R')
		{
			Rook p; 
			cpy(&p,cp);

			return &p;
		}
		if (cp->symbol == 'B')
		{
			Bishop p; 
			cpy(&p,cp);

			return &p;
		}
		if (cp->symbol == 'Q')
		{
			Queen p; 
			cpy(&p,cp);

			return &p;
		}
		if (cp->symbol == '-')
		{
			Empty p; 
			cpy(&p,cp);

			return &p;
		}
	}
	ChessPiece*** createBoardCpy()
	{
		ChessPiece*** tempBoard = new ChessPiece**[12];
		for (int i = 0; i < 12; i++)
		{
			tempBoard[i] = new ChessPiece*[12];
			for (int j = 0; j < 12; j++)
			{
				auto New = new ChessPiece();
				tempBoard[i][j] = New;
				New->color = board[i][j]->color;
				New->symbol = board[i][j]->symbol;
				New->name = board[i][j]->name;
				New->location = board[i][j]->location;
			}
		}
		return tempBoard;
	}

	void PlayTurn()
	{
		bool noValidMoves = true;
		pair<int,int> piece = getPiece();
		ChessPiece *cp =board[piece.first][piece.second];
		//creates a tempboard
		ChessPiece*** tempBoard = createBoardCpy();
		int i=0;
		//asks user for distance inpput if their piece is Q,R, or B
		int distanceToMove= 10;
		pair<int,int>* arr = new pair<int,int>[8];
		
		//initializes array to (-1,-1)
		for (int i = 0; i < 8; i++)
		{
			arr[i] = make_pair(-1,-1);
		}
		
		if (cp->symbol == 'R' || cp->symbol == 'Q' || cp->symbol == 'B')
		{
			while (noValidMoves)
			{
				distanceToMove = -1;
				while ((distanceToMove > 7) || (distanceToMove < 0))
				{
					cout << "							        Choose how many spaces, 1-7, you'd like to move your " << cp->symbol << " or enter 0 to pick another piece" << endl;
					cin >> distanceToMove;
				}
				if (distanceToMove == 0)
				{
					PlayTurn();
					return;
				}
				else
				{
					arr[i] = cp->move1(board, distanceToMove);
					arr[++i] = cp->move2(board, distanceToMove);
					arr[++i] = cp->move3(board, distanceToMove);
					arr[++i] = cp->move4(board, distanceToMove);
					arr[++i] = cp->move5(board, distanceToMove);
					arr[++i] = cp->move6(board, distanceToMove);
					arr[++i] = cp->move7(board, distanceToMove);
					arr[++i] = cp->move8(board, distanceToMove);

					if (arr[0].first == -1 && arr[1].first == -1 && arr[2].first == -1 && arr[3].first == -1 && arr[4].first == -1 && arr[5].first == -1 && arr[6].first == -1 && arr[7].first == -1)
					{
						printf("                                                                                      No valid moves in that distance, try again\n");
					}
					else
					{
						noValidMoves = false;
					}
				}
			}
		}
		else
		{
			arr[i]   = cp->move1();
			arr[++i] = cp->move2();
			arr[++i] = cp->move3();
			arr[++i] = cp->move4();
			arr[++i] = cp->move5();
			arr[++i] = cp->move6();
			arr[++i] = cp->move7();
			arr[++i] = cp->move8();
		}
		bool movePassed = false;
		//makes tempboard with possible moves
		for (int i = 0; i < 8; i++)
		{
			if (cp->checkMove(board,arr[i]))
			{
				if (arr[i].first == -1)
				{
				}
				else
				{
					movePassed = true;
					tempBoard[arr[i].first][arr[i].second]->symbol = '*';
					tempBoard[arr[i].first][arr[i].second]->color = 'A' + i; 
				}
			}
		}

		DrawBoard(tempBoard);
		makeChoice(movePassed,tempBoard,cp,arr);
		delete[] arr;
	}
	

		//makes possible move array and sets it to the pieces possMOves

	void makeChoice(bool movePassed, ChessPiece *** tempBoard, ChessPiece *cp, pair<int, int> arr[])
	{
		ChessPiece *CheckPiece;
		if (movePassed)
		{
			
			char choice = '?';
			while (choice != 'A'&&choice!= 'B'&&choice!='C'&&choice!='D'&&choice!='E'&&choice!='F'&&choice!='G'&&choice!='H'&&choice != 'a'&&choice!= 'b'&&choice!='c'&&choice!='d'&&choice!='e'&&choice!='f'&&choice!='g'&&choice!='h'&&choice!='X'&&choice!='x')
			{
				cout<< "				 		                  Choose a letter on the board to move your piece, or press X to pick another piece"<<endl;
				cin >> choice;
			}

			//actually literally totally makes move
			int move_array_index = 0; 
			if ((choice == 'A'||choice == 'a') && cp->checkMove(board,arr[move_array_index]))
			{
				if (inCheck)
				{
					if (CheckMakeMove(arr[move_array_index], cp))
					{
						printf("                                         Invalid move, your King is still in check. Hit 1 to try again, or hit 0 if you are in Checkmate.\n");
						cin >> checkmate;
						if (checkmate == 1)
						{
							DrawBoard();
							for (int i = 0; i < 12; i++)
							{
								for (int j = 0; j < 12; j++)
									delete tempBoard[i][j];

								delete[] tempBoard[i];
							}

							delete[] tempBoard;
							PlayTurn();
						}
						else if (checkmate == 0)
						{
							inCheck = false;
							return;
						}
					}
					else 
					{
						inCheck = false;
					}
				}

				makeMove(arr[move_array_index], cp);
			}
			else if ((choice == 'B'||choice == 'b')&& cp->checkMove(board,arr[move_array_index+1]))
			{
				if (inCheck)
				{
					if (CheckMakeMove(arr[move_array_index + 1], cp))
					{
						printf("                                         Invalid move, your King is still in check. Hit 1 to try again, or hit 0 if you are in Checkmate.\n");
						cin >> checkmate;
						if (checkmate == 1)
						{
							DrawBoard();
							for (int i = 0; i < 12; i++)
							{
								for (int j = 0; j < 12; j++)
									delete tempBoard[i][j];

								delete[] tempBoard[i];
							}

							delete[] tempBoard;
							PlayTurn();
						}
						else if (checkmate == 0)
						{
							inCheck = false;
							return;
						}
					}
					else 
					{
						inCheck = false;
					}
				}
				makeMove(arr[move_array_index+1], cp);
			}
			else if ((choice == 'C'||choice == 'c')&& cp->checkMove(board,arr[move_array_index+2]))
			{
				if (inCheck)
				{
					if (CheckMakeMove(arr[move_array_index + 2], cp))
					{
						printf("                                         Invalid move, your King is still in check. Hit 1 to try again, or hit 0 if you are in Checkmate.\n");
						cin >> checkmate;
						if (checkmate == 1)
						{
							DrawBoard();
							for (int i = 0; i < 12; i++)
							{
								for (int j = 0; j < 12; j++)
									delete tempBoard[i][j];

								delete[] tempBoard[i];
							}

							delete[] tempBoard;
							PlayTurn();
						}
						else if (checkmate == 0)
						{
							inCheck = false;
							return;
						}
					}
					else 
					{
						inCheck = false;
					}
				}
				makeMove(arr[move_array_index+2], cp);
			}
			else if ((choice == 'D'||choice == 'd')&& cp->checkMove(board,arr[move_array_index+3]))
			{
				if (inCheck)
				{
					if (CheckMakeMove(arr[move_array_index + 3], cp))
					{
						printf("                                         Invalid move, your King is still in check. Hit 1 to try again, or hit 0 if you are in Checkmate.\n");
						cin >> checkmate;
						if (checkmate == 1)
						{
							DrawBoard();
							for (int i = 0; i < 12; i++)
							{
								for (int j = 0; j < 12; j++)
									delete tempBoard[i][j];

								delete[] tempBoard[i];
							}

							delete[] tempBoard;
							PlayTurn();
						}
						else if (checkmate == 0)
						{
							inCheck = false;
							return;
						}
					}
					else 
					{
						inCheck = false;
					}
				}
				makeMove(arr[move_array_index+3], cp);
			}
			else if ((choice == 'E'||choice == 'e')&& cp->checkMove(board,arr[move_array_index+4]))
			{
				if (inCheck)
				{
					if (CheckMakeMove(arr[move_array_index + 4], cp))
					{
						printf("                                         Invalid move, your King is still in check. Hit 1 to try again, or hit 0 if you are in Checkmate.\n");
						cin >> checkmate;
						if (checkmate == 1)
						{
							DrawBoard();
							for (int i = 0; i < 12; i++)
							{
								for (int j = 0; j < 12; j++)
									delete tempBoard[i][j];

								delete[] tempBoard[i];
							}

							delete[] tempBoard;
							PlayTurn();
						}
						else if (checkmate == 0)
						{
							inCheck = false;
							return;
						}
					}
					else
					{
						inCheck = false;
					}
				}
				makeMove(arr[move_array_index+4], cp);
			}
			else if ((choice == 'F'||choice == 'f')&& cp->checkMove(board,arr[move_array_index+5]))
			{
				if (inCheck)
				{
					if (CheckMakeMove(arr[move_array_index + 5], cp))
					{
						printf("                                         Invalid move, your King is still in check. Hit 1 to try again, or hit 0 if you are in Checkmate.\n");
						cin >> checkmate;
						if (checkmate == 1)
						{
							DrawBoard();
							for (int i = 0; i < 12; i++)
							{
								for (int j = 0; j < 12; j++)
									delete tempBoard[i][j];

								delete[] tempBoard[i];
							}

							delete[] tempBoard;
							PlayTurn();
						}
						else if (checkmate == 0)
						{
							inCheck = false;
							return;
						}
					}
					else 
					{
						inCheck = false;
					}
				}
				makeMove(arr[move_array_index+5], cp);
			}	
			else if ((choice == 'G'||choice == 'g')&& cp->checkMove(board,arr[move_array_index+6]))
			{
				if (inCheck)
				{
					if (CheckMakeMove(arr[move_array_index + 6], cp))
					{
						printf("                                         Invalid move, your King is still in check. Hit 1 to try again, or hit 0 if you are in Checkmate.\n");
						cin >> checkmate;
						if (checkmate == 1)
						{
							DrawBoard();
							for (int i = 0; i < 12; i++)
							{
								for (int j = 0; j < 12; j++)
									delete tempBoard[i][j];

								delete[] tempBoard[i];
							}

							delete[] tempBoard;
							PlayTurn();
						}
						else if (checkmate == 0)
						{
							inCheck = false;
							return;
						}
					}
					else 
					{
						inCheck = false;
					}
				}
				makeMove(arr[move_array_index+6], cp);
			}	
			else if ((choice == 'H'||choice == 'h')&& cp->checkMove(board,arr[move_array_index+7]))
			{
				if (inCheck)
				{
					if (CheckMakeMove(arr[move_array_index + 7], cp))
					{
						printf("                                         Invalid move, your King is still in check. Hit 1 to try again, or hit 0 if you are in Checkmate.\n");
						cin >> checkmate;
						if (checkmate == 1)
						{
							DrawBoard();
							for (int i = 0; i < 12; i++)
							{
								for (int j = 0; j < 12; j++)
									delete tempBoard[i][j];

								delete[] tempBoard[i];
							}

							delete[] tempBoard;
							PlayTurn();
						}
						else if (checkmate == 0)
						{
							inCheck = false;
							return;
						}
					}
					else
					{
						inCheck = false;
					}
				}
				makeMove(arr[move_array_index+7], cp);
			}
			else if(choice == 'X'||choice == 'x')
			{
				DrawBoard();
				PlayTurn();
			}
			else
			{
				cout << "                                                               invalid try a different move" <<endl;
				DrawBoard(tempBoard);
				makeChoice(movePassed,tempBoard,cp,arr);

			}
		}
		else
		{
			cout << "                                                                   invalid try a different piece" <<endl;
			PlayTurn();
		}
	}

	bool CheckMakeMove(pair<int, int> move, ChessPiece *cp)
	{
		bool C;
		char oppPlayer = oppositePlayer();
		ChessPiece* colorArr[16];
		ChessPiece *Hold = setEqual(board[move.first][move.second]);
		ChessPiece *CheckPiece = new Check("C", '=', make_pair(move.first, move.second));
		ChessPiece *OtherCheckPiece = setEqual(cp);
		if (oppPlayer == '-')
		{
			for (int i = 0; i < 16; i++)
			{
				colorArr[i] = blackPieces[i];
			}
		}
		else if (oppPlayer == '+')
		{
			for (int i = 0; i < 16; i++)
			{
				colorArr[i] = whitePieces[i];
			}
		}
		int oldRow, oldCol;
		oldRow = cp->getLocation().first;
		oldCol = cp->getLocation().second;
		if (cp->symbol == 'K')
		{
			(board[move.first][move.second]) = CheckPiece;
			C = CheckCheck(colorArr);
			(board[move.first][move.second]) = Hold;
			delete CheckPiece;
		}
		else if (cp->symbol != 'K')
		{
			(board[move.first][move.second]) = OtherCheckPiece;
			wK.symbol = 'C';
			bK.symbol = 'C';
			C = CheckCheck(colorArr);
			(board[move.first][move.second]) = Hold;
			wK.symbol = 'K';
			bK.symbol = 'K';
			delete CheckPiece;
		}
		if (C)
		{
			return true;
		}
		else if (!C)
		{
			return false;
		}
	}

	void makeMove(pair<int,int> move, ChessPiece *cp)
	{
		int oldRow, oldCol;
		oldRow = cp->getLocation().first;
		oldCol = cp->getLocation().second;
		//changes board position of old move
		if (isWinner(move, cp))
		{
		(board[move.first][move.second]) = (board[oldRow][oldCol]);
		(board[move.first][move.second]->setLocation(move));
		gameWon = true;
		return;
		}
		else
		{
		(board[move.first][move.second]) = (board[oldRow][oldCol]);
		(board[move.first][move.second]->setLocation(move));
		}
		if (CheckCheck(cp))
		{
			inCheck = true;
		}
		if (board[move.first][move.second]->symbol == 'P')
			board[move.first][move.second]->has_moved = true;
		board[oldRow][oldCol] = new Empty ("E",'=', make_pair(-1,-1));
		if (board[move.first][move.second]->symbol == 'P' &&board[move.first][move.second]->color == '-'&&move.first == 9)
		{
			board[move.first][move.second] = new Queen("bQ",'-',move);
		}
		if (board[move.first][move.second]->symbol == 'P' &&board[move.first][move.second]->color == '+'&&move.first == 2)
		{
			board[move.first][move.second] = new Queen("wQ",'+',move);
		}
	}

	bool CheckCheck(ChessPiece *cp)
	{
		ChessPiece*** magniBoard = board;
		std::pair<int, int> check_arr[64];
		pair<int, int> tempPair = make_pair(-1,-1);
		//pair<int, int>** check_arr = new pair<int, int>*[64];
		for (int i = 0; i < 64; i++)
		{
			check_arr[i] = tempPair;
		}
		int j = 1;
		if (cp->symbol == 'R' || cp->symbol == 'B')
		{
			for (int i = 0; i < 32; i+=4)
			{
				check_arr[i] = cp->move1(board, j);
				check_arr[i + 1] = cp->move2(board, j);
				check_arr[i + 2] = cp->move3(board, j);
				check_arr[i + 3] = cp->move4(board, j);
				j++;
			}
		}
		else if (cp->symbol == 'Q')
		{
			for (int i = 0; i < 64; i+=8)
			{
				check_arr[i] = cp->move1(board, j);
				check_arr[i + 1] = cp->move2(board, j);
				check_arr[i + 2] = cp->move3(board, j);
				check_arr[i + 3] = cp->move4(board, j);
				check_arr[i + 4] = cp->move5(board, j);
				check_arr[i + 5] = cp->move6(board, j);
				check_arr[i + 6] = cp->move7(board, j);
				check_arr[i + 7] = cp->move8(board, j);
				j++;
			}

		}
		else
		{
			for (int i = 0; i < 64; i+=8)
			{
				check_arr[i] = cp->move1();
				check_arr[i + 1] = cp->move2();
				check_arr[i + 2] = cp->move3();
				check_arr[i + 3] = cp->move4();
				check_arr[i + 4] = cp->move5();
				check_arr[i + 5] = cp->move6();
				check_arr[i + 6] = cp->move7();
				check_arr[i + 7] = cp->move8();
			}
		}
		for (int i = 0; i <64; i++)
		{
			if (cp->checkMove(board, check_arr[i]))
			{
				if ((check_arr[i]).first == -1)
				{
				}
				else
				{
					if (magniBoard[(check_arr[i]).first][(check_arr[i]).second]->symbol == 'K')
					{
						inCheck = true;
						return true;
					}
					else
					{
						inCheck = false;
					}
				}
			}
		}
		/*for (int i = 0; i < 64; i++)
		{
			delete check_arr[i];
		}*/
		//delete[] check_arr;

		/*for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
				delete magniBoard[i][j];
			delete[] magniBoard[i];
		}
		delete[] magniBoard;*/

		if (inCheck)
		{
			return true;
		}
	return false;
	}

	bool CheckCheck(ChessPiece* PieceArray[16])
	{
		ChessPiece *cp;
		ChessPiece*** magniBoard = board;
		pair<int, int> check_arr[64];
		pair<int, int> tempPair = make_pair(-1, -1);
		for (int i = 0; i < 16; i++)
		{
			cp = PieceArray[i];
			for (int i = 0; i < 64; i++)
			{
				check_arr[i] = tempPair;
			}
		
			int j =1;
			if (cp->symbol =='R' || cp-> symbol =='B')
			{
				for (int i = 0; i < 32; i+=4)
				{
					check_arr[i]   = cp->move1(board,j);
					check_arr[i+1] = cp->move2(board,j);
					check_arr[i+2] = cp->move3(board,j);
					check_arr[i+3] = cp->move4(board,j);
					j++;
				}
			}
			else if(cp->symbol == 'Q')
			{
				for (int i = 0; i < 64; i+=8)
				{
					check_arr[i]   = cp->move1(board,j);
					check_arr[i+1] = cp->move2(board,j);
					check_arr[i+2] = cp->move3(board,j);
					check_arr[i+3] = cp->move4(board,j);
					check_arr[i+4] = cp->move5(board,j);
					check_arr[i+5] = cp->move6(board,j);
					check_arr[i+6] = cp->move7(board,j);
					check_arr[i+7] = cp->move8(board,j);
					j++;
				}
			}
			else
			{
				for(int i = 0; i < 64; i+=8)
				{
					check_arr[i]   = cp->move1();
					check_arr[i+1] = cp->move2();
					check_arr[i+2] = cp->move3();
					check_arr[i+3] = cp->move4();
					check_arr[i+4] = cp->move5();
					check_arr[i+5] = cp->move6();
					check_arr[i+6] = cp->move7();
					check_arr[i+7] = cp->move8();
					j++;
				}
			}
			for (int i = 0; i <64; i++)
			{
				if (cp->checkMove(board,check_arr[i]))
				{
					if ((check_arr[i]).first == -1)
					{
					}
					else
					{
						if (magniBoard[(check_arr[i]).first][(check_arr[i]).second]->symbol == 'C')
						{
							inCheck = true;
							return true;
						}
						else
						{
							inCheck = false;
						}
					}
				}
			}
			/*for (int i = 0; i < 64; i++)
			{
					delete check_arr[i];
			}*/
			//delete[] check_arr;

			/*for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 12; j++)
					delete magniBoard[i][j];
				delete[] magniBoard[i];
			}
			delete [] magniBoard;*/

			if(inCheck)
			{
				return true;
			}
		}
		return false;
	}
	~ChessGame()
	{
	
	}
};


int main()
{
	ChessGame game = ChessGame();
	bool done = false;



	while(!done)
		done = game.Update();
	return 0;
}
