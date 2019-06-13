#include <iostream.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
enum status
{
    running,
    pause,
    quit,
    over
};
int gamestatus;
int jump = 0;
int start = 0;
int scr = 0;
class layout
{
  public:
    void start()
    {
        setcolor(RED);
        settextstyle(1, HORIZ_DIR, 4);
        outtextxy(100, 200, "press y to start game");
    }
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
    void score()
    {
        char msg[10];
        setcolor(RED);
        settextstyle(1, HORIZ_DIR, 1);
        sprintf(msg, "%d", scr);
        outtextxy(550, 5, msg);
    }
    void pause()
    {
        setcolor(RED);
        settextstyle(1, HORIZ_DIR, 4);
        outtextxy(100, 200, "PAUSED");
        getch();
    }
    void game_over()
    {
        setcolor(RED);
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
    void draw()
    {

        setcolor(YELLOW);
        circle(x, y, 30);
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
};

int show = 0;
class bushes
{
  public:
    int x;
    int y;
    int d;
    int speed;
    bushes()
    {
        x = 620;
        y = 360;
        d = 0;
        speed = 20;
    }

    void draw()
    {

        setcolor(RED);
        circle(x - d, y, 10);
        setfillstyle(WIDE_DOT_FILL, RED);
        floodfill(x - d, y, RED);
        line(x - d, y + 10, x - d, y + 40);
    }
};

layout l;
bushes b;
stickman s;
int count = 0;
int jump_count = 0;
void input()
{

    char ch;

    ch = getch();
   // if (ch == ' ')
    if (ch == ' ' && jump_count < 1)
    {

        jump = 1;
        start = 1;
        jump_count++;
    }
    else if (ch == 'y')
    {
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
void update()
{

    if (jump == 1)
    {
        s.x = 30;
        s.y = s.y - 100;
        start = 1;
        count = 10;
        // jump = 0;
    }

    else if (count > 0)
    {
        s.y = s.y + 10;
        count--;
       
    }

    b.d = b.d + b.speed;
    if (b.d >= 620)
    {
        b.d = 0;
        scr += 1;
        b.speed = b.speed + 5;
        if (b.speed > 40)
        {
            b.speed = 20;
        }
    }

    if (b.d >= 580 && start != 1)
    {
        gamestatus = over;
    }
}

void draw()
{

    if (gamestatus == running)
    {
        l.background();
        s.draw();
        b.draw();
        l.score();
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
    l.start();
    input();
    while (gamestatus == running)
    {
        if (count == 0)
        {
            start = 0;
            jump_count=0;
        }
        jump = 0;
        setcolor(BLACK);
        cleardevice();
        if (kbhit())
        {
            //delay(100);
            input();
        }
        update();
        draw();
        delay(100);
    }
    closegraph();
    return 0;
}