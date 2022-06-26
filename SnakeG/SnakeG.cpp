#include <iostream>
#include <random>
#include <conio.h>
#include <ctime>

using namespace std;






class snake
{
	const int wight = 40, hight = 20;
	int x, y, fruX, fruY, score;

	bool pash = false;
public:
	enum class dre { stop = 0,UP, DOWN,LEFT,RIGHT } dir = dre::stop;
	int GameOver = false;

	void draw();
	void drawWin();
	void setup();
	void logic();

};

void snake::logic()
{
	
	

		switch (_getch())
		{
		case 'w': dir = dre::UP;
			break;
		case 's': dir = dre::DOWN;
			break;
		case 'a': dir = dre::LEFT;
			break;
		case 'd': dir = dre::RIGHT;
			break;
		case 'x': GameOver = true;
			break;
		default: dir = dre::stop;
			break;
		};

		switch (dir)
		{
		case dre::UP: y--;
			break;
		case dre::DOWN:y++;
			break;
		case dre::LEFT: x--;
			break;
		case dre::RIGHT: x++;
			break;

		};

		if (x > wight - 3 || x<1 || y>hight - 2 || y < 1) GameOver = true;
		else;

		if ((x == fruX) && (y == fruY))
		{
			score += 10;

			random_device dev;
			mt19937 rng(dev());
			uniform_int_distribution<mt19937::result_type> dist6(1, hight);
			fruX = dist6(rng);

			random_device dev2;
			mt19937 rng2(dev2());
			uniform_int_distribution<mt19937::result_type> dist61(1, wight);
			fruY = dist61(rng2);


		};

	
	

}


void snake::setup()
{
	srand(time(NULL));
	dir = dre::stop;
	x = wight / 2;
	y = hight / 2;
	{
		random_device dev;
		mt19937 rng(dev());
		uniform_int_distribution<mt19937::result_type> dist6(1, hight);
		fruX = dist6(rng);

		random_device dev2;
		mt19937 rng2(dev2());
		uniform_int_distribution<mt19937::result_type> dist61(1, wight);
		fruY = dist61(rng2);


	};
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
	
	
		a.draw();
		a.setup();
		while (!a.GameOver)
		{
			a.drawWin();
			a.logic();
		}
		system("cls");
		cout << "GAME OVER!";
	
	return 0;
}