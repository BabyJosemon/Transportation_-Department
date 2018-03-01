/*
SUCCESS
*/
#include <conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
void main()
{
    int x,y,i;
    int g=DETECT, d;
    initgraph(&g, &d, "c:\\turboc3\\bgi");
    cleardevice();
    x=getmaxx()/2;
    y=getmaxy()/2;
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
    setbkcolor(rand());
    setcolor(4);
    outtextxy(30, 100, "Press");
    outtextxy(30, 130, "any");
    outtextxy(30, 160, "key");
    outtextxy(30, 190, "to");
    outtextxy(30, 220, "Quit");
    while(!kbhit())
    {
        setcolor(rand());
        for(int i=0;i<1;i++)
            circle(x,y,i);
        setcolor(rand());
        for(int j=5;j<10;j++)
            circle(x,y,j);
        setcolor(rand());
        for(int k=14;k<19;k++)
            circle(x,y,k);
        setcolor(rand());
        for(int l=23;l<28;l++)
            circle(x,y,l);

        delay(1000);
    }
    getch();
    closegraph();
}
/*
https://www.youtube.com/watch?v=1Bx5aqH0kBM
*/

