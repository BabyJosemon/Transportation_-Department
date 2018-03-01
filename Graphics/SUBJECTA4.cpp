#include<graphics.h>
#include<conio.h>
void main()
{ int at=DETECT, am;
      initgraph(&at, &am, "c:\\turboc3\\bgi ");
      rectangle(100, 100, 300, 300);
      setfillstyle(SOLID_FILL, RED);
      floodfill(400, 400, WHITE);
      getch();
      closegraph();
}
