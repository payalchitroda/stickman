#include <iostream.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
enum status
{
    running,
    pause,
    quit,
    over
};
int gamestatus = running;
int jump = 0;
class layout
{
  public:
    void background()
    {
	setcolor(RED);
	settextstyle(1, HORIZ_DIR, 1);
	outtextxy(5, 5, "Press X to Exit");
	settextstyle(1, HORIZ_DIR, 1);
	outtextxy(250, 5, "Press space to jump");
	settextstyle(1, HORIZ_DIR, 1);
	outtextxy(500, 5, "score");
	setcolor(GREEN);
	rectangle(0, 400, 800, 500);
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(2, 450, GREEN);
    }
    void score(int scr)
    {
	settextstyle(1, HORIZ_DIR, 1);
	outtextxy(550, 5, " score");
    }
    void pause()
    {
	settextstyle(1, HORIZ_DIR, 4);
	outtextxy(100, 200, "PAUSED");
	getch();
    }
    void game_over()
    {
	settextstyle(1, HORIZ_DIR, 4);
	outtextxy(100, 200, "Game Over");
	getch();
    }
};
class stickman
{

  public:
    int x;
    int y;
    stickman()
    {
	x = 30;
	y = 250;
    }
    /*stickman(int x_cor, int y_cor)
    {
	x = x_cor;
	y = y_cor;
    }*/
    void draw()
    {

	if (jump == 1)
	{
	    for (int j = 0; j < 5; j++)
	    {
		setcolor(YELLOW);
		circle(x, y, x);
		setfillstyle(SOLID_FILL, YELLOW);
		floodfill(x, y, YELLOW);
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		fillellipse(x - 10, y - 10, 2, 6);
		fillellipse(x + 10, y - 10, 2, 6);
		ellipse(x, y + 3, 205, 335, 18, 10);
		setcolor(WHITE);
		ellipse(x, y + 3, 205, 335, 18, 11);
		ellipse(x, y + 3, 205, 335, 18, 12);
		ellipse(x, y + 3, 205, 335, 18, 13);
		setcolor(BLACK);
		ellipse(x, y + 3, 205, 335, 18, 14);
		setcolor(WHITE);
		line(x, y + 30, x, y + 100);
		line(x, y + 100, x - 30, y + 150);
		line(x, y + 100, x + 30, y + 150);
		line(x - 20, y + 50, x, y + 70);
		line(x, y + 70, x + 20, y + 50);
	    }
	    x = 30;
	    y = 250;
	    jump = 0;
	}
	else
	{
	    setcolor(YELLOW);
	    circle(x, y, x);
	    setfillstyle(SOLID_FILL, YELLOW);
	    floodfill(x, y, YELLOW);
	    setcolor(BLACK);
	    setfillstyle(SOLID_FILL, BLACK);
	    fillellipse(x - 10, y - 10, 2, 6);
	    fillellipse(x + 10, y - 10, 2, 6);
	    ellipse(x, y + 3, 205, 335, 18, 10);
	    setcolor(WHITE);
	    ellipse(x, y + 3, 205, 335, 18, 11);
	    ellipse(x, y + 3, 205, 335, 18, 12);
	    ellipse(x, y + 3, 205, 335, 18, 13);
	    setcolor(BLACK);
	    ellipse(x, y + 3, 205, 335, 18, 14);
	    setcolor(WHITE);
	    line(x, y + 30, x, y + 100);
	    line(x, y + 100, x - 30, y + 150);
	    line(x, y + 100, x + 30, y + 150);
	    line(x - 20, y + 50, x, y + 70);
	    line(x, y + 70, x + 20, y + 50);
	}
    }
};
class bushes
{
  public:
    int x;
    int y;
    bushes()
    {
	x = 630;
	y = 360;
    }
    void draw()
    {
	int d = 0;
        int speed = 20;
        int gameover = 0;
        setcolor(RED);
        circle(x - d, y, 10);
        setfillstyle(WIDE_DOT_FILL, RED);
        floodfill(x - d, y, RED);
        line(x - d, y + 10, x - d, y + 40);
        d = d + speed;
        if (d == 630)
        {
            d = 0;
            speed = speed + 10;
        }

        if (d >= 610 && jump == 0)
        {
            gamestatus = over;
        }
    }
};

layout l;
bushes b;
stickman s;
void input()
{
    char ch;
    ch = getch();
    if (ch == ' ')
    {
        s.x = 30;
        s.y = s.y - 50;
        jump = 1;
        gamestatus = running;
    }
    else if (ch == 'p')
    {
        gamestatus = pause;
    }
    else if (ch == 'x')
    {
        gamestatus = quit;
    }
}
void draw()
{

    if (gamestatus == running)
    {
        l.background();
        s.draw();
        b.draw();
        l.score(5);
    }
    else if (gamestatus == over)
    {
        l.game_over();
    }
    else if (gamestatus == pause)
    {
        l.pause();
        getch;
        gamestatus = running;
    }
    else if (gamestatus == quit)
    {
        exit(0);
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setcolor(BLACK);
    cleardevice();
    while (gamestatus == running)
    {
        input();
        draw();
        // delay(100);
    }

    getch();
    closegraph();
    return 0;
}