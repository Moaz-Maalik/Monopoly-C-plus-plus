#define _WIN32_WINNT 0x0500
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <conio.h>

#include <windows.h>
#include <windowsx.h>



void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}


void myLine(int x1, int y1, int x2, int y2, int color) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(color, color, color)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}

void myLine2(int x1, int y1, int x2, int y2, int R, int G, int B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 20, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);


}

void myLine3(int x1, int y1, int x2, int y2, int R, int G, int B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 5, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}


bool isCursorKeyPressed(int& whickKey)   //whichKey passed as reference....
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whickKey = 1;		// 1 if left key is pressed
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whickKey = 2;		// 2 if up key is pressed
		return true;
	}

	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whickKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whickKey = 4;   // 4 if down key is pressed
		return true;
	}
	return false;
}


void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}

void shape2(int x1, int y1, int x2, int y2,int R,int G,int B,int FR,int FG,int FB)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

	HPEN hpen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	HPEN hOldPen = SelectPen(device_context, hpen);

	HBRUSH hBrush = CreateSolidBrush(RGB(FR, FG, FB));
	HBRUSH hOldBrush = SelectBrush(device_context, hBrush);

	int center=(x1+x2)/2,center1=(y1+y1)/2,cen=(x2-x1)/4,cen1=(y2-y1)/4;
    //change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.

    SelectObject(device_context,hpen);
	MoveToEx(device_context,center,y1,NULL);
    LineTo(device_context,x1,y1+ cen1);
	LineTo(device_context,x1+cen,y2);
	LineTo(device_context,x2-cen,y2);
	LineTo(device_context,x2,y1+cen1);
	LineTo(device_context,center,y1);

	FloodFill(device_context,x1,y1,(RGB(R,G,B)));

	ReleaseDC(console_handle, device_context);



	SelectBrush(device_context, hOldBrush);
	DeleteObject(hBrush);

	SelectPen(device_context, hOldPen);
	DeleteObject(hpen);

	}


void Polygon(int x1, int y1, int x2, int y2,int R,int G,int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);

	HBRUSH brush = CreateSolidBrush(RGB(FR, FG, FB));

	SelectObject(device_context, brush);

	POINT vertices[] = { {(x1+x2)/2, y1}, {x2, y2}, {x1, y2} };
	Polygon(device_context, vertices, sizeof(vertices) / sizeof(vertices[0]));

	ReleaseDC(console_handle, device_context);

	DeleteObject(brush);
	DeleteObject(pen);
}

void Poly2(int x1, int y1, int x2, int y2,int R,int G,int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);

	HBRUSH brush = CreateSolidBrush(RGB(FR, FG, FB));

	SelectObject(device_context, brush);

	POINT vertices[] = { {(x1), y1}, {x2, y2}, {x1, y2}, {x2,y1} };
	Polygon(device_context, vertices, sizeof(vertices) / sizeof(vertices[0]));

	ReleaseDC(console_handle, device_context);

	DeleteObject(brush);
	DeleteObject(pen);
}

void Poly3(int x1, int y1, int x2, int y2,int R,int G,int B, int FR, int FG, int FB)
{

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);

	HBRUSH brush = CreateSolidBrush(RGB(FR, FG, FB));

	SelectObject(device_context, brush);

	POINT vertices[] = { {(x1+x2)/2, y1}, {x2, (y1+y2)/2}, {(x1+x2)/2, y2}, {x1,(y1+y2)/2} };
	Polygon(device_context, vertices, sizeof(vertices) / sizeof(vertices[0]));
	ReleaseDC(console_handle, device_context);
	DeleteObject(brush);
	DeleteObject(pen);
}


void myRect(int x1, int x2, int y1, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB)); //Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, x2, y1, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}


void myRect2(int x1, int x2, int y1, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 5, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB)); //Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, x2, y1, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}


void myTriangle(int x1, int y1, int x2, int y2,int R, int G, int B,int FR,int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID, 2, RGB(R,G,B));
	SelectObject(device_context,pen);

	HBRUSH brush = ::CreateSolidBrush(RGB(FR,FG,FB));
	SelectObject(device_context,brush);

	int center=(x1+x2)/2, centerY=(y1+y2)/2;


	FloodFill(device_context,center,centerY,(RGB(R,G,B)));
	ReleaseDC(console_handle, device_context);

	DeleteObject(pen);
	DeleteObject(brush);
}






void Digit1(int a)
{
		myLine3(100+a*1.25,100,100+a*1.25,150,255,0,0);
		myLine3(80+a*1.25,120,100+a*1.25,100,255,0,0);
		myLine3(80+a*1.25,150,110+a*1.25,150,255,0,0);
}
void Digit2(int a) //use three 3 integers if you want colored lines.
{
	myLine3(100+a,100,150+a,100,255,0,0);
	myLine3(150+a,100,150+a,125,255,0,0);
	myLine3(100+a,125,150+a,125,255,0,0);
	myLine3(100+a,125,100+a,150,255,0,0);
	myLine3(100+a,150,150+a,150,255,0,0);
}
void Digit3(int a) //use three 3 integers if you want colored lines.
{
	myLine3(100+a,100,150+a,100,255,0,0);
	myLine3(150+a,100,150+a,125,255,0,0);
	myLine3(100+a,125,150+a,125,255,0,0);
	myLine3(150+a,125,150+a,150,255,0,0);
	myLine3(100+a,150,150+a,150,255,0,0);

}
void Digit4(int a)
{
		myLine3(150+a,100,150+a,150,255,0,0);
		myLine3(100+a,125,150+a,125,255,0,0);
		myLine3(100+a,100,100+a,125,255,0,0);
}
void Digit5(int a)
{
	myLine3(100+a,100,150+a,100,255,0,0);
	myLine3(100+a,100,100+a,125,255,0,0);
	myLine3(100+a,125,150+a,125,255,00,0);
	myLine3(150+a,125,150+a,150,255,0,0);
	myLine3(100+a,150,150+a,150,255,0,0);
}
void Digit6(int a)
{
	myLine3(100+a,100,150+a,100,255,0,0);
	myLine3(100+a,100,100+a,125,255,0,0);
	myLine3(100+a,125,150+a,125,255,0,0);
	myLine3(150+a,125,150+a,150,255,0,0);
	myLine3(100+a,150,150+a,150,255,0,0);
	myLine3(100+a,125,100+a,150,255,0,0);
}
void Digit7(int a)
{
	myLine3(150+a,100,150+a,150,255,0,0);
	myLine3(100+a,100,150+a,100,255,0,0);
}
void Digit8(int a)
{
	myLine3(100+a,100,150+a,100,255,0,0);
	myLine3(100+a,100,100+a,125,255,0,0);
	myLine3(100+a,125,150+a,125,255,0,0);
	myLine3(150+a,125,150+a,150,255,0,0);
	myLine3(100+a,150,150+a,150,255,0,0);
	myLine3(100+a,125,100+a,150,255,0,0);
	myLine3(150+a,100,150+a,125,255,0,0);
}
void Digit9(int a)
{
	myLine3(100+a,100,150+a,100,255,0,0);
	myLine3(100+a,100,100+a,125,255,0,0);
	myLine3(100+a,125,150+a,125,255,0,0);
	myLine3(150+a,125,150+a,150,255,0,0);
	myLine3(100+a,150,150+a,150,255,0,0);

	myLine3(150+a,100,150+a,125,255,0,0);
}
void Digit0(int a)
{
	myRect2(100+a,100,155+a,150,255,0,0,0,0,0);
}

void Box ()
{
	myLine2(450,50,900,50,0,255,255);//--
	myLine2(450,450,900,450,0,255,255);//_
	myLine2(450,50,450,450,0,255,255);//|
	myLine2(900,50,900,450,0,255,255); //  |
}

using namespace std;



void printBoard(int board[4][10],int time,int score, int a2, int startingPosition, int currentlySelectedRow, int CurrentlySelectedColumn,  int currentlySelectedRow2, int CurrentlySelectedColumn2)
{


		int startfromhere;

		myRect(530, 90, 750, 190,255,0,255, 0, 255, 255);


		myRect(980, 480, 1200, 580,0,255,255, 255, 0, 255);

		myRect(530, 290, 1200, 340, 255,0,255,255,255,0);


for (int row = 0; row < 4; row++)
	{
	    if (row==0)
        {

            for (int column = 0; column < 10; column++)
            {
                int x1, x2, y1, y2;

                x1 = (startingPosition +380) + (column * 85);
                y1 = (startingPosition + -10) + (row * 85);
                x2 = (startingPosition + 465) + (column * 85);
                y2 = (startingPosition + 55) + (row * 85);

                int borderColor = 0;
                int borderColor2 =0;

                if (row == currentlySelectedRow && column == CurrentlySelectedColumn)
                {
                    borderColor = 255;
                }

                if (row == currentlySelectedRow2 && column == CurrentlySelectedColumn2)
                {
                    borderColor2 = 500;
                }


                if (board[row][column] == 0)
                {
                    /*myEllipse(x1, y1, x2, y2, 0, borderColor, borderColor, 0, 0, 2-55);*/
                    myRect(x1, y1, x2, y2, borderColor2, borderColor, borderColor, 0, 0, 255);

                    gotoxy(1000, 1000);

                }
                else if (board[row][column] == 1)
                {
                    myRect(x1, y1, x2, y2, borderColor2, borderColor, borderColor, 0, 255, 0);

                }
                else if (board[row][column] == 2)
                {
                    myRect(x1, y1, x2, y2, borderColor2, borderColor, borderColor, 255, 0, 0);

                }
            }
        }
	    if (row==1)
        {

            for (int column = 0; column < 10; column++)
            {
                int x1, x2, y1, y2;

                x1 = (startingPosition + 380) + (10 * 85);
                y1 = (startingPosition + -10) + ((column+row-1) * 62);
                x2 = (startingPosition + 465) + (10 * 85);
                y2 = (startingPosition + 55) + ((column+row-1) * 62);

                int borderColor = 0;
                int borderColor2 = 0;

                if (row == currentlySelectedRow && column == CurrentlySelectedColumn)
                {
                    borderColor = 255;
                }


                if (row == currentlySelectedRow2 && column == CurrentlySelectedColumn2)
                {
                    borderColor2 = 255;
                }



                if (board[row][column] == 0)
                {
                    /*myEllipse(x1, y1, x2, y2, 0, borderColor, borderColor, 0, 0, 2-55);*/
                    myRect(x1, y1, x2, y2, borderColor2, borderColor, borderColor, 0, 0, 255);
                }
                else if (board[row][column] == 1)
                {
                    myRect(x1, y1, x2, y2, borderColor2, borderColor, borderColor, 0, 255, 0);
                }
                else if (board[row][column] == 2)
                {
                    myRect(x1, y1, x2, y2, borderColor2, borderColor, borderColor, 255, 0, 0);
                }
            }
        }
        if (row==2)
        {

            for (int column = 0; column < 10; column++)
            {
                int x1, x2, y1, y2;

                x1 = (startingPosition +380) + ((column+1) * 85);
                y1 = (startingPosition + -10) + (10 * 60);
                x2 = (startingPosition + 465) + ((column+1) * 85);
                y2 = (startingPosition + 55) + (10 * 60);

                int borderColor = 0;
                int borderColor2 = 0;

                if (row == currentlySelectedRow && column == 9-CurrentlySelectedColumn)
                {
                    borderColor = 255;
                }



                if (row == currentlySelectedRow2 && column == 9-CurrentlySelectedColumn2)
                {
                    borderColor2 = 255;
                }

                if (board[row][column] == 0)
                {
                    /*myEllipse(x1, y1, x2, y2, 0, borderColor, borderColor, 0, 0, 2-55);*/
                    myRect(x1, y1, x2, y2, borderColor2, borderColor, borderColor, 0, 0, 255);
                }
                else if (board[row][column] == 1)
                {
                    myRect(x1, y1, x2, y2, borderColor2, borderColor, borderColor, 0, 255, 0);
                }
                else if (board[row][column] == 2)
                {
                    myRect(x1, y1, x2, y2, borderColor2, borderColor, borderColor, 255, 0, 0);
                }
            }
        }
        if (row==3)
        {

            for (int column = 0; column < 10; column++)
            {
                int x1, x2, y1, y2;

                x1 = (startingPosition + 380) + (0 * 85);
                y1 = (startingPosition + -10) + ((column+row-2) * 62);
                x2 = (startingPosition + 465) + (0 * 85);
                y2 = (startingPosition + 65) + ((column+row-2) * 62);

                int borderColor = 0;
                int borderColor2 = 0;


                if (row == currentlySelectedRow && column == 9-CurrentlySelectedColumn)
                {
                    borderColor = 255;
                }


                if (row == currentlySelectedRow2 && column == 9-CurrentlySelectedColumn2)
                {
                    borderColor2 = 255;
                }



                if (board[row][column] == 0)
                {
                    /*myEllipse(x1, y1, x2, y2, 0, borderColor, borderColor, 0, 0, 2-55);*/
                    myRect(x1, y1, x2, y2, borderColor2, borderColor, borderColor, 0, 0, 255);
                }
                else if (board[row][column] == 1)
                {
                    myRect(x1, y1, x2, y2, borderColor2, borderColor, borderColor, 0, 255, 0);
                }
                else if (board[row][column] == 2)
                {
                    myRect(x1, y1, x2, y2, borderColor2, borderColor, borderColor, 255, 0, 0);
                }
            }

		}




	}

}

int RollDice()
{
    srand((unsigned)time(0));
    int dice=rand() % 7;
    if(dice==0)
    {
        dice=3;
    }
    return dice;
}

void PopulateBoard(int board[4][10])
{
	srand((unsigned)time(0));
	for (int row = 0; row < 4; row++)
	{
	    for (int col = 0; col < 10; col++)
        {
            board[row][col]=1;
        }
	}
    board[0][0]=2;
    board[1][0]=2;
	board[2][9]=2;
	board[3][9]=2;

	board[0][2]=0;
	board[0][4]=0;
	board[0][5]=0;
	board[0][7]=0;

	board[1][2]=0;
	board[1][5]=0;
	board[1][7]=0;


	board[2][1]=0;
	board[2][4]=0;
	board[2][6]=0;


	board[3][1]=0;
	board[3][4]=0;
	board[3][6]=0;


}

class Player
{
protected:
    string name;
    int id;
    int amount;
    int row;
    int column;

public:

    Player()
    {
        id=0;
        amount=0;
        row=0;
        column=0;

    }

    Player(string a, int ID, int money, int roww, int col )
    {
        name=a;
        id=ID;
        amount=money;
        row=roww;
        column=col;

    }

    void setPlayer(string a, int ID, int money, int roww, int col )
    {
        name=a;
        id=ID;
        amount=money;
        row=roww;
        column=col;

    }

    string getnamePlayer()
    {
        return name;
    }

    int getidPlayer()
    {
       return id;
    }

    int getamountPlayer()
    {
        return amount;
    }

    int getrowPlayer()
    {
        return row;
    }

    int getcolumnPlayer()
    {
        return column;
    }


    void setnamePlayer(string n)
    {
        name=n;
    }

    void setidPlayer(int ID)
    {
        id=ID;
    }

    void setamountPlayer(int money)
    {
        amount=money;
    }

    void setrowPlayer(int roww)
    {
        row=roww;
    }

    void setcolumnPlayer(int col)
    {
        column=col;
    }

    ~Player()
    {
        name="Player";
        id=0;
        amount=0;
        row=0;
        column=0;

    }


};

class Property
{
protected:
    int ID;
    int ownerid;
    int token;
    int mortgage;
    int Proprow;
    int Propcol;

public:

    Property()
    {
        Proprow=0;
        Propcol=0;
        ID=0;
        ownerid=0;
        token=0;
        mortgage=0;
    }

    Property(int id,int owner,int tkn,int mort,int prow,int pcol)
    {
        Proprow=prow;
        Propcol=pcol;
        ID=id;
        ownerid=owner;
        token=tkn;
        mortgage=mort;
    }

    ~Property()
    {

        Proprow=0;
        Propcol=0;
        ID=0;
        ownerid=0;
        token=0;
        mortgage=0;
    }

    virtual void setProperty(int noofup, int money, int rnt, int grp,int id,int owner,int tkn,int mort,int prow,int pcol,string nme)
    {
        Proprow=prow;
        Propcol=pcol;
        ID=id;
        ownerid=owner;
        token=tkn;
        mortgage=mort;
    }


    int getidProp()
    {
        return ID;
    }

    void setPropid(int id)
    {
        ID=id;
    }


    void setProptoken(int tkn)
    {
        token=tkn;
    }


    int getProptoken()
    {
        return token;
    }

    void setPropmortgage(int mort)
    {
        mortgage=mort;
    }

    int getPropmortgage()
    {
        return mortgage;
    }


    virtual void SetRent(int rnt)=0;

    virtual void set_PropPrice(int money)=0;

    virtual int get_upgrdble_grp()=0;

    virtual void set_PropName(string)=0;

    virtual int getUpgradable_Price()=0;

    virtual string getPropname()=0;

    virtual int getUpgradable_rent()=0;

    virtual  void setPropowner(int owner)
    {
        ownerid=owner;
    }

    virtual void setProprow(int pr)
    {
        Proprow=pr;
    }


    virtual void setPropcol(int col)
    {
        Propcol=col;
    }


    virtual int getProprow()
    {
        return Proprow;
    }


    virtual int getPropowner()
    {
        return ownerid;
    }





    virtual int getPropcol()
    {
        return Propcol;

    }

};

class upgradable: public Property
{
protected:

    string name;
    int noofupgrdable;
    int price;
    int rent;
    int group;
public:
    upgradable()
    {
        noofupgrdable=0;
        price=0;
        rent=0;
        group=0;
    }
    upgradable(int noofup, int money, int rnt, int grp, int id,int owner,int tkn,int mort,int prow,int pcol, string nme)
    {
        name=nme;
        Proprow=prow;
        Propcol=pcol;
        ID=id;
        ownerid=owner;
        token=tkn;
        mortgage=mort;
        noofupgrdable=noofup;
        price=money;
        rent=rnt;
        group=grp;
    }
    ~upgradable()
    {
        noofupgrdable=0;
        price=0;
        rent=0;
        group=0;
    }

    virtual void setProperty(int noofup, int money, int rnt, int grp, int id,int owner,int tkn,int mort,int prow,int pcol, string nme)
    {
        name=nme;
        Proprow=prow;
        Propcol=pcol;
        ID=id;
        ownerid=owner;
        token=tkn;
        mortgage=mort;
        noofupgrdable=noofup;
        price=money;
        rent=rnt;
        group=grp;
    }

    int get_upgrdble_grp()
    {
        return group;
    }

    virtual int getUpgradable_Price()
    {
        return price;
    }

    virtual int getUpgradable_rent()
    {
        return rent;
    }

    virtual void set_PropName(string a)
    {
        name=a;
    }

    virtual void set_PropPrice(int money)
    {
        price=money;
    }

    virtual string getPropname()
    {
        return name;
    }

    virtual void SetRent(int rnt)
    {
        rent=rnt;
    }

};

class unupgradable:public Property
{
protected:

    string name;
    int price;
    int group;
    int rent;
    int noofup;

public:

    unupgradable()
    {
        price=0;
        group=0;
    }

    unupgradable(int noofup, int money, int rnt, int grp, int id,int owner,int tkn,int mort,int prow,int pcol, string nme)
    {
        noofup=0;
        name=nme;
        Proprow=prow;
        Propcol=pcol;
        ID=id;
        ownerid=owner;
        token=tkn;
        mortgage=mort;
        price=money;
        group=grp;
        rent=rnt;
    }
    ~unupgradable()
    {
        price=0;
        group=0;
    }


    virtual void setProperty (int noofup, int money, int rnt, int grp, int id,int owner,int tkn,int mort,int prow,int pcol, string nme)
    {
        noofup=0;
        name=nme;
        Proprow=prow;
        Propcol=pcol;
        ID=id;
        ownerid=owner;
        token=tkn;
        mortgage=mort;
        price=money;
        group=grp;
        rent=rnt;
    }

        int get_upgrdble_grp()
    {
        return group;
    }

    virtual void set_PropName(string a)
    {
        name=a;
    }


    virtual void set_PropPrice(int money)
    {
        price=money;
    }

    virtual int getUpgradable_Price()
    {
        return price;
    }

    virtual int getUpgradable_rent()
    {
        return rent;
    }

    virtual string getPropname()
    {
        return name;
    }

    virtual void SetRent(int rnt)
    {
        rent=rnt;
    }

};


class chances
{
 public:
        char ** chans;
        chances()
        {
            chans=NULL;
        }
        void inputfromfile()
        {
            ifstream fin("Chance.txt");
            int count=0;
            char ab[200];
            cout<<" *************** CHANCES ****************"<<endl;
            while(!fin.eof())
            {
                fin.getline(ab,200);
                cout<<count<<" .  "<<ab<<endl;
                count++;
            }
            fin.close();
            _getch();
            system("cls");
            chans=new char*[count];
            char ba[100];
            fin.open("Chance.txt");
            int j=0;
            while(!fin.eof() && j<14)
            {
                int count2=0;
                fin.getline(ba,100);
                for(int i=0;ba[i]!=' ';i++)
                {
                    count2++;

                }
                count2++;

                chans[j]=new char[count2];
                j++;
            }
            fin.close();
            char baaa[200];
            fin.open("Chance.txt");
            int k=0;



        }
        void output()
        {
        }


};


class cumunity_chest
{
 public:
        char ** rules;
        cumunity_chest()
        {
            rules=NULL;
        }
        void inputfromfile()
        {
            ifstream fin("CommunityChest.txt");
            int count=0;
            char ab[100]{'\0'};

            cout<<" *************** COMMUNITY CHEST ****************"<<endl;
            while(!fin.eof())
            {
                fin.getline(ab,100);
                cout<<count<<" .  "<<ab<<endl;
                count++;
            }
            cout << endl<< endl;
            fin.close();
            _getch();
            system("cls");

        }
        void output()
        {
        }


};



void setupgradeables(Player & Pl1, Player & Pl2, Property**s)
{

       int option=0,option2=0;
       int bid1=0, bid2=0;
       int flag=0;


      for(int k=0; k<20; k++)
      {
        if (Pl2.getrowPlayer()==s[k]->getProprow() && Pl2.getcolumnPlayer()==s[k]->getPropcol() && s[k]->getPropowner()==0)
        {
            for(int j=0; j<20; j++)// The person will traverse the upgradeable class and if there's an incomplete bought property
                //                                                                       it will not allow him to buy that property.
            {
                if(j!=k)
                {
                    if (s[j]->getPropowner()==Pl2.getidPlayer())
                    {
                        for(int l=j; l<j+3; l++)
                        {
                            if (s[j]->get_upgrdble_grp()==s[l]->get_upgrdble_grp() && s[l]->getPropowner()==s[j]->getPropowner() && s[j]->get_upgrdble_grp()!=0)
                            flag++;
                        }
                    }
                    else
                        flag=3;
                }
            }
            if(flag==3 || s[k]->get_upgrdble_grp()==0)
            {
                 cout<<endl<<Pl2.getnamePlayer()<<"   ,"<<s[k]->getPropname()<<"   : What do you want?\n1. Buy the Property\n2. Auction";
                 cin>>option;
                 if (option==1)
                 {
                    if (Pl2.getamountPlayer()-s[k]->getUpgradable_Price()>0)
                    {
                        s[k]->setPropowner(2);
                        Pl2.setamountPlayer(Pl2.getamountPlayer()-s[k]->getUpgradable_Price());
                    }
                    else
                    {
                        int options;
                        cout<<"YOU DONOT HAVE ENOUGH AMOUNT\nSELECT PROPERTY BELOW TO MORTGAGE";
                        for (int k=0; k<20; k++)
                        {
                             if(s[k]->getPropowner()==Pl2.getidPlayer())
                             {
                                 cout<<s[k]->getidProp()<<".  "<<s[k]->getPropname()<<endl;
                             }
                             s[options]->setPropowner(0);
                         }
                    }
                 }
                 if (option==2)
                 {
                    for (int i=0; option2!=2; i++)
                    {
                        cout<<"1. Bid\n2. Done";
                        cin>>option2;
                        if (i%2==0)
                        {
                          cout<<"PLAYER 1 BID";
                          cin>>bid2;
                        }
                          if (i%2!=0)
                         {
                                  cout<<"PLAYER 2 BID";
                                 cin>>bid1;
                         }
                     }
                     if (bid2>bid1)
                     {
                              s[k]->setPropowner(2);
                              Pl2.setamountPlayer(Pl2.getamountPlayer()-bid1);
                      }
                      else
                      {
                             s[k]->setPropowner(1);
                            Pl1.setamountPlayer(Pl1.getamountPlayer()-bid2);
                      }
                   }
              }
        }
              else if (Pl2.getrowPlayer()==s[k]->getProprow() && Pl2.getcolumnPlayer()==s[k]->getProprow() && s[k]->getPropowner()!=0)
              {
                     cout<<" What do you want?\n1. Pay Rent\n2. Mortgage";
                     cin>>option;
                     int options=0;

                     if (option==1)
                     {
                          Pl2.setamountPlayer(Pl2.getamountPlayer()-s[k]->getUpgradable_rent());
                     }
                     if (option==2)
                     {
                         cout<<"SELECT THE PROPERTY TO MORTGAGE";

                        for (int k=0; k<20; k++)
                        {
                                if(s[k]->getPropowner()==Pl2.getidPlayer())
                                {
                                    cout<<s[k]->getidProp()<<".  "<<s[k]->getPropname()<<endl;
                                }
                        }
                        cin>>options;
                        s[options]->setPropowner(0);

                     }
              }

       }

}


void setupgradeables2(Player & Pl1, Player & Pl2, Property ** s)
{

       int option=0,option2=0;
       int bid1=0, bid2=0;
       int flag=0;

      for(int k=0; k<20; k++)
      {
        if (Pl1.getrowPlayer()==s[k]->getProprow() && Pl1.getcolumnPlayer()==s[k]->getPropcol() && s[k]->getPropowner()==0)
        {
            for(int j=0; j<20; j++)// The person will traverse the upgradeable class and if there's an incomplete bought property
                //                                                                       it will not allow him to buy that property.
            {
                if(j!=k)
                {
                    if (s[j]->getPropowner()==Pl1.getidPlayer())
                    {
                        for(int l=j; l<j+3; l++)
                        {
                            if (s[j]->get_upgrdble_grp()==s[l]->get_upgrdble_grp() && s[l]->getPropowner()==s[j]->getPropowner() && s[j]->get_upgrdble_grp()!=0)
                            flag++;
                        }
                    }
                    else
                        flag=3;
                }
            }
            if(flag==3 || s[k]->get_upgrdble_grp()==0)
            {

                            if (Pl1.getrowPlayer()==s[k]->getProprow() && Pl1.getcolumnPlayer()==s[k]->getPropcol() && s[k]->getPropowner()==0)
                            {
                                cout<<endl<<Pl1.getnamePlayer()<<"   ,"<<s[k]->getPropname()<<"  : What do you want?\n1. Buy the Property\n2. Auction";

                                cin>>option;

                                if (option==1)
                                {

                                    if (Pl1.getamountPlayer()-s[k]->getUpgradable_Price()>0)
                                    {
                                        s[k]->setPropowner(1);
                                        Pl1.setamountPlayer(Pl1.getamountPlayer()-s[k]->getUpgradable_Price());
                                    }
                                    else
                                    {
                                        cout<<"YOU DONOT HAVE ENOUGH AMOUNT";

                                    }
                                }
                                if (option==2)
                                {
                                    for (int i=0; option2!=2; i++)
                                    {
                                        cout<<"1. Bid\n2. Done";
                                        cin>>option2;
                                        if (i%2==0)
                                        {
                                            cout<<"PLAYER 1 BID";
                                            cin>>bid1;
                                        }
                                        if (i%2!=0)
                                        {
                                            cout<<"PLAYER 2 BID";
                                            cin>>bid2;
                                        }
                                    }
                                    if (bid1>bid2)
                                    {

                                        s[k]->setPropowner(1);
                                        Pl1.setamountPlayer(Pl1.getamountPlayer()-bid1);

                                    }
                                    else
                                    {
                                        s[k]->setPropowner(2);
                                        Pl2.setamountPlayer(Pl2.getamountPlayer()-bid2);

                                    }
                                }
                            }
              }
        }
                      else if (Pl1.getrowPlayer()==s[k]->getProprow() && Pl1.getcolumnPlayer()==s[k]->getPropcol() && s[k]->getPropowner()!=0)
                            {
                                int options=0;
                                cout<<endl<<Pl1.getnamePlayer()<<"   ,"<<s[k]->getPropname()<<"  : What do you want?\n1. Buy the Property\n2. Auction";
                                cin>>option;
                                if (option==1)
                                {
                                    Pl1.setamountPlayer(Pl1.getamountPlayer()-s[k]->getUpgradable_rent());
                                }
                                if (option==2)
                                 {
                                     cout<<"SELECT THE PROPERTY TO MORTGAGE";

                                    for (int k=0; k<20; k++)
                                    {
                                            if(s[k]->getPropowner()==Pl1.getidPlayer())
                                            {
                                                cout<<s[k]->getidProp()<<".  "<<s[k]->getPropname()<<endl;
                                            }
                                    }
                                    cin>>options;
                                    s[options]->setPropowner(0);

                                 }
                            }


                        }
}



void setunupgradeables(Player & Pl1, Player & Pl2, Property**u)
{

       int option=0,option2=0;
       int bid1=0, bid2=0;
       int flag=0;

      for(int k=0; k<8; k++)
      {
        if (Pl2.getrowPlayer()==u[k]->getProprow() && Pl2.getcolumnPlayer()==u[k]->getPropcol() && u[k]->getPropowner()==0)
        {
                cout<<endl<<Pl2.getnamePlayer()<<"   ,"<<u[k]->getPropname()<<"   : What do you want?\n1. Buy the Property\n2. Auction";
                 cin>>option;
                 if (option==1)
                 {
                    u[k]->setPropowner(2);
                    Pl2.setamountPlayer(Pl2.getamountPlayer()-u[k]->getUpgradable_Price());
                 }

                _getch();
                 if (option==2)
                 {
                    for (int i=0; option2!=2; i++)
                    {
                        cout<<"1. Bid\n2. Done";
                        cin>>option2;
                        if (i%2==0)
                        {
                          cout<<"PLAYER 1 BID";
                          cin>>bid2;
                        }
                          if (i%2!=0)
                         {
                                  cout<<"PLAYER 2 BID";
                                 cin>>bid1;
                         }
                     }
                     if (bid2>bid1)
                     {
                              u[k]->setPropowner(2);
                              Pl2.setamountPlayer(Pl2.getamountPlayer()-bid1);
                      }
                      else
                      {
                             u[k]->setPropowner(1);
                            Pl1.setamountPlayer(Pl1.getamountPlayer()-bid2);
                      }
            }
              else if (Pl2.getrowPlayer()==u[k]->getProprow() && Pl2.getcolumnPlayer()==u[k]->getProprow() && u[k]->getPropowner()!=0)
              {
                     cout<<" What do you want?\n1. Pay Rent\n2. Mortgage";
                     cin>>option;
                     if (option==1)
                     {
                          Pl2.setamountPlayer(Pl2.getamountPlayer()-u[k]->getUpgradable_rent());
                      }
               }
      }
      }
}

void setunupgradeables2(Player & Pl1, Player & Pl2, Property**u)
{

       int option=0,option2=0;
       int bid1=0, bid2=0;
       int flag=0;

      for(int k=0; k<8; k++)
      {
        if (Pl1.getrowPlayer()==u[k]->getProprow() && Pl1.getcolumnPlayer()==u[k]->getPropcol() && u[k]->getPropowner()==0)
        {
                cout<<endl<<Pl1.getnamePlayer()<<"   ,"<<u[k]->getPropname()<<"   : What do you want?\n1. Buy the Property\n2. Auction";
                 cin>>option;

                 if (option==1)
                 {
                    u[k]->setPropowner(2);
                    Pl1.setamountPlayer(Pl2.getamountPlayer()-u[k]->getUpgradable_Price());
                 }

                _getch();

                 if (option==2)
                 {
                    for (int i=0; option2!=2; i++)
                    {
                        cout<<"1. Bid\n2. Done";
                        cin>>option2;
                        if (i%2==0)
                        {
                          cout<<"PLAYER 1 BID";
                          cin>>bid2;
                        }
                          if (i%2!=0)
                         {
                                  cout<<"PLAYER 2 BID";
                                 cin>>bid1;
                         }
                     }
                     if (bid2>bid1)
                     {
                              u[k]->setPropowner(2);
                              Pl2.setamountPlayer(Pl2.getamountPlayer()-bid1);
                      }
                      else
                      {
                             u[k]->setPropowner(1);
                            Pl1.setamountPlayer(Pl1.getamountPlayer()-bid2);
                      }
            }
              else if (Pl1.getrowPlayer()==u[k]->getProprow() && Pl1.getcolumnPlayer()==u[k]->getProprow() && u[k]->getPropowner()!=0)
              {
                     cout<<" What do you want?\n1. Pay Rent\n2. Mortgage";
                     cin>>option;
                     if (option==1)
                     {
                          Pl1.setamountPlayer(Pl1.getamountPlayer()-u[k]->getUpgradable_rent());
                      }
               }
      }
      }
}


void community2(Player & Pl1, Player & Pl2)
{
    int input;
    if ((Pl1.getrowPlayer()==0 && (Pl1.getcolumnPlayer()==2 || Pl1.getcolumnPlayer()==7) || (Pl1.getrowPlayer()==1 &&  Pl1.getcolumnPlayer()==7) || (Pl1.getrowPlayer()==3 &&  Pl1.getcolumnPlayer()==3)))
    {
        cumunity_chest C;

        C.inputfromfile();
        cin>>input;
        if(input == 1)
        {
            Pl1.setrowPlayer(3);
            Pl1.setcolumnPlayer(9);
        }
        if (input == 2)
        {
            Pl1.setamountPlayer(Pl1.getamountPlayer()+200);
        }

    }

}



void community(Player & Pl1, Player & Pl2)
{
    int input;
    if ((Pl2.getrowPlayer()==0 && (Pl2.getcolumnPlayer()==2 || Pl2.getcolumnPlayer()==7) || (Pl2.getrowPlayer()==1 &&  Pl2.getcolumnPlayer()==7) || (Pl2.getrowPlayer()==3 &&  Pl2.getcolumnPlayer()==3)))
    {

        cumunity_chest C;

        C.inputfromfile();
        cin>>input;
        if(input == 1)
        {
            Pl2.setrowPlayer(3);
            Pl2.setcolumnPlayer(9);
        }
        if (input == 2)
        {
            Pl2.setamountPlayer(Pl2.getamountPlayer()+200);
        }


    }

}



void Taxes(Player & Pl1, Player & Pl2)
{
    int tax=0;
        if ((Pl2.getrowPlayer()==0 && Pl2.getcolumnPlayer()==4))
        {
            cout<<Pl2.getnamePlayer()<<" ,  Your 25% land tax has been deducted";
            tax=(Pl2.getamountPlayer()-(Pl2.getamountPlayer()/4));
            Pl2.setamountPlayer(tax);
        }

}


void Taxes2(Player & Pl1, Player & Pl2)
{
    int tax=0;
        if ((Pl1.getrowPlayer()==0 && Pl1.getcolumnPlayer()==4))
        {
            cout<<Pl1.getnamePlayer()<<" ,  Your 25% land tax has been deducted";
            tax=(Pl1.getamountPlayer()-(Pl1.getamountPlayer()/4));
            Pl1.setamountPlayer(tax);
        }

}


void placehouses(Player & Pl1, Player & Pl2, Property **s)
{
            int j=0;
    for(int k=0; k<20; k++)
    {
        if (s[k]->getPropowner()==Pl2.getidPlayer())
        {
            for(int l=0; l<2; l++)
            {
                if(s[k+1]->getPropowner()==Pl2.getidPlayer())
                {
                    j++;
                }

                if(s[k+2]->getPropowner()==Pl2.getidPlayer())
                {
                    j++;
                }
            }
        }
        if (j==2)
        {
            int jwb=0;
            cout<<"YOU wanna place a house at "<<s[k]->getPropname()<<endl<<"1. YES"<<endl<<"2. NO";
            cin>> jwb;
            if (jwb==1)
            {
                cout<<endl<<"YOUR HOUSE HAS BEEN PLACED";
                s[k]->SetRent(s[k]->getUpgradable_rent()+(s[k]->getUpgradable_rent()/4));
            }
        }
        j=0;

    }
}



void placehouses2(Player & Pl1, Player & Pl2, Property **s)
{
            int j=0;
    for(int k=0; k<20; k++)
    {
        if (s[k]->getPropowner()==Pl1.getidPlayer())
        {
            for(int l=0; l<2; l++)
            {
                if(s[k+1]->getPropowner()==Pl1.getidPlayer())
                {
                    j++;
                }

                if(s[k+2]->getPropowner()==Pl1.getidPlayer())
                {
                    j++;
                }
            }
        }
        if (j==2)
        {
            int jwb=0;
            cout<<"YOU wanna place a house at "<<s[k]->getPropname()<<endl<<"1. YES"<<endl<<"2. NO";
            cin>> jwb;
            if (jwb==1)
            {
                cout<<endl<<"YOUR HOUSE HAS BEEN PLACED";
                s[k]->SetRent(s[k]->getUpgradable_rent()+(s[k]->getUpgradable_rent()/4));
            }
        }
        j=0;

    }
}

int main()
{
    int board[4][10]={0};
    Player Bank;
    Bank.setPlayer("BANK",0,1000,0,0);
    Player Pl1;
    Pl1.setPlayer("PLAYER 1",1,5000,0,0);
    Player Pl2;
    Pl2.setPlayer("PLAYER 2",2,5000,0,0);


    string naam;
    cout<<"ENTER THE NAME OF PLAYER 1:"<<endl;
    cin>>naam;

    cout<<"YOUR COLOUR IS BLUE"<<endl;
    Pl1.setnamePlayer(naam);


    cout<<endl<<endl<<endl;
    string naam2;
    cout<<"ENTER THE NAME OF PLAYER 2:"<<endl;
    cin>>naam2;
    cout<<"YOUR COLOUR IS RED"<<endl;
    Pl2.setnamePlayer(naam2);

    Property **s;

    s=new Property*[20];

    for (int i=0; i<20; i++)
    {
         s[i]=new upgradable();

    }
    s[0]->setProperty(0,200,80,0,0,0,0,0,0,1,"JoharTown_A");
    s[1]->setProperty(0,250,90,0,1,0,0,0,0,3,"JoharTown_B");

    s[2]->setProperty(0,250,60,1,2,0,0,0,0,6,"IqbalTown_A");
    s[3]->setProperty(0,300,70,1,3,0,0,0,0,8,"IqbalTown_B");
    s[4]->setProperty(0,400,100,1,4,0,0,0,0,9,"IqbalTown_C");

    s[5]->setProperty(0,300,100,2,5,0,0,0,1,1,"FaisalTown_A");
    s[6]->setProperty(0,400,130,2,6,0,0,0,1,3,"FaisalTown_B");
    s[7]->setProperty(0,400,130,2,7,0,0,0,1,4,"FaisalTown_C");

    s[8]->setProperty(0,800,200,3,8,0,0,0,1,6,"ModelTown_A");
    s[9]->setProperty(0,850,250,3,9,0,0,0,1,8,"ModelTown_B");
    s[10]->setProperty(0,2000,500,3,10,0,0,0,1,9,"ModelTown_C");

    s[11]->setProperty(0,1000,300,4,11,0,0,0,2,1,"Gulberg_A");
    s[12]->setProperty(0,1200,350,4,12,0,0,0,2,2,"Gulberg_B");
    s[13]->setProperty(0,2500,600,4,13,0,0,0,2,4,"Gulberg_C");

    s[14]->setProperty(0,2000,500,5,14,0,0,0,2,6,"DHA_A");
    s[15]->setProperty(0,2000,500,5,15,0,0,0,2,7,"DHA_B");
    s[16]->setProperty(0,2500,1000,5,16,0,0,0,2,9,"DHA_C");

    s[17]->setProperty(0,2500,800,6,17,0,0,0,3,1,"Bahria_A");
    s[18]->setProperty(0,3000,900,6,18,0,0,0,3,2,"Bahria_B");
    s[19]->setProperty(0,3000,1000,6,19,0,0,0,3,4,"Bahria_C");



    Property **u;

    u=new Property*[8];

    for (int i=0; i<8; i++)
    {
         u[i]=new unupgradable();
    }

    u[0]->setProperty(0,2000,200,0,0,0,0,0,0,5,"Metro");
    u[1]->setProperty(0,2000,200,0,1,0,0,0,1,5,"Bus");
    u[2]->setProperty(0,2500,350,0,2,0,0,0,2,5,"Railway");
    u[3]->setProperty(0,2500,350,0,3,0,0,0,3,5,"OrangeLine");
    u[4]->setProperty(0,4000,400,1,4,0,0,0,3,8,"WASA");
    u[5]->setProperty(0,5000,450,1,5,0,0,0,3,9,"LESCO");
    u[6]->setProperty(0,8000,500,1,6,0,0,0,1,2,"PTCL");
    u[7]->setProperty(0,2500,350,1,7,0,0,0,2,8,"SUI");


    cout<<endl<<endl<<"RULES ARE:"<<endl<<"PRESS D TO ROLL THE DICE-NO OTHER KEY MUST BE PRESSED";
    _getch();



	system("cls");

	PopulateBoard(board);
	int currentlySelectedRow=0;
	int currentlySelectedRow2=0;
	int CurrentlySelectedColumn=0;
    int CurrentlySelectedColumn2=0;

	int startingPosition=15;
	int score=0;
	int baari=0;

	int a1=20,a2=400;

	bool bankrupt=false;
	int time=0;


	printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn, currentlySelectedRow2, CurrentlySelectedColumn2);
	char controll='n';

	for (int v=0; v<100; v++)
	{


	while (controll!='m')
	{

		while (controll!='m')
		{


			if (_kbhit())
			{

				system("cls");

				baari++;

				controll = _getch();

				if (controll == 'S')
				{
				remove("save.txt");
				ofstream fout("save.txt");
				for (int i=0; i<4; i++)
				{
					for (int j=0; j<10; j++)
					{
						fout<<board[i][j]<<" ";
					}
					for (int j=0; j<20; j++)
                    {

                    }
				}
				fout<<score<<time;
				fout.close();
			}




				if (controll == 'L')
				{

					ifstream fin("save.txt");
                    for (int i=0; i<4; i++)
                    {
                        for (int j=0; j<10; j++)
                        {
                            fin>>board[i][j];
                        }

                    }

					for (int j=0; j<20; j++)
                    {

                    }
                    fin>>score>>time;

				}
				cout<<Pl1.getnamePlayer()<<"  has Amount:  "<<Pl1.getamountPlayer()<<"/- PKR"<<endl;
				for (int k=0; k<20; k++)
                {
                     if(s[k]->getPropowner()==Pl1.getidPlayer())
                     {
                         cout<<s[k]->getPropname()<<endl;
                     }
                }

                for (int k=0; k<8; k++)
                {
                     if(u[k]->getPropowner()==Pl1.getidPlayer())
                     {
                         cout<<u[k]->getPropname()<<endl;
                     }
                }

				cout<<endl<<endl<<Pl2.getnamePlayer()<<"  has Amount:  "<<Pl2.getamountPlayer()<<"/- PKR"<<endl;
				for (int k=0; k<20; k++)
                {
                     if(s[k]->getPropowner()==Pl2.getidPlayer())
                     {
                         cout<<s[k]->getPropname()<<endl;
                     }
                }
                for (int k=0; k<8; k++)
                {
                     if(u[k]->getPropowner()==Pl2.getidPlayer())
                     {
                         cout<<u[k]->getPropname()<<endl;
                     }
                }

                printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn, currentlySelectedRow2, CurrentlySelectedColumn2);

                if (currentlySelectedRow==4)
                    currentlySelectedRow = 0;

				if (CurrentlySelectedColumn==10)
                    CurrentlySelectedColumn = 0;

				if (controll == 'd')
				{
				    if(baari%2!=0)
                    {


                        if (Pl1.getrowPlayer()==4)
                        {
                            Pl1.setamountPlayer(Pl1.getamountPlayer()+500);
                            Pl1.setrowPlayer(0);
                        }
                        Pl1.setcolumnPlayer(RollDice()+Pl1.getcolumnPlayer());
                        _getch();



                        if (Pl1.getcolumnPlayer()<10)
                        {
                            CurrentlySelectedColumn=Pl1.getcolumnPlayer();
                        }
                        else if (Pl1.getcolumnPlayer()>10 && Pl1.getcolumnPlayer()<20)
                        {
                            CurrentlySelectedColumn=Pl1.getcolumnPlayer()-10;
                            currentlySelectedRow++;
                            Pl1.setrowPlayer(Pl1.getrowPlayer()+1);
                            Pl1.setcolumnPlayer(Pl1.getcolumnPlayer()-10);
                        }

                        setupgradeables(Pl1,Pl2,s);
                        setunupgradeables(Pl1,Pl2,u);
                        community(Pl1,Pl2);
                        Taxes(Pl1,Pl2);

                         printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn, currentlySelectedRow2, CurrentlySelectedColumn2);

                        system("cls");
                        printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn, currentlySelectedRow2, CurrentlySelectedColumn2);



                    }

                    else
                    {


                        if (Pl2.getrowPlayer()==4)
                        {
                            Pl2.setamountPlayer(Pl2.getamountPlayer()+500);
                            Pl2.setrowPlayer(0);
                        }

                        Pl2.setcolumnPlayer(RollDice()+Pl2.getcolumnPlayer());
                        _getch();

                        if (Pl2.getcolumnPlayer()<10)
                        {
                            CurrentlySelectedColumn2=Pl2.getcolumnPlayer();
                        }
                        else if (Pl2.getcolumnPlayer()>10 && Pl2.getcolumnPlayer()<20)
                        {
                            CurrentlySelectedColumn2=Pl2.getcolumnPlayer()-10;
                            currentlySelectedRow2++;
                            Pl2.setrowPlayer(Pl2.getrowPlayer()+1);
                            Pl2.setcolumnPlayer(Pl2.getcolumnPlayer()-10);
                        }

                        system("cls");
                        printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn, currentlySelectedRow2, CurrentlySelectedColumn2);

                        setupgradeables2(Pl1,Pl2,s);
                        setunupgradeables2(Pl1,Pl2,u);
                        community2(Pl1,Pl2);
                        Taxes2(Pl1,Pl2);

                    }

				if (Pl1.getamountPlayer()<0 || Pl2.getamountPlayer()<0 )
                {
                    break;
                }

                    printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn, currentlySelectedRow2, CurrentlySelectedColumn2);
				}

				if (Pl1.getamountPlayer()<0 || Pl2.getamountPlayer()<0 )
                {
                    break;
                }



				if (controll == 13)
				{

				}


			system("cls");


			printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn, currentlySelectedRow2, CurrentlySelectedColumn2);
			}



	}



	}

	}

	return 0;
}
