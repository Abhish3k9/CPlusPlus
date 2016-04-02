			    //PARKING MANAGEMENT
// DEVELOPED BY ABHISHEK AND ANURAG
//**************************************************
//NECESSARY HEADER FILES
//***************************************************

#include<conio.h>
#include<dos.h>
#include<fstream.h>
#include<generic.h>
#include<graphics.h>
#include<iomanip.h>
#include<iostream.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//***************************************************
//GLOBAL VARIABLES
//***************************************************
int a,c=0,f=0,j=0;

void modi(int,int);
int tokenno();
int tokennob();
int tokennoc();

void DATE_TIME()                  //func to add DATE & TIME
{
   clrscr();  textcolor(RED);
   struct date d;
   getdate(&d);
   cout<<"\t\t\t\t\t\t\t\t Date:"<<(int)d.da_day<<"/"<<(int)d.da_mon<<"/"<<d.da_year;
   struct time t;
   gettime(&t);
   printf("\t\t\t\t\t\t\t\t       Time is:%2d:%02d:%02d\n",
     t.ti_hour, t.ti_min, t.ti_sec);
 }

void password()
{
 clrscr();
 char ch,pass[15]=" ";
 X:
 cout<<"\nWelcome Administrator";
 cout<<"\nEnter Password : ";
 for(int i=0;i<15;i++)
 {
  ch=getch();
  if(ch==(int)13){pass[i]='\0';break;}
  else{pass[i]=ch;cout<<'*';}
 }
 if(strcmp(pass,"admin")==0)
  { cout<<"\n\n\n\n\t\t\t\t\t Welcome ";  delay(800); }
 else { cout<<"\nWrong Password. Enter Again ";  goto X; }
}

class pass                              // The PASS FILE
{
 int passno;
 char name[25];
 float charges;
 int newcharges;
 public:
 pass()
 {
  charges=500;
 }
 void addp()
 {
  clrscr();
  cout<<"\n Enter The Pass No.:\n";   cin>>passno;
  cout<<"\n Enter The Name:\n";       gets(name);
  cout<<"\n Charges: \n"<<charges;
 }
 void dispp()
 {
  cout<<"\n  Pass no.:\n"<<passno;
  cout<<"\n  Name:\n";       puts(name);
  cout<<"\n  Charges:\n"<<charges;  delay(500);
 }
 void modify(int c)
 {
     if ((charges-c)>0)
      charges-=c;
     else
      {
       cout<<"Pass's Maximum limit reached. \nYou'll have to pay more. \nAmount to be paid is : ";
       newcharges = (c-charges);
       cout<<newcharges<<"\nPlease renew your pass as soon as possible. ";
       charges=0;
      }
 }
 int retp()
  { return passno; }
 float retch()
  { return charges; }

}ps,paas,passo,l;

class cycle : private pass                        // The muscular wheel
{          int tkno,pass;
	   char name[20];
	   int charge;
	   int cha(int c)
		     {
			int cost;
			cost=c*5;
			  return cost;
		     }
	public:
	//MEMBER FUNCTIONS FOR CLASS CYCLE....

	void enter()            //CYCLE
	{
		int h;
		cout<<"\n\t\t\t\tPARKING MANAGENEMT\n\n";
		cout<<"\t\t\t          CYCLE DATABASE\n\n";
		a=tokenno();
		tkno=a;
		cout<<"\nToken_No:\n"<<tkno;
		cout<<"\nEnter Name:\n";
		gets(name);
		cout<<"\n\nCharge:\t\tRs 5 Per Hour\n";
		cout<<"\nHow Many Hours You Want To Park: ";
		cin>>h;
		charge=cha(h);
		cout<<"\nThe Charges are : " << charge;
		cout<<"\n\tENTRY ADDED";
		getch();
	}

	void disp()             //cycle
	{       cout<<"\n\t\t\t\tPARKING MANAGENEMT\n";
		cout<<"\t\t\t\t    CYCLE DATABASE\n\n";
		cout<<"\n\nToken_No.:\t\t"<<tkno;
		cout<<"\n\nName:\t\t";
		puts(name);
		cout<<"\nCharge: Rs."<<charge;
		getch();

	}
	void disply()           //cycle
	{       cout<<"\n\nToken_No.:\t\t"<<tkno;
		cout<<"\n\nName:\t\t";
		puts(name);
		cout<<"\nCharge:\t\tRs 5/-\n";
	}
	void p()                //cycle
	{
		cout<<"\n\t\t\t\tPARKING MANAGENEMT\n\n";
		cout<<"\nEnter Name:\t";
		gets(name);
		f+=1;
		pass=f;
		cout<<"\nAnnual Pass No.:\n"<<pass;
		cout<<"\nCharge:\tRs 500/-\n";
	}
	void pd()               //cycle
	{
		cout<<"\n\t\t\t\tPARKING MANAGENEMT\n";
		cout<<"\nName:\n";
		puts(name);
		cout<<"\nAnnual Pass No:\n"<<pass;
		cout<<"\nCharge:\tRs 450/-\n";
	}
	void mod()          //modify func
	{
		cout<<"\n\t\t\t\tPARKING MANAGENEMT\n";
		cout<<"\nEnter Name:\n";
		gets(name);
	}
	//ACCESSOR FUNCTIONS
	int retch()
	 {return charge;}

	int ret_t()
	 {return tkno;}

	char * ret_n()
	 {return name;}

	int ret_po()
	 {return pass;}
}C;

void add()                    //cycle
{
	char ans;
	int pn,ch;
	clrscr();
	ofstream out("cycle.dat",ios::binary|ios::app);
	C.enter();
	ch=C.retch();
	int pno=ps.retp();
	cout<<"\n Do You Have A Pass (Y/N)??";
	cin>>ans;
	if(ans =='y' || ans=='Y')
	{
	   cout<<"\n Enter Your Pass No.:\n";
	   cin>>pn;
	   if(pn==pno)
	   {
		cout<<"\n PASS FOUND\n";
		cout<<"\n Deducting Rs."<<ch<<"/-";
		out.write ((char*)&C,sizeof(C));
		cout<<"\n Cycle Record Added";
		cout<<"\n Press Any Key To Continue : ";
		getch();
		out.close();
		modi(ch,pno);
	   }
	}
	else
	{
	 out.write ((char*)&C,sizeof(C));
	 out.close();
	}
}


int tokenno()
{
	int cl,pos;
	ifstream in;
	in.open("cycle.dat",ios::binary);
	if(!in)
	{
		pos=in.tellg();
		if(pos==-1)
		{
		      cl=1;
		      in.close();
		      return cl;
		}
	}
	else
	{
		while(in)
		{
		      in.read((char*)&C,sizeof(C));
		      if(in.eof())break;
		}
		 cl=C.ret_t();
		 ++cl;
		 in.close();

	 }

	return cl;
}

void earn()                  // cycle
 {
 ifstream in("cycle.dat",ios::binary);
 if(!in)
 {
   cout<<"\n Error Opening File..!!\n";
   return;
 }
 int s;
 int sum=0;
 while(in)
 {
   in.read((char*)&C,sizeof(C));
   if(in.eof())break;
   s=C.retch();
   sum+=s;
 }
 in.close();
 cout<<"\n Total Earning= "<<sum;
 getch();
}

void display()                    //cycle
{
	clrscr();
	int c=0;
	ifstream in("cycle.dat",ios::binary);
	if(!in)
	{
		cout<<"ERRor opening file..!!!";
		return;
	}
	while(in)
	{
		in.read((char*)&C,sizeof(C));
		if(in.eof()) break;
		C.disp();
		c=1;
	}
	if(c==0)
	cout<<"\n\n\t\tDATA BASE EMPTY\n";
	in.close();
}
//display by name
void dpn()                          //cycle
{       clrscr();
	cout<<"Enter Name To Search For:";
	char y[30];
	gets(y);int u=0;
	ifstream in("cycle.dat",ios::binary);
	if(!in){ cout<<"ERRor opening file..!!!";return;}
	while(in)
	{
		in.read((char*)&C,sizeof(C));
		if(in.eof())break;
		if(strcmp(C.ret_n(),y)==0)
		{
		   C.disp();
		   u=1;
		}
	}
	if(u==0)
	cout<<"NOT FOUND";
	in.close();
}
//display by token no                  cycle
void dpno()
{       clrscr();
	cout<<"Enter Token No.:\n";
	int n2;
	cin>>n2;int c2=0;
	ifstream in("cycle.dat",ios::binary);
	if(!in) {cout<<"ERRor opening file...!!";return;}
	while(in)
	{
		in.read((char*)&C,sizeof(C));
		if(in.eof()) break;
		if(C.ret_t()==n2)
		{
		    C.disp();
		    c2=1;
		}
	}
	if(c2==0)
	cout<<"NOT FOUND";
	in.close();
}
//delete by token no                        cycle
void del()
{       clrscr();
	int a,found=0;
	char c='y';
	while(c=='y'||c=='Y')
	{
	ifstream in("cycle.dat",ios::binary);
	ofstream out("temp.dat",ios::binary);
	cout<<"\nEnter The Token_No :\n";
	cin>>a;
	while(in)
	{
		in.read((char*)&C,sizeof(C));
		if(in.eof()) break;
		if(C.ret_t()==a)
			{
			  cout<<"Deleting..!!\n";
			  C.disp();
			  found=1;
			}
		else
			{
			  out.write((char*)&C,sizeof(C));
			}
	}
	remove("cycle.dat");
	rename("temp.dat","cycle.dat");
	cout<<"\n Want to delete more(y/n):\n";
	cin>>c;
	}
	if(found==0)
	cout<<"Not Found\n";
}
void pass()                      //cycle
{
	clrscr();
	ofstream out("pass.dat",ios::binary|ios::app);
	paas.addp();
	out.write ((char*)&paas,sizeof(paas));
	out.close();
	cout<<"\n Annual Pass Created\n";
}
void passd()                  //cycle
{
	clrscr();
	int c=0;
	ifstream in("pass.dat",ios::binary);
	if(!in) {cout<<"ERRor opening file..!!";return;}
	while(in)
	{
		in.read((char*)&ps,sizeof(ps));
		if(in.eof()) break;
		ps.dispp();
		c=1;
	}
	if(c==0)
	cout<<"\n\n\t\tDATA BASE EMPTY";
	in.close();
}
void modi(int c,int p)        //cycle
{
	clrscr();
	fstream io("pass.dat",ios::binary|ios::in|ios::out);
	int found=0; long pos; int id;
	if(!io)
	{ cout<<"\nERRor OPENING FILE...!!! "; return; }
	while(io)
	 {
		pos=io.tellg();
		io.read((char*) &ps,sizeof(ps));
		if(io.eof()) break;
		if(ps.retp()==p)
		{
			found=1;
			cout<<"\nModifying details in file...Done!!\n";
			ps.modify(c);
			io.seekp(pos,ios::beg);
			io.write((char *)&ps,sizeof(ps));}
		}
	if(found==0)
	cout<<"\nRecord Does Not Exist!!!";
	io.close();
}
/* Functions of previous class ended */


class bike                        // The fairly efficient ride
{          int srno,pass;
	   char name[20];
	   int tkno;
	   int charge;

	   int cha(int c)
		     {
		      int cost;
		      cost=c*5;
			return cost;
		     }

	public:
	//MEMBER FUNCTIONS FOR CLASS Bike....

	void enter()            //Bike
	{
		int h;
		cout<<"\n\t\t\t\tPARKING MANAGENEMT\n";
		cout<<"\t\t\t\t      BIKE DATABASE\n\n";
		tkno=tokennob();
		cout<<"\nToken_No:\n"<<tkno;
		cout<<"\nEnter Name:\n";
		gets(name);
		cout<<"\n\nCharge:\t\tRs 5 Per Hour\n";
		cout<<"\n How Many Hours You Want To Park:\n";
		cin>>h;
		charge=cha(h);
		cout<<"\n ENTRY MADE!!!";
     getch();
	}

	void disp()             //bike
	{
	   cout<<"\n\t\t\t\tPARKING MANAGENEMT\n";
		cout<<"\t\t\t\t\tCYCLE DATABASE\n\n";
		cout<<"\n\nToken_No:\t\t\n"<<tkno;
		cout<<"\n\nName:\t\t\n";
		puts(name);
		cout<<"\nCharge:Rs.\n"<<charge;
		getch();
	}
	void disply()           //bike
	{       cout<<"\n\nToken_No:\t\t"<<tkno;
		cout<<"\n\nName:\t\t";
		puts(name);
		cout<<"\nCharge:\t\tRs 5/-\n";
	}
	void p()                //bike
	{
		cout<<"\n\t\t\t\tPARKING MANAGENEMT\n\n";
		cout<<"\nEnter Name:\t";
		gets(name);
		f+=1;
		pass=f;
		cout<<"\nAnnual Pass No.:\n"<<pass;
		cout<<"\nCharge:\tRs 500/-\n";
	}
	void pd()               //bike
	{
		cout<<"\n\t\t\t\tPARKING MANAGENEMT\n\n";
		cout<<"\nName:\n";
		puts(name);
		cout<<"\nAnnual Pass No:\n"<<pass;
		cout<<"\nCharge:\tRs 500/-";
	}
	void mod()          //modify func
	{
		cout<<"\n\t\t\t\tPARKING MANAGENEMT..!\n";
		cout<<"\nEnter Name:\n";
		gets(name);
	}
	//ACCESSOR FUNCTIONS
	int retch()
	{return charge;
	}
	int ret_t()
	{ return tkno; }
	char * ret_n()
	{ return name; }
	int ret_po()
	{ return pass; }
}B;

int tokennob()                       //bike
{
	int cl,pos;
	ifstream in;
	in.open("bike.dat",ios::binary);
	if(!in)
	{
		pos=in.tellg();
		if(pos==-1)
		{
		      cl=1;
		      in.close();
		      return cl;
		}
	}
	else
	{
		while(in)
		{
		      in.read((char*)&B,sizeof(B));
		      if(in.eof())break;
		}
		 cl=B.ret_t();
		 ++cl;
		 in.close();

	 }

	return cl;
}

void earnb()                  // bike
{
 ifstream in("bike.dat",ios::binary);
 if(!in)
 {
	 cout<<"\n Error Opening File..!!!";
	 return;
 }
 int s;
 int sum=0;
 while(in)
 {
	in.read((char*)&B,sizeof(B));
	if(in.eof())break;
	s=B.retch();
	sum+=s;
 }
 in.close();
 cout<<"\n Total Earning="<<sum;
 getch();
}

void modib(int,int);
void addb()                            //bike
{
	char ans;
	int pn,ch;
	clrscr();
	ofstream out("bike.dat",ios::binary|ios::app);
	B.enter();
	ch=B.retch();
	int pno=ps.retp();
	cout<<"\n Do You Have A Pass(y/n)??";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
	   cout<<"\n Enter Your Pass No.:\n";
	   cin>>pn;
	   if(pn==ps.retp())
	   {
		cout<<"\n PASS FOUND\n";
		cout<<"\n Deducting Rs."<<ch<<"/-";
		out.write ((char*)&B,sizeof(B));
		cout<<"\n Bike Record Added";
		getch();
		out.close();
		modib(ch,pno);
	    }

	}
	else
	{   out.write ((char*)&B,sizeof(B));
	 out.close();
	 getch();}
}
void displayb()                  //  bike
{
	clrscr();
	int c=0;
	ifstream in("bike.dat",ios::binary);
	if(!in)
	{
	cout<<"ERRor opening file..!!!";
	return;
	}
	while(in)
	{
		in.read((char*)&B,sizeof(B));
		if(in.eof()) break;
		B.disp();
		c=1;
	}
	if(c==0)
	cout<<"\n\n\t\tDATA BASE EMPTY";
	in.close();
}
//display by name               bike
void dpnb()
{       clrscr();
	cout<<"Enter Name To Search For:\n";
	char y[30];
	gets(y);int u=0;
	ifstream in("bike.dat",ios::binary);
	if(!in){ cout<<"ERRor opening file..!!";return;}
	while(in)
	{
		in.read((char*)&B,sizeof(B));
		if(in.eof())break;
		if(strcmp(B.ret_n(),y)==0)
		{
		     B.disp();
		     u=1;
		}
	}
	if(u==0)
	cout<<"NOT FOUND";
	in.close();
}
//display by token no              bike
void dpnob()
{       clrscr();
	cout<<"Enter Token No.:\n";
	int n2;
	cin>>n2;int c2=0;
	ifstream in("bike.dat",ios::binary);
	if(!in) {cout<<"ERRor opening file...!!";return;}
	while(in)
	{
		in.read((char*)&B,sizeof(B));
		if(in.eof()) break;
		if(B.ret_t()==n2)
		{
		    B.disp();
		    c2=1;
		}
	}
	if(c2==0)
	cout<<"NOT FOUND";
	in.close();
}
//delete by token no
void delb()                   // bike
{       clrscr();
	int a,found=0;
	char c='y';
	while(c=='y'||c=='Y')
	{
	ifstream in("bike.dat",ios::binary);
	ofstream out("temp.dat",ios::binary);
	cout<<"\nEnter The Token_No :\n";
	cin>>a;
	while(in)
	{
		in.read((char*)&B,sizeof(B));
		if(in.eof()) break;
		if(B.ret_t()==a)
			{	cout<<"Deleting...!!!\n";
				B.disp();
				found=1;
			}
		else
			{
			      out.write((char*)&B,sizeof(B));
			}
	}
	remove("bike.dat");
	rename("temp.dat","bike.dat");
	cout<<"\n Want to delete more(y/n):\n";
	cin>>c;
	}
	if(found==0)
	cout<<"Not Found";
}
void passb()                      //bike
{
	clrscr();
	ofstream out("passb.dat",ios::binary|ios::app);
	passo.addp();
	out.write ((char*)&passo,sizeof(passo));
	out.close();
	cout<<"\n Annual Pass Created\n";
getch();
}
void passdb()                  //bike
{
	clrscr();
	int c=0;
	ifstream in("passb.dat",ios::binary);
	if(!in) {cout<<"ERRor opening file...";return;}
	while(in)
	{
		in.read((char*)&ps,sizeof(ps));
		if(in.eof()) break;
		ps.dispp();
		c=1;
	}
	if(c==0)
	cout<<"\n\n\t\tDATA BASE EMPTY";
	in.close();
}
void modib(int c,int p)        //bike
{
	clrscr();
	fstream io("passb.dat",ios::binary|ios::in|ios::out);
	int found=0; long pos; int id;
	if(!io)
	{	cout<<"\nERROR OPENING FILE..!! "; return; }
	      while(io)
	       {
		pos=io.tellg();
		io.read((char*) &ps,sizeof(ps));
		if(io.eof())
		  break;
		if(ps.retp()==p)
		{
			found=1;
			cout<<"\n Modifying DATA in file..DONE!! \n";
			ps.modify(c);
			io.seekp(pos,ios::beg);
			io.write((char *)&ps,sizeof(ps));
		}

	}
	if(found==0)
	cout<<"\nRecord Does Not Exist..!!";
	io.close();
}

/* Functions of previous class ended

					 */
class car                        // The monster drinking our fuel
{          int pass;
	   char name[20];
	   int tkno;
	   int charge;

	   int cha(int c)
		     {
		      int cost;
		      cost=c*5;
			return cost;
		     }

	public:
	//MEMBER FUNCTIONS FOR CLASS Car....

	void enter()            //car
	{
		int h;
		cout<<"\n\t\t\t\tPARKING MANAGENEMT\n";
		cout<<"\t\t\t     DATABASE\n\n";
		tkno=tokennoc();
		cout<<"\nToken_No:\n"<<tkno;
		cout<<"\nEnter Name:\n";
		gets(name);
		cout<<"\n\nCharge:\t\tRs 5 Per Hour";
		cout<<"\n How Many Hours You Want To Park:\n";
		cin>>h;

		charge=cha(h);
		cout<<"\n ENTRY MADE!!!";
		  }

	void disp()             //car
	{       cout<<"\n\t\t\t\tPARKING MANAGENEMT\n";
		cout<<"\t\t\t       CAR DATABASE\n\n";
		cout<<"\n\nToken_No:\t\t"<<tkno;
		cout<<"\n\nName:\t\t";
		puts(name);
		cout<<"\nCharge:Rs."<<charge;
		getch();

	}
	void disply()           //car
	{       cout<<"\n\nToken_No:\t\t"<<tkno;
		cout<<"\n\nName:\t\t";
		puts(name);
		cout<<"\nCharge:\t\tRs 5/-";
	}
	void p()                //car
	{
		cout<<"\n\t\t\t\tPARKING MANAGENEMT\n";
		cout<<"\nEnter Name:\t";
		gets(name);
		f+=1;
		pass=f;
		cout<<"\nAnnual Pass No.:\n"<<pass;
		cout<<"\nCharge:\tRs 500/-";
	}
	void pd()               //car
	{
		cout<<"\n\t\t\t\tPARKING MANAGENEMT\n";
		cout<<"\nName:";
		puts(name);
		cout<<"\nAnnual Pass No:"<<pass;
		cout<<"\nCharge:\tRs 500/-";
	}
	void mod()          //modify func
	{
		cout<<"\n\t\t\t\tPARKING MANAGENEMT\n";
		cout<<"\nEnter Name:\n";
		gets(name);
	}
	//ACCESSOR FUNCTIONS
	int retch()
	{ return charge; }
	int ret_t()
	{ return tkno; }
	char * ret_n()
	{ return name; }
	int ret_po()
	{ return pass; }
}ca;

int tokennoc()
{
	int cl,pos;
	ifstream in;
	in.open("car.dat",ios::binary);
	if(!in)
	{
		pos=in.tellg();
		if(pos==-1)
		{
		      cl=1;
		      in.close();
		      return cl;
		}
	}
	else
	{
		while(in)
		{
		      in.read((char*)&ca,sizeof(ca));
		      if(in.eof())break;
		}
		 cl=ca.ret_t();
		 ++cl;
		 in.close();

	 }

	return cl;
}

void earnc()                  // car
 {
 ifstream in("car.dat",ios::binary);
 if(!in)
 {
	  cout<<"\n Error Opening File..!!";
	  return;
 }
 int s;
 int sum=0;
 while(in)
 {
	 in.read((char*)&ca,sizeof(ca));
	 if(in.eof())break;
	 s=ca.retch();
	 sum+=s;
 }
 in.close();
 cout<<"\n Total Earning="<<sum;
 getch();
}
void modic(int,int);
void addc()
{
	char ans;
	int pn,ch;
	clrscr();
	ofstream out("car.dat",ios::binary|ios::app);
	ca.enter();
	ch=ca.retch();
	int pno=ps.retp();
	cout<<"\n Do You Have A Pass(y/n)??";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
	   cout<<"\n Enter Your Pass No.:";
	   cin>>pn;
	   if(pn==ps.retp())
	   {
		cout<<"\n PASS FOUND";
		cout<<"\n Deducting Rs."<<ch<<"/-";
		out.write ((char*)&ca,sizeof(ca));
		cout<<"\n CAR Record Added";
		getch();
		out.close();
		modic(ch,pno);
		 getch();
	 }
	}
	else
	{   out.write ((char*)&ca,sizeof(ca));
	    out.close();
	}
}
void displayc()
{
	clrscr();
	int c=0;
	ifstream in("car.dat",ios::binary);
	if(!in)
	{
	cout<<"ERRor opening file";
	return;
	}
	while(in)
	{
		in.read((char*)&ca,sizeof(ca));
		if(in.eof()) break;
		ca.disp();
		c=1;
	}
	if(c==0)
	cout<<"\n\n\t\tDATA BASE EMPTY";
	in.close();
getch();}
//display by name                car
void dpnc()
{       clrscr();
	cout<<"Enter Name To Search For:\n";
	char y[30];
	gets(y);int u=0;
	ifstream in("car.dat",ios::binary);
	if(!in){ cout<<"ERRor opening file..!!";return;}
	while(in)
	{
		in.read((char*)&ca,sizeof(ca));
		if(in.eof())break;
		if(strcmp(ca.ret_n(),y)==0)
		{
		ca.disp();
		u=1;
		}
	}
	if(u==0)
	cout<<"NOT FOUND";
	in.close();
}
//display by token no                car
void dpnoc()
{       clrscr();
	cout<<"Enter Token No.:\n";
	int n2;
	cin>>n2;int c2=0;
	ifstream in("car.dat",ios::binary);
	if(!in) {cout<<"ERRor opening file...!!";return;}
	while(in)
	{
		in.read((char*)&ca,sizeof(ca));
		if(in.eof()) break;
		if(ca.ret_t()==n2)
		{
		ca.disp();
		c2=1;
		}
	}
	if(c2==0)
	cout<<"NOT FOUND";
	in.close();
}
//delete by token no               car
void delc()
{       clrscr();
	int a,found=0;
	char c='y';
	while(c=='y'||c=='Y')
	{
	ifstream in("car.dat",ios::binary);
	ofstream out("temp.dat",ios::binary);
	cout<<"\nEnter The Token_No :\n";
	cin>>a;
	while(in)
	{
		in.read((char*)&ca,sizeof(ca));
		if(in.eof()) break;
		if(ca.ret_t()==a)
			{	cout<<"Deleting...!!!\n";
			ca.disp();
			found=1;
			}
		else
			{
			out.write((char*)&ca,sizeof(ca));
			}
	}
	remove("car.dat");
	rename("temp.dat","car.dat");
	cout<<"\n Want to delete more:\n";
	cin>>c;
	}
	if(found==0)
	cout<<"Not Found";
}

void passc()                      //car
{
	clrscr();
	ofstream out("passc.dat",ios::binary|ios::app);
	l.addp();
	out.write ((char*)&l,sizeof(l));
	out.close();
	cout<<"\n Annual Pass Created\n";
}
void passdc()                  //car
{
	clrscr();
	int c=0;
	ifstream in("passc.dat",ios::binary);
	if(!in) {cout<<"ERRor opening file..!!";return;}
	while(in)
	{
		in.read((char*)&ps,sizeof(ps));
		if(in.eof()) break;
		ps.dispp();
		c=1;
	}
	if(c==0)
	cout<<"\n\n\t\tDATA BASE EMPTY";
	in.close();
}
void modic(int c,int p)        //car
{
	clrscr();
	fstream io("pass.dat",ios::binary|ios::in|ios::out);
	int found=0; long pos; int id;
	if(!io)
	{	cout<<"\nERROR OPENING FILE..!! "; return; }
	while(io)
	{
		pos=io.tellg();
		io.read((char*) &ps,sizeof(ps));
		if(io.eof()) break;
		if(ps.retp()==p)
		{

			found=1;
			cout<<"\n Modifying data in file.....Done!!\n";
			ps.modify(c);

		io.seekp(pos,ios::beg);
		io.write((char *)&ps,sizeof(ps));}

  getch();	}
	if(found==0)
	cout<<"\nRecord Does Not Exist..!";
	io.close();
}

//to display data from all files

void dpall()                     // Main Menu Case ( 4 ), Displays everything
{       clrscr();
	cout<<"\n\t\t\t\tPARKING MANAGEMENT\n";
	for(int i=0;i<tokenno()+1;i++)
		{ if(C.ret_t()==i)
		     {
			int c=0;
			ifstream in("cycle.dat",ios::binary);
			if(!in) { cout<<"ERRor..........."; return;}
			cout<<"\n\n Cycle Database:\n";
			while(in)
			  {
			    in.read((char*)&C,sizeof(C));
			    if(in.eof()) break;
			    C.disply();
			    c=1;
			  }
			if(c==0)
			cout<<"\n\n\t\tCYCLE DATA BASE EMPTY.....";
			in.close();
		     }
		}
	for(int j=0;j<tokennob()+1;j++)
		 { if(B.ret_t()==j)
		     {
			int c=0;
			ifstream in("bike.dat",ios::binary);
			if(!in) { cout<<"ERRor..........."; return;}
			cout<<"\n\n Bike Database:\n";
			while(in)
			  {
			    in.read((char*)&B,sizeof(B));
			    if(in.eof()) break;
			    B.disply();
			    c=1;
			  }
			if(c==0)
			cout<<"\n\n\t\tBIKE DATA BASE EMPTY.....";
			in.close();
		     }
		 }
	 for(int k=0;k<tokennoc()+1;k++)
		 { if(ca.ret_t()==k)
		     {
			int c=0;
			ifstream in("car.dat",ios::binary);
			if(!in) { cout<<"ERRor..........."; return;}
			cout<<"\n\n Car Database:\n";
			while(in)
			  {
			   in.read((char*)&ca,sizeof(ca));
			   if(in.eof()) break;
			   ca.disply();
			   c=1;
			  }
			if(c==0)
			cout<<"\n\n\t\tCAR DATA BASE EMPTY.....";
			in.close();
		     }
		 }
       cout<<"\n\n\tPress any key to countinue:\n";
       getch();
}

//to add,display and modify records on file pass & passb
void main()     //MAIN FUNCTION
{
   clrscr();
   textcolor(RED);
   password();
   /* select a driver and mode that supports */
   /* multiple background colors. */
   int gdriver = EGA, gmode = EGAHI, errorcode;
   int bkcol; int maxcolor;

   // initialize graphics and local variables
   initgraph(&gdriver, &gmode, "c:/tc/bgi");

   /* read result of initialization  */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred  */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   /* maximum color index supported */
   maxcolor = getmaxcolor();

   /* loop through the available colors */
   for (bkcol=0; bkcol<(maxcolor-13); bkcol++)
   {
      cout<<endl;
      cout<<endl;
      cout<<endl;
      cout<< "\t\t  PPPP   AAAAA  RRRRR   K  K  IIIIII  N   N  GGGGGG       "<<endl;
      cout<< "\t\t  P  PP  A   A  R    R  K K     II    NN  N  G            "<<endl;
      cout<< "\t\t  PPPPP  AAAAA  RRRRR   KK      II    N N N  G  GGGG      "<<endl;
      cout<< "\t\t  P      A   A  R   R   K K     II    N  NN  G  GG G      "<<endl;
      cout<< "\t\t  P      A   A  R    R  K  K  IIIIII  N   N  GGGGG G      "<<endl;

      cout<<endl;
      cout<<endl;
      cout<<endl;
      cout<<"      M   M  AAAAA  N   N  AAAAA  GGGGGG   EEEEE  M   M   EEEE  N   N  TTTTT"<<endl;
      cout<<"      MM MM  A   A  NN  N  A   A  G        EE     MM MM   E     NN  N    T  "<<endl;
      cout<<"      M M M  AAAAA  N N N  AAAAA  G  GGGG  EEEE   M M M   EEE   N N N    T  "<<endl;
      cout<<"      M   M  A   A  N  NN  A   A  G  GG G  EE     M   M   E     N  NN    T  "<<endl;
      cout<<"      M   M  A   A  N   N  A   A  GGGGG G  EEEEE  M   M   EEEE  N   N    T  "<<endl;

      cout<<endl;
      cout<<endl;
      cout<<endl;
      cout<< "\t\t   SSSSS  Y     Y  SSSSS  TTTTTT   EEEE  M   M "<<endl;
      cout<< "\t\t   SS      Y   Y   SS       TT     E     MM MM "<<endl;
      cout<< "\t\t   SSSSS    YYY    SSSSS    TT     EEE   M M M "<<endl;
      cout<< "\t\t      SS     Y        SS    TT     E     M   M "<<endl;
      cout<< "\t\t   SSSSS     Y     SSSSS    TT     EEEE  M   M "<<endl;

      /* select a new background color  */
      setbkcolor(bkcol);
      delay(2000);
   }
   /*clear the screen */
   cleardevice();
   /* clean up  */
   closegraph();

   //Graphics ENDed

	   // Our Real Code
 clrscr();
 start:
 textcolor(GREEN);
 DATE_TIME();
 int g;
 cout<<"\t\t\t\tPARKING MANAGEMENT\n";cout<<endl;
 cout<<"\n\t\t\t 1. CYCLES";
 cout<<"\n\t\t\t 2. BIKES";
 cout<<"\n\t\t\t 3. CARS";
 cout<<"\n\t\t\t 4. DISPLAY ALL DATABASE";
 cout<<"\n\t\t\t 5. TOTAL SALARY AT THE END OF DAY";
 cout<<"\n\t\t\t 6. QUIT";
 cout<<"\n\n\n\t\t\tEnter Your Choice[1-6]:\t";
 cin >> g;
 switch(g)
 {
  case 1:{
	   clrscr();
	   textcolor(MAGENTA);
	   int n; char f,d;
	   do
	   {
	    clrscr();
	    cout<<"\n\t\t\t\tPARKING MANAGEMENT\n\n";
	    cout<<"   \t\t\t\t  CYCLE DATABASE\n\n";
	    cout<<"\t\t\t1. Make An Entry\n";
	    cout<<"\t\t\t2. Make An Annual Pass\n";
	    cout<<"\t\t\t3. Display By Name\n";
	    cout<<"\t\t\t4. Display By Token No.\n";
	    cout<<"\t\t\t5. Display All Cycles \n";
	    cout<<"\t\t\t6. Display Annual Passes\n";
	    cout<<"\t\t\t7. Delete\n";
	    cout<<"\t\t\t8. Return To Main Menu\n";
	    cout<<"\t\t\t9. Quit\n\n";
	    cout<<"\t\t\tEnter Your Choice:[1-9]:";
	    cin >> n;
	    switch(n)
	    {
	     case 1: do
		     {
		      add();
		      cout<<"\n\t\tEnter More[y/n]\t";
		      cin>>d;
		     }while(d=='y');
		     break;
	     case 2:pass();
		     break;
	     case 3:dpn();
		     break;
	     case 4:dpno();
		     break;
	     case 5:display();
		     break;
	     case 6:passd();
		     break;
	     case 7:del();
		     break;
	     case 8:goto start;
	     case 9:exit(0);
						}
	   cout<<"\n\t\t\t\t CYCLE MENU[Y/N]:\n";
	   cin >> f;
	   }while(f=='Y' || f=='y');
	  }
	   break;
  case 2:{
	  clrscr();
	  textcolor(MAGENTA);
	  int n; char f,d;
	  do
	  {
	   clrscr();
	   cout<<"\n\t\t\t\tPARKING MANAGEMENT\n\n";
	   cout<<"   \t\t\t\t  BIKE DATABASE\n";
	   cout<<"\t\t\t1. Make An Entry\n";
	   cout<<"\t\t\t2. Make An Annual Pass\n";
	   cout<<"\t\t\t3. Display By Name\n";
	   cout<<"\t\t\t4. Display By Token No.\n";
	   cout<<"\t\t\t5. Display All Bikes \n";
	   cout<<"\t\t\t6. Display Annual Passes\n";
	   cout<<"\t\t\t7. Delete\n";
	   cout<<"\t\t\t8. Return To Main Menu\n";
	   cout<<"\t\t\t9. Quit\n\n";
	   cout<<"\t\t\tEnter Your Choice:[1-9]:";
	   cin>>n;
	   switch(n)
	   {
	    case 1:do
		   {
		    addb();
		    cout<<"\n\t\tEnter More[y/n]\t";
		    cin>>d;
		   }while(d=='y');
		   break;
	    case 2:passb();
		   break;
	    case 3:dpnb();
		   break;
	    case 4:dpnob();
		   break;
	    case 5:displayb();
		   break;
	    case 6:passdb();
		   break;
	    case 7:delb();
		   break;
	    case 8:goto start;
	    case 9:exit(0);
						}
	   cout<<"\n\t\t\t\t BIKE MENU[Y/N]:\n";
	   cin>>f;
	   }while(f=='Y' || f=='y');
  }
   break;
   case 3:{
	   clrscr();
	   textcolor(MAGENTA);
	   int n; char f,d;
	   do
	   {
	    clrscr();
	    cout<<"\n\t\t\t\tPARKING MANAGEMENT.....\n\n";
	    cout<<"   \t\t\t\t  CAR DATABASE.....\n";
	    cout<<"\t\t\t1. Make An Entry\n";
	    cout<<"\t\t\t2. Make An Annual Pass\n";
	    cout<<"\t\t\t3. Display By Name\n";
	    cout<<"\t\t\t4. Display By Token No.\n";
	    cout<<"\t\t\t5. Display All Cars \n";
	    cout<<"\t\t\t6. Display Annual Passes\n";
	    cout<<"\t\t\t7. Delete\n";
	    cout<<"\t\t\t8. Return To Main Menu\n";
	    cout<<"\t\t\t9. Quit\n\n";
	    cout<<"\t\t\tEnter Your Choice:[1-9]:";
	    cin>>n;
	    switch(n)
	    {
	     case 1:do
		    {
		     addc();
		     cout<<"\n\t\tEnter More[y/n]\t";
		     cin>>d;
		    }while(d=='y');
		    break;
	     case 2:passc();
		    break;
	     case 3:dpnc();
		    break;
	     case 4:dpnoc();
		    break;
	     case 5:displayc();
		    break;
	     case 6:passdc();
		    break;
	     case 7:delc();
		    break;
	     case 8:goto start;
	     case 9:exit(0);
						}
	    cout<<"\n\t\t\t\t CAR MENU[Y/N]:\n";
	    cin>>f;
	    }while(f=='Y' || f=='y');
  }
	 break;
  case 4:textcolor(MAGENTA);
	 dpall();  char dis_ans;
	 cout<<"Return to Main Menu [Y/N]";
	 cin >> dis_ans;
	 if (dis_ans == 'y' || 'Y')
	  goto start;
	 else
	  exit(0);
  case 5:textcolor(MAGENTA);
	 earn();
	 break;
  case 6:exit(0);
  default:{ cout<<"You have entered a wrong option. \n \t Try Again"; delay(500); goto start; }
 }
 getch();
}             //end of main & end of program