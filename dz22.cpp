#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <chrono>//clock
#include <vector>
using namespace std;

namespace windowProps
{
	int WIDTH;
	int HEIGHT;
}

void setWindowSize() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	windowProps::WIDTH = columns;
	windowProps::HEIGHT = rows - 1;
}

enum ConsoleColors {
    BLACK = 0,
    DARK_BLUE = FOREGROUND_BLUE,
    DARK_GREEN = FOREGROUND_GREEN,
    DARK_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
    DARK_RED = FOREGROUND_RED,
    DARK_MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
    DARK_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
    GRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    DARK_GRAY = FOREGROUND_INTENSITY,
    BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
    MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE

};

static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
enum Direction { LEFT, RIGHT, UP, DOWN };

void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(houtput, pos);
}


void showcursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

class Fruit {
private:
	COORD position;
	char symbol;
public:
    Fruit(int x, int y, char s) : symbol(s) {
		position.X = x;
		position.Y = y;
    }
	Fruit() :position({ 0,0 }), symbol('*') {}
	void Print() {
        SetConsoleTextAttribute(hConsole, ConsoleColors::CYAN);
		gotoxy(position.X, position.Y);
		cout << symbol;
	}
	void Clear() {
		gotoxy(position.X, position.Y);
		cout << ' ';
	}
	void SetPosition(int x, int y) {
		position.X = x;
		position.Y = y;
	}
	void changeSymbol(char s) {
		symbol = s;
	}
	COORD GetPosition()const {
		return position;
	}
};

class Hero
{
private:
    int hp;
    int h, w;
    COORD position;
    char symbol;
    string name;
    Direction dir;
	int points = 0;
	bool isIntersected = false;

    void Print(char filler)
    {

        for (int y = 0; y < h; y++)
        {
            gotoxy(position.X, position.Y + y);
            for (int x = 0; x < w; x++)
            {
                cout << filler;
            }
            cout << endl;
        }
    }


public:
    Hero() :hp(100), h(1), w(1), position({ 0,0 }), symbol('#'), name("No name"), dir(RIGHT) {}

    Hero(string name, int h, int w, char s) :hp(100), position({ 0,0 }), symbol(s), name(name), dir(RIGHT)
    {
        h > 1 ? this->h = h : this->h = 1;
        this->w = w > 0 ? w : 1;
    }

    void ShowInfo()const
    {
        cout << "========== Player [ " << name << " ] == HP : [ " << hp << " ] ===========" << endl;
    }

    void SetPosition(int x, int y)
    {
        position.X = x >= 0 ? x : 0;
        position.Y = y >= 0 ? y : 0;
    }

    void Move()
    {
        bool isMoved = false;

        switch (dir)
        {
        case LEFT: isMoved = MoveLeft(); break;
        case RIGHT:isMoved = MoveRight(); break;
        case UP:isMoved = MoveUp(); break;
        case DOWN:isMoved = MoveDown(); break;
        }
        if (!isMoved || isIntersected) {
			MarkHero();
            isIntersected = false;
        }
        else {
            PrintHero();
        }
        /*isMoved ? PrintHero() : MarkHero();*/

    }

    void MarkHero()
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::RED);
        Print(symbol);
    }

    void ChangeDirection(Direction dir)
    {
        this->dir = dir;
    }

    bool MoveRight()
    {
        if (IsValidPosition(position.X + 1, position.Y))
        {
            ClearHero();
            position.X++;
            PrintHero();
            return true;
        }
        /*ChangeDirection(LEFT);*/
        return false;
    }

    bool MoveLeft()
    {
        if (IsValidPosition(position.X - 1, position.Y))
        {
            ClearHero();
            position.X--;
            PrintHero();
            return true;
        }
        /*ChangeDirection(RIGHT);*/
        return false;
    }

    bool MoveUp()
    {
        if (IsValidPosition(position.X, position.Y - 1))
        {
            ClearHero();
            position.Y--;
            PrintHero();
            return true;
        }
        /*ChangeDirection(DOWN);*/
        return false;
    }

    bool MoveDown()
    {
        if (IsValidPosition(position.X, position.Y + 1))
        {
            ClearHero();
            position.Y++;
            PrintHero();
            return true;
        }
        ChangeDirection(UP);
        return false;
    }

    void PrintHero()
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::GREEN);
        Print(symbol);
    }

    void ClearHero()
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::BLACK);
        Print(' ');
    }

    bool IsValidPosition(int x, int y)
    {
		return x >= 0 && y >= 1 && x < windowProps::WIDTH && y < windowProps::HEIGHT;
    }

	bool IsIntersected(Fruit fruit)
	{
		COORD fruitPosition = fruit.GetPosition();

		this->isIntersected = (position.X == fruitPosition.X && position.Y == fruitPosition.Y);
		return this->isIntersected;
	}

	void incrementPoints() {
		points++;
	}

	int getPoints()const {
		return points;
	}

	void showPoints() {
		gotoxy(60, 0);
		cout << "Points: " << points;
	}   
};

int main() {
    setWindowSize();
    showcursor(false);
    Hero hero("King", 1, 1, char(219));
    hero.ShowInfo();
    hero.SetPosition(10, 10);
    hero.PrintHero();

    time_t interval = 50;
    time_t start = clock();

    Fruit fruit = Fruit(20, 20, '*');

    while (true)
    {
        if (clock() >= start + interval)
        {
            fruit.Print();
            if (hero.IsIntersected(fruit)) {
                fruit.Clear();
                hero.incrementPoints();
				fruit.SetPosition(rand() % windowProps::WIDTH, rand() % windowProps::HEIGHT);
				fruit.changeSymbol(char(65 + rand() % 26));
				fruit.Print();
            }

            hero.Move();
			hero.showPoints();
            start = clock();
        }
        if (_kbhit())
        {
            int key = _getch();
            if (key == 27) break;
            /*cout << key << endl;*/
            if (key == 224)
            {
                key = _getch();
                switch (key)
                {
                case 77: //RIGHT
                    hero.ChangeDirection(RIGHT); break;
                case 75: //LEFT
                    hero.ChangeDirection(LEFT); break;
                case 72: //UP
                    hero.ChangeDirection(UP); break;
                case 80: //DOWN
                    hero.ChangeDirection(DOWN); break;
                }
            }
        }
    }

}
