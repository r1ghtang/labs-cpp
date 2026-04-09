#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

// Базовый класс Point
class Point {
protected:
    int x, y;      // координаты объекта
    int cvet;      // цвет объекта

public:
    // Конструктор без параметров
    Point() {
        x = 0;
        y = 0;
        cvet = WHITE;
    }

    // Конструктор с параметрами
    Point(int xn, int yn, int color) {
        x = xn;
        y = yn;
        cvet = color;
    }

    // Виртуальный метод показа объекта
    virtual void Show() {
    }

    // Виртуальный метод скрытия объекта
    virtual void Hide() {
    }

    // Метод получения координат
    void Locat(int& xl, int& yl) {
        xl = x;
        yl = y;
    }

    // Метод перемещения объекта по экрану
    void Fly(int cost) {
        int xx, yy;

        Show();
        randomize();

        do {
            // Генерируем новую координату X
            do {
                xx = x + round((rand() / (double)RAND_MAX - 0.5) * cost);
            } while (xx <= 0 || xx >= getmaxx());

            // Генерируем новую координату Y
            do {
                yy = y + round((rand() / (double)RAND_MAX - 0.5) * cost);
            } while (yy <= 0 || yy >= getmaxy());

            Hide();
            x = xx;
            y = yy;
            Show();

            delay(300); // небольшая пауза для эффекта движения
        } while (!kbhit());
    }
};

// Класс Krug наследуется от Point
class Krug : public Point {
protected:
    int radius; // радиус круга

public:
    // Конструктор без параметров
    Krug() : Point() {
        radius = 10;
    }

    // Конструктор с параметрами
    Krug(int xn, int yn, int r, int color) : Point(xn, yn, color) {
        radius = r;
    }

    // Показ круга
    virtual void Show() {
        setcolor(cvet);
        setfillstyle(SOLID_FILL, cvet);
        fillellipse(x, y, radius, radius);
    }

    // Скрытие круга
    virtual void Hide() {
        setcolor(getbkcolor());
        setfillstyle(SOLID_FILL, getbkcolor());
        fillellipse(x, y, radius, radius);
    }
};

// Класс Ring наследуется от Krug
class Ring : public Krug {
protected:
    int width; // толщина кольца

public:
    // Конструктор без параметров
    Ring() : Krug() {
        width = 5;
    }

    // Конструктор с параметрами
    Ring(int xn, int yn, int r, int color, int wid) : Krug(xn, yn, r, color) {
        width = wid;
    }

    // Показ кольца
    virtual void Show() {
        // Рисуем внешний круг
        setcolor(cvet);
        setfillstyle(SOLID_FILL, cvet);
        fillellipse(x, y, radius, radius);

        // Закрашиваем внутреннюю часть цветом фона
        setcolor(getbkcolor());
        setfillstyle(SOLID_FILL, getbkcolor());
        fillellipse(x, y, radius - width, radius - width);
    }

    // Скрытие кольца
    virtual void Hide() {
        setcolor(getbkcolor());
        setfillstyle(SOLID_FILL, getbkcolor());
        fillellipse(x, y, radius, radius);
    }
};

int main() {
    int gd = DETECT, gm;

    // Инициализация графического режима
    initgraph(&gd, &gm, "");

    setbkcolor(BLACK);
    cleardevice();

    // Создаём объекты
    Krug testKrug(150, 100, 50, RED);
    Ring testRing(450, 150, 90, GREEN, 20);

    // Показываем и двигаем круг
    testKrug.Show();
    testKrug.Fly(100);

    // Показываем и двигаем кольцо
    testRing.Show();
    testRing.Fly(60);

    getch();

    // Скрываем объекты перед завершением
    testKrug.Hide();
    testRing.Hide();

    getch();
    closegraph();

    return 0;
}
