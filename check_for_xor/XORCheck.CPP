#include <iostream.h>
#include <conio.h>

int xor (int a, int b)
{
 return (a||b) && !(a&&b);
}

void main()
{
 clrscr();
 cout << xor(1,0) <<"\n";
 cout << xor(0,0) <<"\n";
 cout << xor(0,1) <<"\n";
 cout << xor(1,1);
 getch();
}