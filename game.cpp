#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
enum status
{
    running,
    pause,
    quit
};
int gamestatus = running;
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
    void draw(int w)
    {

        if (w == 2)
        {
            p = 0;
        }
        else if (w == 1)
        {
            p = -50
        }
        else
        {
            
        }
        if (w == 1)
        {
            for (int j = 0; j < 5; j++)
            {
                setcolor(YELLOW);
                circle(30, 250 + p, 30);
                setfillstyle(SOLID_FILL, YELLOW);
                floodfill(30, 250 + p, YELLOW);
                setcolor(BLACK);
                setfillstyle(SOLID_FILL, BLACK);
                fillellipse(20, 240 + p, 2, 6);
                fillellipse(40, 240 + p, 2, 6);
                ellipse(30, 253 + p, 205, 335, 18, 10);
                setcolor(WHITE);
                ellipse(30, 253 + p, 205, 335, 18, 11);
                ellipse(30, 253 + p, 205, 335, 18, 12);
                ellipse(30, 253 + p, 205, 335, 18, 13);
                setcolor(BLACK);
                ellipse(30, 253 + p, 205, 335, 18, 14);
                setcolor(WHITE);
                line(30, 280 + p, 30, 350 + p);
                line(30, 350 + p, 0, 400 + p);
                line(30, 350 + p, 60, 400 + p);
                line(10, 300 + p, 30, 320 + p);
                line(30, 320 + p, 50, 300 + p);
            }
            p=0;
        }
    }
};
class bushes
{
  public:
    void draw(int y)
    {
        int x = 0;
        setcolor(RED);
        circle(700 - x, 360, 10);
        setfillstyle(WIDE_DOT_FILL, RED);
        floodfill(700 - x, 360, RED);
        line(700 - x, 370, 700 - x, 400);
        x = x + y;
    }
};

void input()
{
    char ch;
    ch = getch();
    if (ch =='')
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
void draw(char ch)
{
    layout l;
    bushes b;
    stickman s;
    if (gamestatus == running)
    {
        l.background();
        s.draw();
        b.draw();
        l.score();
    }
    else if (gamestatus == pause)
    {
        l.pause();
    }
    else if (gamestaus == quit)
    {
        exit();
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setcolor(BLACK);
    cleardevice();

    char ch;

    while (gamestatus == running)
    {
        input();
        draw();
    }

    getch();
    closegraph();
    return 0;
}