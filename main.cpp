#include<iostream>
#include <stdlib.h>
#include<Windows.h>
#include "Stacks.h"
#include "mygraphics.h"
#include "myconsole.h"
#include<ctime>
#include <sstream>
using namespace std;


const int source = -9;
const int destination = -10;
const int hurdle = 4;
const int hurdlee = -7;
const int passedd = -5;
const int blocked = 6;
const int passed = 7;
bool Right = true;
bool Left = true;
bool Up = true;
bool Down = true;

void Rat(int c,int x , int y)
{

				myEllipse(x + 10, y + 10, x + 38, y + 38, RGB(100, 00, 0), RGB(225, 225, 0));//face
				myEllipse(x + 3, y + 3, x + 13, y + 13, RGB(100, 00, 0), RGB(0, 225, 0)); //corners
				myEllipse(x + 36, y + 3, x + 46, y + 13, RGB(100, 00, 0), RGB(0, 225, 0));// corners
				myEllipse(x + 3, y + 36, x + 13, y + 46, RGB(100, 00, 0), RGB(0, 225, 0));//corners
				myEllipse(x + 36, y + 36, x + 46, y + 46, RGB(100, 00, 0), RGB(0, 225, 0));//corners
				myEllipse(x + 17, y + 17, x + 24, y + 24, RGB(100, 00, 0), RGB(0, 225, 0)); // eye
				myEllipse(x + 27, y + 17, x + 34, y + 24, RGB(100, 00, 0), RGB(0, 225, 0)); //eye
				myEllipse(x + 17, y + 29, x + 32, y + 30, RGB(100, 00, 0), RGB(0, 225, 0)); //lips

}
void Rat_Spc(int c, int x, int y)
{

	myEllipse(x + 10, y + 10, x + 38, y + 38, RGB(100, 00, 0), RGB(225, 225, 0));//face
	myEllipse(x + 17, y + 17, x + 24, y + 24, RGB(100, 00, 0), RGB(0, 225, 0)); // eye
	myEllipse(x + 27, y + 17, x + 34, y + 24, RGB(100, 00, 0), RGB(0, 225, 0)); //eye
	myEllipse(x + 17, y + 29, x + 32, y + 30, RGB(100, 00, 0), RGB(0, 225, 0)); //lips

}
void Rat_With_Label(int c, int x, int y, int i)
{

	myEllipse(x + 10, y + 10, x + 38, y + 38, RGB(100, 00, 0), RGB(225, 225, 0));//face
	
	int l = i;
	ostringstream str1;
	str1 << l;
	string str = str1.str();
	myDrawTextWithFont(x + 18, y + 14,20, str ,RGB(100, 00, 0), RGB(225, 225, 0)); //lips

}
void Draw_Box(int **arr, int i, int j, int X, int Y)
{
	if (arr[i][j] == hurdle)
	{
		myRect(X, Y, X + 50, Y + 50, RGB(0, 100, 0), RGB(100, 0, 0));
	}
	else if (arr[i][j] == passed)
	{
		myRect(X, Y, X + 50, Y + 50, RGB(0, 100, 0), RGB(240, 248, 255));
	}
	else if (arr[i][j] == source)
	{
		myRect(X, Y, X + 50, Y + 50, RGB(0, 100, 0), RGB(0, 0, 100));
	}
	else if (arr[i][j] == destination)
	{
		myRect(X, Y, X + 50, Y + 50, RGB(0, 100, 0), RGB(0, 200, 0));
		//Cheez
		myEllipse(X+10,Y+10,X+38,Y+38,RGB(100, 0, 0), RGB(225, 165, 0));
	}
	
	else
	{
		myRect(X, Y, X + 50, Y + 50, RGB(0, 100, 0), RGB(255, 255, 0));
	}
}
void Source_Check(int **temp,int i, int j, int X1, int Y1,int r, int c)
{
	if (j + 1 < c && temp[i][j + 1] == source)
	{
		Rat(c, X1 + 50, Y1);
	}
	else if (i + 1 < r && temp[i + 1][j] == source)
	{
		Rat(c, X1, Y1 + 50);
	}
	else if (j - 1 >= 0 && temp[i][j - 1] == source)
	{
		Rat(c, X1 - 50, Y1);
	}
	else if (i - 1 >= 0 && temp[i - 1][j] == source)
	{
		Rat(c, X1, Y1 - 50);
	}
}
void Load_Array(int ** temp,int r,int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{

			temp[i][j] = hurdlee;
		}
	}
}
int **Load_Maze(int ** &arr,int r, int c,int X , int Y, int sx, int sy, int dx, int dy)
{

	// creating random hurdles
	//srand((unsigned)time(0));
	int random;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{

			random = 1 + (rand() % 5);

			arr[i][j] = random;
		}
	}

	// Labeling source and destination
	arr[sx][sy] = source;
	arr[dx][dy] = destination;

	int** arr1 = new int* [r];
	for(int i=0;i<r;i++)
	{
		arr1[i] = new int[c];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			arr1[i][j] = arr[i][j];
		}
	}
	

	for (int i = 0, y = Y; i < r; i++, y += 51)
	{
		for (int j = 0, x = X; j < c; j++, x += 51)
		{
			Draw_Box(arr, i, j, x, y);

		}
		cout << endl;
	}
	return arr1;
}
void Load_Maze2(int**& arr,int **temp, int r, int c, int X, int Y, int sx, int sy, int dx, int dy)
{

	for (int i = 0, y = Y; i < r; i++, y += 51)
	{
		for (int j = 0, x = X; j < c; j++, x += 51)
		{
			Draw_Box(arr, i, j, x, y);

		}
		cout << endl;
	}

	temp[sx][sy] = source;
	temp[dx][dy] = destination;
}
void Traversing_Maze(int** arr,int r, int c, int sx, int sy,int &X,int &Y)
{
	int x = X;
	int y = Y;
	for (int s = 0; s < r; s++, y += 51)
	{
	     x = X;
		for (int t = 0; t < c; t++, x += 51)
		{

			if (s == sx && t == sy)
			{
				goto end;
			}

		}

	}
end:
	X = x;
	Y = y;
	return;
}
void Traversing_Maze_to_Poped_Element(int** arr, int r, int c, int i, int j, int x, int y)
{
	int X = x;
	int Y = y;
	for (int s = 0; s < r; s++, Y += 51)
	{
		X = x;
		for (int t = 0; t < c; t++, X += 51)
		{
			if (s == i && t == j)
			{

				myRect(X, Y, X + 50, Y + 50, RGB(0, 100, 0), RGB(240, 0, 255));
				goto end;
			}

		}

	}
end:
	return;
}
void Traversing_Maze_to_Poped_Element_no_print(int** arr, int r, int c, int i, int j, int &x, int &y)
{
	int X =  x;
	int Y = y;
	for (int s = 0; s < r; s++, Y += 51)
	{
		X = x;
		for (int t = 0; t < c; t++, X += 51)
		{
			if (s == i && t == j)
			{
				Rat(c, X, Y);
				Sleep(500);

				goto  end;
			}

		}

	}
end:
	x = X;
	y = Y;
	return;
}
void Back_Tracking(Linklist<point> :: Stack s, int r, int c,int x, int y)
{
	while (!s.IsEmpty())   // Back tracking
	{
		point l = s.Pop();

		int Y = y;
		for (int s = 0; s < c; s++, Y += 51)
		{
			int X=x;
			for (int t = 0; t < c; t++, X += 51)
			{
				if (s == l.getX() && t == l.getY())
				{
					Rat(c, X, Y);
					Sleep(300);
				}
			}
		}
	}
}
void Back_Tracking2(int **temp, int r, int c,int dx, int dy,int X1,int Y1)
{
  Traversing_Maze(temp, r, c, dx, dy, X1, Y1);
  int i = 0, j = 0;
  Linklist<point> ::Queuee q(r* c);
  Linklist<point> ::Queuee qt(r* c);

  point p(dx, dy);
  i = dx;
  j = dy;

  q.Enqueue(p);

  p.set(X1, Y1);
  qt.Enqueue(p);


  Rat(c, X1, Y1);
 

  while (temp[i][j] != source && !q.IsEmpty())
 {


	point l = q.Dequeue();
	i = l.getX();
	j = l.getY();
	l = qt.Dequeue();
	X1 = l.getX();
	Y1 = l.getY();
	
	if (temp[i][j] != source )
	{

		if (j + 1 < c && temp[i][j + 1] != passedd && temp[i][j]-1 == temp[i][j + 1] && temp[i][j + 1] != hurdlee) //right
		{

			if (temp[i][j + 1] != source)
				myRect(X1 + 50, Y1, X1 + 100, Y1 + 50, RGB(0, 100, 0), RGB(248, 250, 248));
			Rat(c, X1 + 50, Y1);
			if (temp[i][j+1] != source)
				//temp[i][j+1] = passedd;

			p.set(i, j + 1);
			q.Enqueue(p);
			p.set(X1 + 51, Y1);
			qt.Enqueue(p);

			if (temp[i][j + 1] == source)
				break;
			//Sleep(500);
			//  Draw_Box(arr1, i, j - 1, X1 - 51, Y1);

			Sleep(300);
		}
		
		else if (i + 1 < r && temp[i + 1][j] != hurdlee && temp[i + 1][j] != passedd && temp[i][j]-1 == temp[i + 1][j])//down
		{

			if (temp[i + 1][j] != source)
				myRect(X1, Y1 + 50, X1 + 50, Y1 + 100, RGB(0, 100, 0), RGB(249,245,248));
			     Rat(c, X1, Y1 + 50);

			if (temp[i + 1][j] != source)
				//temp[i + 1][j] = passedd;

			p.set(i + 1, j);
			q.Enqueue(p);
			p.set(X1, Y1 + 51);
			qt.Enqueue(p);


			//Sleep(500);
			if (temp[i + 1][j] == source)
				break;

			Sleep(300);
		}
		
		else if (j - 1 >= 0 && temp[i][j - 1] != hurdlee && temp[i][j - 1] != passedd && temp[i][j]-1 == temp[i][j - 1]) //left
		{

			if (temp[i][j - 1] != source)
				myRect(X1 - 50, Y1, X1, Y1 + 50, RGB(0, 100, 0), RGB(250,250,250));
			    Rat(c, X1 - 50, Y1);


			if (temp[i][j - 1] != source)
				//temp[i][j - 1] = passedd;

			p.set(i, j - 1);
			q.Enqueue(p);
			p.set(X1 - 51, Y1);
			qt.Enqueue(p);

			if (temp[i][j - 1] == source)
				break;
			//Draw_Box(arr1, i, j + 1, X1 + 51, Y1);
			Sleep(300);
		}
	
		else if (i - 1 >= 0 && temp[i - 1][j] != hurdlee && temp[i - 1][j] != passedd && temp[i][j]-1 == temp[i - 1][j]) // up
		{
			if (temp[i - 1][j] != source)
				myRect(X1, Y1 - 50, X1 + 50, Y1, RGB(0, 100, 0), RGB(248, 255, 249));
			    Rat(c, X1, Y1 - 50);

				if (temp[i-1][j] != source)
					//temp[i-1][j] = passedd;

			p.set(i - 1, j);
			q.Enqueue(p);
			p.set(X1, Y1 - 51);
			qt.Enqueue(p);

			if (temp[i - 1][j] == source)
				break;
			//Draw_Box(arr1, i + 1, j, X1, Y1 + 51);


		}

		Source_Check(temp, i, j, X1, Y1, r, c);
		
		Sleep(300);
	}
  }

  
}
void Manue(int &r, int &c,int &sx,int &sy,int &dx,int &dy)
{
	FullScreen();

	string start = "Rat In Maze Problem";
	myDrawTextWithFont(500, 250, 100, start, RGB(100, 0, 0), RGB(255, 255, 0));
	string start1 = "Enter Maze size (Max 15)";
	myDrawTextWithFont(500, 400, 70, start1, RGB(100, 0, 0), RGB(255, 255, 0));
	r = 16;
	while(r>15)
	cin >> r; c = r;
	int l = r;
	ostringstream strt;
	strt << l;
	string strtt = strt.str();
	myDrawTextWithFont(1130, 400, 70, strtt, RGB(100, 00, 0), RGB(225, 225, 0));
	string start2 = "Enter Rat Location";
	myDrawTextWithFont(500, 500, 70, start2, RGB(100, 0, 0), RGB(255, 255, 0));
	sx = 16;
	while (sx > r)
	{
		cin >> sx;
	}
	int l1 = sx;
	ostringstream obj;
	obj << l1;
	string so = obj.str();
	myDrawTextWithFont(1030, 500, 70, so, RGB(100, 00, 0), RGB(225, 225, 0));
	sy = 16;
	while (sy > r)
	{
		cin >> sy;

	}
	int l2 = sy;
	ostringstream obj1;
	obj1 << l2;
	string soo = obj1.str();
	myDrawTextWithFont(1170, 500, 70, soo, RGB(100, 00, 0), RGB(225, 225, 0));
	string start3 = "Enter Cheez Location";
	myDrawTextWithFont(500, 600, 70, start3, RGB(100, 0, 0), RGB(255, 255, 0));
	dx = 16;
	while (dx > r)
	{
		cin >> dx;
	}
	int l3 = dx;
	ostringstream objj;
	objj << l3;
	string sooo = objj.str();
	myDrawTextWithFont(1030, 600, 70, sooo, RGB(100, 00, 0), RGB(225, 225, 0));
	dy = 16;
	while(dy > r)
	cin >> dy;
	int l4 = dy;
	ostringstream obj12;
	obj12 << l4;
	string soooo = obj12.str();
	myDrawTextWithFont(1170, 600, 70, soooo, RGB(100, 00, 0), RGB(225, 225, 0));

	ClearScreen();
}
void Second_Page(int  ** &arr1,int ** arr,int ** temp,int r, int c,int X, int Y, int X1, int Y1,int sx, int sy, int dx,int dy)
{
	string str = "Rat In Maze Problem";
	myDrawTextWithFont(700, 50, 70, str, RGB(100, 0, 0), RGB(255, 255, 0));

	string str1 = "Solution With Stack";
	myDrawTextWithFont(X, 150, 70, str1, RGB(100, 0, 0), RGB(255, 255, 0));

	//Loading maze1
	 arr1 = Load_Maze(arr, r, c, X, Y, sx, sy, dx, dy);

	string str2 = "Solution With Queue";
	myDrawTextWithFont(X1 + 300, 150, 70, str2, RGB(100, 0, 0), RGB(255, 255, 0));

	//loading maze2
	Load_Maze2(arr1, temp, r, c, X1, Y1, sx, sy, dx, dy);

}
void Solution_By_Stack(int**& arr1, int** arr, int** temp, int r, int c, int X, int Y, int X1, int Y1, int sx, int sy, int dx, int dy)
{
	//creating Stack
	Linklist<point> ::Stack s(r * c, r, c);
	point p;
	p.set(sx, sy);
	int i = sx;
	int j = sy;
	// Pushing source toStack
	s.Push(p);

	// trversing Maze to source
	Traversing_Maze(arr, r, c, sx, sy, X, Y);

	//Q1 Part(a) Using Stack 
	while (arr[i][j] != destination && !s.IsEmpty())
	{
		if (Right == true)
		{
			if (j + 1 < c && arr[i][j + 1] != hurdle && arr[i][j + 1] != passed && arr[i][j + 1] != blocked && arr[i][j + 1] != source) //right
			{

				if (arr[i][j] != source)
				{
					myRect(X, Y, X + 50, Y + 50, RGB(0, 100, 0), RGB(240, 248, 255));
					Rat(c, X, Y);
				}

				X += 51;
				j += 1;
				if (arr[i][j] != destination && arr[i][j] != source)
					arr[i][j] = passed;
				p.set(i, j);
				s.Push(p);


				Sleep(500);
				if (arr[i][j - 1] != source)
				{
					Draw_Box(arr, i, j - 1, X - 51, Y);
				}

			}
			else
			{
				Right = false;

			}
		}
		else if (Down == true)
		{
			if (i + 1 < r && arr[i + 1][j] != hurdle && arr[i + 1][j] != passed && arr[i + 1][j] != blocked && arr[i + 1][j] != source)//down
			{
				Rat(c, X, Y);
				if (arr[i][j] != source)
				{
					myRect(X, Y, X + 50, Y + 50, RGB(0, 100, 0), RGB(240, 248, 255));
					Rat(c, X, Y);
				}


				i += 1;
				Y += 51;
				if (arr[i][j] != destination && arr[i][j] != source)
					arr[i][j] = passed;
				p.set(i, j);

				s.Push(p);

				Sleep(500);
				if (arr[i - 1][j] != source)
				{
					Draw_Box(arr, i - 1, j, X, Y - 51);
				}

			}
			else
			{
				Down = false;
				Right = true;

			}
		}
		else if (Left == true)
		{
			if (j - 1 >= 0 && arr[i][j - 1] != hurdle && arr[i][j - 1] != passed && arr[i][j - 1] != blocked && arr[i][j - 1] != source) //left
			{
				Rat(c, X, Y);
				if (arr[i][j] != source)
				{
					myRect(X, Y, X + 50, Y + 50, RGB(0, 100, 0), RGB(240, 248, 255));
					Rat(c, X, Y);
				}


				X -= 51;
				j -= 1;
				if (arr[i][j] != destination)
					arr[i][j] = passed;
				p.set(i, j);

				s.Push(p);
				Sleep(500);
				if (arr[i][j + 1] != source && arr[i][j] != destination)
				{
					Draw_Box(arr, i, j + 1, X + 51, Y);
				}
			}
			else
			{
				Left = false;
				Down = true;
				Right = true;

			}

		}
		else if (Up == true)
		{
			if (i - 1 >= 0 && arr[i - 1][j] != hurdle && arr[i - 1][j] != passed && arr[i - 1][j] != blocked && arr[i - 1][j] != source) // up
			{
				Rat(c, X, Y);
				if (arr[i][j] != source)
				{
					myRect(X, Y, X + 50, Y + 50, RGB(0, 100, 0), RGB(240, 248, 255));
					Rat(c, X, Y);
				}

				Y -= 51;
				i -= 1;
				if (arr[i][j] != destination && arr[i][j] != source)
					arr[i][j] = passed;
				p.set(i, j);
				s.Push(p);


				Sleep(500);
				if (arr[i + 1][j] != source)
				{
					Draw_Box(arr, i + 1, j, X, Y + 51);
				}

			}
			else
			{
				Up = false;
				Right = true;
				Left = true;
				Down = true;
			}
		}
		else
		{

			if (!s.IsEmpty())
			{
				myRect(X, Y, X + 50, Y + 50, RGB(0, 100, 0), RGB(240, 248, 255));
				Rat(c, X, Y);
				Sleep(500);


				point P = s.Pop();
				i = P.getX();
				j = P.getY();

				if (!s.IsEmpty())
				{
					if (arr[i][j] != destination && arr[i][j] != source)
						arr[i][j] = blocked;

					int x = 50, y = 250;
					Traversing_Maze_to_Poped_Element(arr, r, c, i, j, x, y);

					P = s.Pop();
					i = P.getX();
					j = P.getY();

					y = 250; x = 50;
					Traversing_Maze_to_Poped_Element_no_print(arr, r, c, i, j, x, y);


					s.Push(P);
					X = x;
					Y = y;

					Right = true;
					Left = true;
					Up = true;
					Down = true;

				}
			}
		}

	}
	//Back tracking
	Back_Tracking(s, r, c, 50, 250);

}
void Solution_By_Queue(int**& arr1, int** arr, int** temp, int r, int c, int X, int Y, int X1, int Y1, int sx, int sy, int dx, int dy)
{
	int i = 0, j = 0;
	Traversing_Maze(arr1, r, c, sx, sy, X1, Y1);

	Linklist<point> ::Queuee q(r * c);
	Linklist<point> ::Queuee qt(r * c);
	Linklist<point> ::Queuee label(r * c);
	Linklist<point> ::Queuee color(r * c);

	point p;
	int labl = 0; int co = 0;
	p.set(sx, sy);
	i = sx;
	j = sy;
	q.Enqueue(p);

	p.set(X1, Y1);
	qt.Enqueue(p);

	p.set(0, 0);
	label.Enqueue(p);

	p.set(0, 0);
	color.Enqueue(p);


	while (arr1[i][j] != destination && !q.IsEmpty())
	{


		point l = q.Dequeue();
		i = l.getX();
		j = l.getY();
		l = qt.Dequeue();
		X1 = l.getX();
		Y1 = l.getY();
		l = label.Dequeue();
		labl = l.getX();
		l = color.Dequeue();
		co = l.getX();


		if (arr1[i][j] != destination)
		{


			if (j + 1 < c && arr1[i][j + 1] != hurdle && arr1[i][j + 1] != passed && arr1[i][j + 1] != blocked && arr1[i][j + 1] != source) //right
			{

				if (arr1[i][j + 1] != destination)

					myRect(X1 + 50, Y1, X1 + 100, Y1 + 50, RGB(0, 100, 0), RGB(co, co + 20, co + 40));
				Rat_With_Label(c, X1 + 50, Y1, labl + 1);


				if (arr1[i][j + 1] != destination)
					arr1[i][j + 1] = passed;
				temp[i][j + 1] = labl + 1;
				p.set(i, j + 1);
				q.Enqueue(p);
				p.set(X1 + 51, Y1);
				qt.Enqueue(p);
				p.set(labl + 1, 0);
				label.Enqueue(p);
				p.set(co + 50, 0);
				color.Enqueue(p);
				if (arr1[i][j + 1] == destination)
					break;
				//Sleep(500);
				//  Draw_Box(arr1, i, j - 1, X1 - 51, Y1);


			}

			Sleep(300);
			if (i + 1 < r && arr1[i + 1][j] != hurdle && arr1[i + 1][j] != passed && arr1[i + 1][j] != blocked && arr1[i + 1][j] != source)//down
			{

				if (arr1[i + 1][j] != destination)
					myRect(X1, Y1 + 50, X1 + 50, Y1 + 100, RGB(0, 100, 0), RGB(co, co + 20, co + 40));
				Rat_With_Label(c, X1, Y1 + 50, labl + 1);

				if (arr1[i + 1][j] != destination)
					arr1[i + 1][j] = passed;
				temp[i + 1][j] = labl + 1;
				p.set(i + 1, j);
				q.Enqueue(p);
				p.set(X1, Y1 + 51);
				qt.Enqueue(p);
				p.set(labl + 1, 0);
				label.Enqueue(p);
				p.set(co + 50, 0);
				color.Enqueue(p);
				//Sleep(500);
				if (arr1[i + 1][j] == destination)
					break;


			}
			Sleep(300);
			if (j - 1 >= 0 && arr1[i][j - 1] != hurdle && arr1[i][j - 1] != passed && arr1[i][j - 1] != blocked && arr1[i][j - 1] != source) //left
			{

				if (arr1[i][j - 1] != destination)
					myRect(X1 - 50, Y1, X1, Y1 + 50, RGB(0, 100, 0), RGB(co, co + 20, co + 40));
				Rat_With_Label(c, X1 - 50, Y1, labl + 1);


				if (arr1[i][j - 1] != destination)
					arr1[i][j - 1] = passed;
				temp[i][j - 1] = labl + 1;
				p.set(i, j - 1);
				q.Enqueue(p);
				p.set(X1 - 51, Y1);
				qt.Enqueue(p);
				p.set(labl + 1, 0);
				label.Enqueue(p);
				p.set(co + 50, 0);
				color.Enqueue(p);
				if (arr1[i][j - 1] == destination)
					break;
				//Draw_Box(arr1, i, j + 1, X1 + 51, Y1);

			}

			Sleep(300);
			if (i - 1 >= 0 && arr1[i - 1][j] != hurdle && arr1[i - 1][j] != passed && arr1[i - 1][j] != blocked && arr1[i - 1][j] != source) // up
			{
				if (arr1[i - 1][j] != destination)
					myRect(X1, Y1 - 50, X1 + 50, Y1, RGB(0, 100, 0), RGB(co, co + 20, co + 40));
				Rat_With_Label(c, X1, Y1 - 50, labl + 1);

				if (arr1[i - 1][j] != destination)
					arr1[i - 1][j] = passed;
				temp[i - 1][j] = labl + 1;
				p.set(i - 1, j);
				q.Enqueue(p);
				p.set(X1, Y1 - 51);
				qt.Enqueue(p);
				p.set(labl + 1, 0);
				label.Enqueue(p);
				p.set(co + 50, 0);
				color.Enqueue(p);
				if (arr1[i - 1][j] == destination)
					break;
				//Draw_Box(arr1, i + 1, j, X1, Y1 + 51);


			}

			Sleep(300);
		}



	}

	X1 = 1100, Y1 = 250;
	Sleep(500);
	Back_Tracking2(temp, r, c, dx, dy, X1, Y1);
}


int main()
{

	int key; int i; int j; point p;
	bool pop = false;
	bool stop = false;
	bool specialKey = false;
	int X = 50, Y = 250;
	int X1 = 1100, Y1 = 250;
	int r, c; 	int sx, sy; int dx, dy;
	

	// Displaying Manue
	Manue(r, c, sx, sy, dx, dy);


	// Creating asrray for Maze
	int** arr = new int* [r];
	for (int i = 0; i < r; i++)
	{
		arr[i] = new int[c];
	}
	int** temp = new int* [r];
	for (int i = 0; i < r; i++)
	{
		temp[i] = new int[c];
	}
	int** arr1;
	Load_Array(temp, r, c);

	//Loading second page
	Second_Page(arr1, arr,temp, r, c, X, Y, X1, Y1, sx, sy, dx, dy);

	key = CheckWhichKeyPressed(specialKey);
	while (stop != true)
	{

		key = CheckWhichKeyPressed(specialKey);
		if (key == ESCKEY)
		{
			stop = true;
		}

		//Q1 Part(a) Using Stack    
		else if (key == LEFTKEY)
		{
			Solution_By_Stack(arr1, arr, temp, r, c, X, Y, X1, Y1, sx, sy, dx, dy);
		}

		//Q1 Part(b) Using Queue 
		else if (key == RIGHTKEY)
		{

			Solution_By_Queue(arr1, arr, temp, r, c, X, Y, X1, Y1, sx, sy, dx, dy);
		}

		//Both have O(n^2)
	 }

}