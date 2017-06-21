#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <time.h>

void frame()
{
 int maxx=getmaxx();
 int maxy=getmaxy();
 setcolor(4);
 rectangle(0,0,maxx,maxy);
 rectangle(1,1,maxx-1,maxy-1);
 rectangle(2,2,maxx-2,maxy-2);
}

void cir(int x,int y,int d)
{
 int r=10;
 for(int i=0;i<5;i++)
 {
  circle(x,y,r);
  r+=10;
 }
 delay(d);
 cleardevice();
 frame();
}

void main()
{
 clrscr();
 gotoxy(6,6);
 cout<<"Welcome to <SPOT> \nA unique game that you will like.";
 cout<<"\nInstructions:\nSpot the circle that fades out after some time.\nYou will get five oppertunities.So, make the most of it.!";
 cout<<"\nControls:\nUse W, A, D, S to move (up), (left), (right) and (down) respectively. When you finally know the position press (L) to confirm...Its easy..Try it!";
 cout<<"\nEnter any key to continue :-)";
 getch();
 /* Code for getting graphics to work.
   Check the refernace in sample graphics.h file */
 int gdriver = DETECT, gmode, errorcode;
 initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
 setbkcolor(4);
 frame();
 unsigned int seedval;
 // Calculate time.
 time_t t;
 seedval=(unsigned)time(&t);
 srand(seedval);

  int x=3,y=14;
  int nmaxx=619;
  int nmaxy=474;

  int score=0;
  int d=4000;
  int level=1;
 level:  // Setting level. With each level increase, we decrement the time.
   int i=(rand()%569)+53;
   int j=(rand()%424)+64;
   cleardevice();
   setbkcolor(8);
   frame();
   cir(i,j,d);
  again:
 int r=0;

 cleardevice();
 frame();
 setcolor(15);
 line(x,y,x+14,y);
 char a = getch();

 if(a=='a')
 {
  if(x>3&&x<=nmaxx)
  {
   x-=14;
  }
   goto again;
 }

 else if(a=='d')
 {
  if(x>=3&&x<nmaxx)
  {
    x+=14;
  }
  goto again;
 }

 else if(a=='s')
 {
  if(y>=14&&y<nmaxy)
  {
   y+=10;
  }
  goto again;
 }

 else if(a=='w')
 {
  if(y>14&&y<=nmaxy)
  {
   y-=10;

  }
  goto again;
 }

 else if(a=='l')
 {
   if(x==i&&y==j)
   {
    r=50;
    score+=r;

   }
   else if(x==i&&y>j)
    {
      if(y-j>=0&&y-j<=15)
      {
       r=40;
       score+=r;

      }
   else if(y-j>=16&&y-j<=30)
    {
      r=30;
      score+=r;
    }
   else if(y-j>=31&&y-j<=45)
    {
      r=20;
      score+=r;
     }

    else if(y-j>=46&&y-j<=60)
     {
       r=40;
       score+=r;
     }

   }
   else if(x==i&&j>y)
   {
     if(j-y>=0&&j-y<=15)
     {
       r=40;
       cout<<r;
       score+=r;


     }
    else if(j-y>=16&&j-y<=30)
     {
       r=30;
       score+=r;


     }
   else if(j-y>=31&&j-y<=45)
     {
       r=20;
       score+=r;


     }

   else if(j-y>=46&&j-y<=60)
     {
       r=10;
       score+=r;


     }


   }

   else if(x>i&&y==j)
   {
     if(x-i>=0&&x-i<=15)
     {
       r=40;
       score+=r;


     }
    else if(x-i>=16&&x-i<=30)
     {
       r=30;
       score+=r;


     }
   else if(x-i>=31&&x-i<=45)
     {
       r=20;
       score+=r;


     }

   else if(x-i>=46&&x-i<=60)
     {
       r=10;
       score+=r;


     }


   }


 else if(i>x&&y==j)
   {
     if(i-x>=0&&i-x<=15)
     {
       r=40;
       score+=r;


     }
    else if(i-x>=16&&i-x<=30)
     {
       r=30;
       score+=r;


     }
   else if(i-x>=31&&i-x<=45)
     {
       r=20;
       score+=r;


     }

   else if(i-x>=46&&i-x<=60)
     {
       r=10;
       score+=r;


     }


   }


   else if(y>j)
   {
      if(y-j>=0&&y-j<=15)
      {
       if(x>i)
       {


       if(x-i>=0&&x-i<=15)
       {
       r=40;
       score+=r;


       }
       else if(x-i>=16&&x-i<=30)
      {
       r=30;
       score+=r;


       }
       else if(x-i>=31&&x-i<=45)
       {
       r=20;
       score+=r;


       }

       else if(x-i>=46&&x-i<=60)
       {
       r=10;
       score+=r;


	}

     }
   else if(i>x)
    {
     if(i-x>=0&&i-x<=15)
      {
       r=40;
       score+=r;


      }
     else if(i-x>=16&&i-x<=30)
     {
       r=30;
       score+=r;


      }
    else if(i-x>=31&&i-x<=45)
      {
       r=20;
       score+=r;


      }

     else if(i-x>=46&&i-x<=60)
     {
       r=10;
       score+=r;


     }


   }
   }
   else if(y-j>=16&&y-j<=30)
     {
       if(x>i)
       {
       if(x-i>=0&&x-i<=15)
      {
       r=40;
       score+=r;


      }
     else if(x-i>=16&&x-i<=30)
     {
       r=30;
       score+=r;


     }
    else if(x-i>=31&&x-i<=45)
     {
       r=20;
       score+=r;


     }

   else if(x-i>=46&&x-i<=60)
     {
       r=10;
       score+=r;


     }

   }
   else if(i>x)
   {
     if(i-x>=0&&i-x<=15)
     {
       r=40;
       score+=r;

     }
    else if(i-x>=16&&i-x<=30)
     {
       r=30;
       score+=r;

     }
   else if(i-x>=31&&i-x<=45)
     {
       r=20;
       score+=r;

     }

   else if(i-x>=46&&i-x<=60)
     {
       r=10;
       score+=r;


     }

   }
   }
    else if(y-j>=31&&y-j<=45)
     {

      if(x>i)
     {
      if(x-i>=0&&x-i<=15)
     {
       r=40;
       score+=r;


     }
    else if(x-i>=16&&x-i<=30)
     {
       r=30;
       score+=r;


     }
   else if(x-i>=31&&x-i<=45)
     {
       r=20;
       score+=r;


     }

   else if(x-i>=46&&x-i<=60)
     {
       r=10;
       score+=r;


     }

    }
  else if(i>x)
   {
     if(i-x>=0&&i-x<=15)
     {
       r=40;
       score+=r;


     }
    else if(i-x>=16&&i-x<=30)
     {
       r=30;
       score+=r;


     }
   else if(i-x>=31&&i-x<=45)
     {
       r=20;
       score+=r;


     }

   else if(i-x>=46&&i-x<=60)
     {
       r=10;
       score+=r;


     }


   }
   }
   else if(y-j>=46&&y-j<=60)
     {
      if(x>i)
     {
      if(x-i>=0&&x-i<=15)
     {
       r=40;
       score+=r;


     }
    else if(x-i>=16&&x-i<=30)
     {
       r=30;
       score+=r;


     }
   else if(x-i>=31&&x-i<=45)
     {
       r=20;
       score+=r;


     }

   else if(x-i>=46&&x-i<=60)
     {
       r=10;
       score+=r;


     }

    }

  else if(i>x)
   {
     if(i-x>=0&&i-x<=15)
     {
       r=40;
       score+=r;


     }
    else if(i-x>=16&&i-x<=30)
     {
       r=30;
       score+=r;


     }
   else if(i-x>=31&&i-x<=45)
     {
       r=20;
       score+=r;


     }

   else if(i-x>=46&&i-x<=60)
     {
       r=10;
       score+=r;


     }


   }
  }

  }
    else if(j>y)
   {
     if(j-y>=0&&j-y<=15)
     {
      if(x>i)
     {

      if(x-i>=0&&x-i<=15)
     {
       r=40;
       score+=r;


     }
    else if(x-i>=16&&x-i<=30)
     {
       r=30;
       score+=r;


     }
   else if(x-i>=31&&x-i<=45)
     {
       r=20;
       score+=r;


     }

   else if(x-i>=46&&x-i<=60)
     {
       r=10;
       score+=r;


     }

   }
  else if(i>x)
   {
     if(i-x>=0&&i-x<=15)
     {
       r=40;
       score+=r;


     }
    else if(i-x>=16&&i-x<=30)
     {
       r=30;
       score+=r;


     }
   else if(i-x>=31&&i-x<=45)
     {
       r=20;
       score+=r;


     }

   else if(i-x>=46&&i-x<=60)
     {
       r=10;
       score+=r;


     }


   }
  }
   else if(j-y>=16&&j-y<=30)
     {

      if(x>i)
    {
      if(x-i>=0&&x-i<=15)
     {
       r=40;
       score+=r;


     }
    else if(x-i>=16&&x-i<=30)
     {
       r=30;
       score+=r;


     }
   else if(x-i>=31&&x-i<=45)
     {
       r=20;
       score+=r;


     }

   else if(x-i>=46&&x-i<=60)
     {
       r=10;
       score+=r;


     }

   }

  else if(i>x)
   {
     if(i-x>=0&&i-x<=15)
     {
       r=40;
       score+=r;


     }
    else if(i-x>=16&&i-x<=30)
     {
       r=30;
       score+=r;


     }
   else if(i-x>=31&&i-x<=45)
     {
       r=20;
       score+=r;


     }

   else if(i-x>=46&&i-x<=60)
     {
       r=10;
       score+=r;


     }

   }
   }
   else if(y-j>=31&&y-j<=45)
     {
      if(x>i)
      {
      if(x-i>=0&&x-i<=15)
     {
       r=40;
       score+=r;


     }
    else if(x-i>=16&&x-i<=30)
     {
       r=30;
       score+=r;


     }
   else if(x-i>=31&&x-i<=45)
     {
       r=20;
       score+=r;


     }

   else if(x-i>=46&&x-i<=60)
     {
       r=10;
       score+=r;


     }

   }
  else if(i>x)
   {
     if(i-x>=0&&i-x<=15)
     {
       r=40;
       score+=r;


     }
    else if(i-x>=16&&i-x<=30)
     {
       r=30;
       score+=r;


     }
   else if(i-x>=31&&i-x<=45)
     {
       r=20;
       score+=r;


     }

   else if(i-x>=46&&i-x<=60)
     {
       r=10;
       score+=r;


     }


   }
   }
   else if(y-j>=46&&y-j<=60)
     {
      if(x>i)
     {
      if(x-i>=0&&x-i<=15)
     {
       r=40;
       score+=r;


     }
    else if(x-i>=16&&x-i<=30)
     {
       r=30;
       score+=r;


     }
   else if(x-i>=31&&x-i<=45)
     {
       r=20;
       score+=r;


     }

   else if(x-i>=46&&x-i<=60)
     {
       r=10;
       score+=r;


     }

   }
  else if(i>x)
   {
     if(i-x>=0&&i-x<=15)
     {
       r=40;
       score+=r;


     }
    else if(i-x>=16&&i-x<=30)
     {
       r=30;
       score+=r;


     }
   else if(i-x>=31&&i-x<=45)
     {
       r=20;
       score+=r;


     }

   else if(i-x>=46&&i-x<=60)
     {
       r=10;
       score+=r;
     }

   }
  }
 }
   level++;
   d-=950;
   if(level<=5&&r>0)
   {
   cleardevice();
   setbkcolor(GREEN);
   gotoxy(20,10);
   cout<<"Your Score="<<score;
   cout<<"\nPress Any key to goto next stage";
   getch();
   goto level;
   }
  else if(level>5&&r!=0)
  {
   cleardevice();
   setbkcolor(GREEN);
   gotoxy(20,10);
   cout<<"Your Score="<<score;
   getch();
   for(int pr=0;pr<14;pr++)
   {
    cleardevice();
    gotoxy(20,10);
    cout<<"You Win." ;
    setbkcolor(pr);
    delay(150);
   }
   cleardevice();
   gotoxy(10,15);
   cout<<"Credits";

   gotoxy(5,16);
   cout<<"Concept              \tAbhishek";
   gotoxy(5,17);
   cout<<"Developer 1      \tAbhishek";
   gotoxy(5,18);
   cout<<"Developer 2      \tRishav";
   for(int j =1;j<=25;j++)
   {
    gotoxy(1,1);
    delline();
    delay(200);
   }

   cleardevice();
   gotoxy(5,21);
   cout<<"Thanks For Playing...";
   for( j=1;j<=25;j++)
   {
    gotoxy(1,1);
    delline();
    delay(100);
   }
  }
 else
 {
   cleardevice();
   setbkcolor(GREEN);
   gotoxy(20,10);
   cout<<"Your Score="<<score;
   getch();
   for(int pr=0;pr<14;pr++)
   {
    cleardevice();
    gotoxy(20,10);
    cout<<"You Lost." ;
    setbkcolor(pr);
    delay(150);
   }
   cleardevice();
   gotoxy(10,15);
   cout<<"Credits";

   gotoxy(5,16);
   cout<<"Concept           \tAbhishek";
   gotoxy(5,17);
   cout<<"Developer 1      \tAbhishek";
   gotoxy(5,18);
   cout<<"Developer 2      \tRishav";

   for(int j=1;j<=25;j++)
   { gotoxy(1,1);
     delline();
     delay(200);
   }
   cleardevice();
   gotoxy(5,21);
   cout<<"Thanks For Playing...";
   for(j=1;j<=25;j++)
   {
    gotoxy(1,1);
    delline();
    delay(100);
   }
 }

}
 exit(1);
 getch();
}