#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;




class snake
{
	const int wight = 40, hight = 20;
	int x, y, fruX, fruY, score;
	bool pash = false;
public:
	enum dre { stop,UP, DOWN,LEFT,RIGHT } dir;
	int GameOver = false;

	void draw();
	void drawWin();
	void setup();
	void input();
	void logic();

};

void snake::logic()
{
	switch (dir)
	{
	case UP: y--;
		break;
	case DOWN:y++;
		break;
	case LEFT: x--;
		break;
	case RIGHT: x++;
		break;

	};

	if (x > wight - 3 || x<1 || y>hight - 2 || y < 1) GameOver = true;

	if (x == fruX && y == fruY)
	{
		score += 10;
		srand(time(NULL));
		fruX = (rand() % wight - 2);
		srand(time(NULL));
		fruY = (rand() % hight - 2);
	};
}

void snake::input()
{

	switch (_getch())
	{
	case 'w': dir = UP;
		break;
	case 's': dir = DOWN;
		break;
	case 'a': dir = LEFT;
		break;
	case 'd': dir = RIGHT;
		break;
	case 'x': GameOver = true;
		break;
	};
}

void snake::setup()
{
	srand(time(NULL));
	dir = stop;
	x = wight / 2;
	y = hight / 2;
	fruX = (rand() % wight-2);
	fruY = (rand() % hight-2);
}

void snake::drawWin()
{
	int i,j;
	system("cls");
	for (i = 0;i < wight+1;i++) cout << "#";
	cout << endl;

	for (j = 0;j < hight;j++) {
		for (i = 0;i < wight;i++) {
			if (i == 0 || i == wight - 1) cout << "#";
			if (i == x && j == y) cout << "S";
			else if (i == fruX && j == fruX) cout << "f";
			else cout << " ";
		}
		cout << endl;
	}

	for (i = 0;i < wight+1;i++) cout << "#";
	cout << endl;
	cout << "x: " << x << "\ty: " << y << endl;
	cout << "Fx: " << fruX << "\tFy: " << fruY << endl;
	
}

void snake::draw()
{
	int choice = 0;
	char ch;
	do {
		system("cls");
		switch (choice)
		{
		case 0: {
			cout << "\t\tSTART" << endl
				<< "\t\tLOAD" << endl
				<< "\t\tEXIT" << endl;
		};
			  break;
		case 1: {
			cout << "\t\t<START>" << endl
				<< "\t\tLOAD" << endl
				<< "\t\tEXIT" << endl;
		};
			  break;
		case 2: {
			cout << "\t\tSTART" << endl
				<< "\t\t<LOAD>" << endl
				<< "\t\tEXIT" << endl;
		};
			  break;
		case 3: {
			cout << "\t\tSTART" << endl
				<< "\t\tLOAD" << endl
				<< "\t\t<EXIT>" << endl;
		};
			  break;
		}
		ch = _getch();

		if (ch == 'w') {
			if (choice == 1 || choice == 0) choice = 3;
			else choice--;
		};


		if (ch == 's') {
			if (choice == 3 || choice == 0) choice = 1;
			else choice++;
		};

	} while (ch != 32);



}

int main()
{
	snake a;
	
	
		a.setup();
		a.draw();
		while (!a.GameOver)
		{
			a.drawWin();
			a.input();
			a.logic();
		}
		system("cls");
		cout << "GAME OVER!";
	
	return 0;
}