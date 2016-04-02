#include <iostream.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void lift(int y)
{
  int nx=378,ny=418;
  if(y==1)
  {
   for(;nx>=238;nx--)
   {
    rectangle(0,2,639,140);
    rectangle(0,141,639,280);
    rectangle(0,281,639,420);
    rectangle(100,nx,200,ny);
    delay(50);
    clrscr();ny--;
   }
 }

  if(y==2)
  {
   for(;nx>=98;nx--)
   {
    rectangle(0,2,639,140);
    rectangle(0,141,639,280);
    rectangle(0,281,639,420);
    rectangle(100,nx,200,ny);
    delay(50);
    clrscr();
    ny--;
   }
 }
}

void main()
{
    /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int f;
   /* initialize graphics and local
   variables */
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   rectangle(0,2,639,140);
   rectangle(0,141,639,280);
   rectangle(0,281,639,420);
   gotoxy(40,30);
   cin>>f;
   lift(f);
   rectangle(0,2,639,140);
   rectangle(0,141,639,280);
   rectangle(0,281,639,420);
   if(f==1)
   {
   rectangle(100,238,200,278);
   }

    if(f==2)
   {
   rectangle(100,238,200,278);
   }
    getch();


    }