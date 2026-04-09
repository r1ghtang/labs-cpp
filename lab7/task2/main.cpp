#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

// Базовый класс Point
class Point {
protected:
    int x, y;
    int cvet;

public:
    Point() {
        x = 0;
        y = 0;
        cvet = WHITE;
    }

    Point(int xn, int yn, int color) {
        x = xn;
        y = yn;
        cvet = color;
    }

    virtual void Show() {
    }

    virtual void Hide() {
    }

    void Locat(int& xl, int& yl) {
        xl = x;
        yl = y;
    }

    // Обычное перемещение
    virtual void Fly(int cost) {
        int xx, yy;

        do {
            do {
                xx = x + round((rand() / (double)RAND_MAX - 0.5) * cost);
            } while (xx <= 0 || xx >= getmaxx());

            do {
                yy = y + round((rand() / (double)RAND_MAX - 0.5) * cost);
            } while (yy <= 0 || yy >= getmaxy());

            Hide();
            x = xx;
            y = yy;
            Show();

            delay(300);
        } while (!kbhit());
    }
};

// Класс Krug
class Krug : public Point {
protected:
    int radius;

public:
    Krug() : Point() {
        radius = 10;
    }

    Krug(int xn, int yn, int r, int color) : Point(xn, yn, color) {
        radius = r;
    }

    virtual void Show() {
        setcolor(cvet);
        setfillstyle(SOLID_FILL, cvet);
        fillellipse(x, y, radius, radius);
    }

    virtual void Hide() {
        setcolor(getbkcolor());
        setfillstyle(SOLID_FILL, getbkcolor());
        fillellipse(x, y, radius, radius);
    }
};

// Класс Ring
class Ring : public Krug {
private:
    int width;

public:
    Ring() : Krug() {
        width = 5;
    }

    Ring(int xn, int yn, int r, int color, int wid) : Krug(xn, yn, r, color) {
        width = wid;
    }

    virtual void Show() {
        setcolor(cvet);
        setfillstyle(SOLID_FILL, cvet);
        fillellipse(x, y, radius, radius);

        setcolor(getbkcolor());
        setfillstyle(SOLID_FILL, getbkcolor());
        fillellipse(x, y, radius - width, radius - width);
    }

    virtual void Hide() {
        setcolor(getbkcolor());
        setfillstyle(SOLID_FILL, getbkcolor());
        fillellipse(x, y, radius, radius);
    }

    // Увеличение толщины кольца
    void Expand() {
        if (width < radius - 1) {
            Hide();
            width += 2;
            Show();
        }
    }

    // Уменьшение толщины кольца
    void Narrow() {
        if (width > 1) {
            Hide();
            width -= 2;
            Show();
        }
    }

    // Смена цвета кольца
    void ChangeColor(int newColor) {
        Hide();
        cvet = newColor;
        Show();
    }

    // Перемещение с одновременной сменой цвета
    void FlyWithColor(int cost) {
        int xx, yy;

        do {
            do {
                xx = x + round((rand() / (double)RAND_MAX - 0.5) * cost);
            } while (xx <= 0 || xx >= getmaxx());

            do {
                yy = y + round((rand() / (double)RAND_MAX - 0.5) * cost);
            } while (yy <= 0 || yy >= getmaxy());

            Hide();

            x = xx;
            y = yy;

            // Случайно меняем цвет
            cvet = 1 + rand() % 15;

            Show();
            delay(300);
        } while (!kbhit());
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setbkcolor(BLACK);
    cleardevice();
    srand(time(0));

    Ring testRing(300, 200, 80, YELLOW, 15);

    // Показываем объект
    testRing.Show();
    getch();

    // Расширяем кольцо
    for (int i = 0; i < 5; i++) {
        testRing.Expand();
        delay(300);
    }

    // Сужаем кольцо
    for (int i = 0; i < 5; i++) {
        testRing.Narrow();
        delay(300);
    }

    // Меняем цвет
    testRing.ChangeColor(RED);
    delay(700);

    testRing.ChangeColor(GREEN);
    delay(700);

    // Перемещаем со сменой цвета
    testRing.FlyWithColor(80);

    getch();
    closegraph();

    return 0;
}
