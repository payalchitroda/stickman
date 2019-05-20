#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
int t, speed = 40;
void man(int w);
void layout(int w)
{
    //int gd = DETECT, gm;

    // initgraph(&gd, &gm, "C:\\TC\\BGI");

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
    // delay(100);
    man(w);
}
void man(int w)
{
    if (w == 2)
    {
        setcolor(YELLOW);
        circle(20 + 10, 250, 30);
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(20 + 10, 250, YELLOW);
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(10 + 10, 240, 2, 6);
        fillellipse(30 + 10, 240, 2, 6);
        ellipse(20 + 10, 253, 205, 335, 18, 10);
        setcolor(WHITE);
        ellipse(20 + 10, 253, 205, 335, 18, 11);
        ellipse(20 + 10, 253, 205, 335, 18, 12);
        ellipse(20 + 10, 253, 205, 335, 18, 13);
        setcolor(BLACK);
        ellipse(20 + 10, 253, 205, 335, 18, 14);
        setcolor(WHITE);
        line(20 + 10, 280, 20 + 10, 350);
        line(20 + 10, 350, -10 + 10, 400);
        line(20 + 10, 350, 50 + 10, 400);
        line(0 + 10, 300, 20 + 10, 320);
        line(20 + 10, 320, 40 + 10, 300);
        setcolor(WHITE);
        delay(200);
        cleardevice();
    }
    else if (w == 1)
    {
        setcolor(YELLOW);
        circle(20+ 10, 250 - 50, 30);
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(20+ 10, 250 - 50, YELLOW);
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(10+ 10, 240 - 50, 2, 6);
        fillellipse(30+ 10, 240 - 50, 2, 6);
        ellipse(20+ 10, 253 - 50, 205, 335, 18, 10);
        setcolor(WHITE);
        ellipse(20+ 10, 253 - 50, 205, 335, 18, 11);
	ellipse(20+ 10, 253 - 50, 205, 335, 18, 12);
	ellipse(20+ 10, 253 - 50, 205, 335, 18, 13);
	setcolor(BLACK);
	ellipse(20+ 10, 253 - 50, 205, 335, 18, 14);
	setcolor(WHITE);
	line(20+ 10, 280 - 50, 20+ 10, 350 - 50);
	line(20+ 10, 350 - 50, -10+ 10, 400 - 50);
	line(20+ 10, 350 - 50, 50+ 10, 400 - 50);
	line(0+ 10, 300 - 50, 20+ 10, 320 - 50);
	line(20+ 10, 320 - 50, 40+ 10, 300 - 50);
	setcolor(WHITE);
	delay(200);
	cleardevice();
    }
}

void obj()
{   int jump;
    static int x = 0, scr = 0;

	if (x == 650 && jump != 1)
	{
	    scr = 0;
	    speed = 40;
	    settextstyle(1, HORIZ_DIR, 4);
	    outtextxy(100, 200, "Game Over");
	    getch();
	}
	setcolor(RED);
	circle(700 - x, 360, 10);
	setfillstyle(WIDE_DOT_FILL, RED);
	floodfill(700 - x, 360, RED);
	line(700 - x, 370, 700 - x, 400);
	x = x + 20;
	if (x == 699)
	{
	    x = 0;
	    scr++;
	    settextstyle(1, HORIZ_DIR, 1);
	    outtextxy(550, 5, " scr");
	    if (speed > 20)
		speed--;
	}
	delay(speed);

}
int main()
{
    char ch;
    int i, jump;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    while (1)
    {
	jump = 0;
	while (!kbhit())
	{
	    layout(2);
	    obj();
	}
	ch = getch();
	if (ch == ' ')
	{
	    jump = 1 ;
	    for (i = 0; i < 5; i++)
	    {
		layout(1);
		obj();
	    }
            for (i = 0; i < 10; i++)
            {
                layout(2);
                obj();
            }
        }
        else if (ch == 'x')
            return 0;
    }
    getch();
    closegraph();
}
