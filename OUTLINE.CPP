#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void Editbus();
void EditDriver();
void Reenter();
void DrvrEntr();
void Sort();
void mergebus();
void AddAttend();
void assign();
void DrvrAttend();
void CoreCopy();
void SendBus();
class BUS
{
 int Busno,Stops,streng,areacode,att,status,Drvrnum;
 char AreaNm[20],StpNm[20][5];
 public:
 void Enter();
 void editEnter();
 void Display()
{
 cout<<"area code:"<<areacode<<endl;
 cout<<"The Bus Number is: "<<Busno<<endl;
 cout<<"The Status of the Bus is: "<<status<<endl;
 cout<<"The Number of Stops are: "<<Stops<<endl;
 cout<<"The Area you entered is: ";puts(AreaNm);
 cout<<endl;

}
void attenddisplay()
{
 cout<<"Attend of busno "<<Busno<<" is "<<att;
}
void subsdisplay()
{
 cout<<"area code:"<<areacode<<endl;
 cout<<"The Bus Number is: "<<Busno<<endl;
}

 char *Arearet()
{
 return AreaNm;
}
 int BusnoRet()
{
 return Busno;
}
 int attret()
{
 return att;
}
 int strengret()
{
 return streng;
}
 int areacoderet()
{
 return areacode;
}
void EnterAttend()
{
 cin>>att;
}
int Drvrnumret()
{
 return Drvrnum;
}
void EditDrvr()
{
 cout<<"Enter the Drivernum you want to assign to the bus:";
 cin>>Drvrnum;
}
void Busbroken()
{
 status=0;
}
void Busoperational()
{
 status=1;
}
void strenginc()
{
 att++;
 streng++;
}
int Busstatret()
{
 return status;
}
};
/* ***********************************
 DRIVER CLASS
 *************************************** */
class Driver
{
 int Drvrnum,attend,Busno;
 float salary;
 char shift[20],Drvrname[20],CtrctName[20];
 public:
 void editEnter();
 void Enter(int N,int M);
 void EnterAttend()
 {
  cout<<"Attendence of Driver num "<<Drvrnum<<"is:";
  cin>>attend;
 }
 void EditDrvrname()
 {
  gets(Drvrname);
 }
 int Drvrnumret()
{
 return Drvrnum;
}
 int Drvrattendret()
{
 return attend;
}
void Drvrabsent()
{
 attend=0;
}
void Drvrworking()
{
 attend=1;
}
void display()
{
  cout<<"Name: ";puts(Drvrname);
  cout<<"Driver number: "<<Drvrnum<<endl;
  cout<<"Conductor: ";puts(CtrctName);
  cout<<"Bus: "<<Busno<<endl;
  cout<<"Salary: "<<salary<<endl;
  cout<<"Shift: ";puts(shift);
  cout<<endl;
}
};
/*******************************
Main Function
******************************* */

void main()
{
 clrscr();
 // CoreCopy();
 fstream fil,dfil,dfil3,fil3,dfil1;
 dfil1.open("COREDINFO.dat",ios::binary|ios::out|ios::in);
 fil.open("DATA.dat",ios::binary|ios::in);
 dfil.open("DINFO.dat",ios::binary|ios::in);
 int ch,ch2,ch3;
 BUS B,B1;
 Driver D,D1;
 do
 {
  cout<<"1.Admin\n";
  cout<<"2.Regular\n";
  cout<<"3.Quit\n";
  cout<<"Your Choice is:";
  cin>>ch2;
  if(ch2==1)
     {clrscr();
      do
	{
	  cout<<"1.Re Enter Records\n";
	  cout<<"2.Edit Bus Record\n";
	  cout<<"3.Edit Driver Record\n";
	  cout<<"4.Back\n";
	  cout<<"You Entered:";
	  cin>>ch3;
	  if(ch3==1)
	    Reenter();
	  else if(ch3==2)
	    Editbus();
	  else if(ch3==3)
	    EditDriver();
	 }while(ch3!=4);
	clrscr();
     }
  else if(ch2==2)
  { clrscr();
    do
     {clrscr();
      cout<<"enter 1)to assign a bus"<<endl;
      cout<<"2)enter driver attendence"<<endl ;
      cout<<"3)send bus as one is wrecked"<<endl;
      cout<<"4)display"<<endl;
      cout<<"5)Merge Buses"<<endl;
      cout<<"6)Back"<<endl;
      cout<<"Your choice is:";
      cin>>ch;
      if(ch==1)
       assign();
      else if(ch==2)
	DrvrAttend();
      else if(ch==3)
       SendBus();
      else if(ch==4)
       {clrscr();
	int ch1;
	cout<<"Display 1.Bus Details 2.Driver Details:";
	cin>>ch1;
	if(ch1==1)
	while(fil.read((char*)&B,sizeof(B)))
	 B.Display();
	else if(ch1==2)
	 while(dfil.read((char*)&D,sizeof(D)))
	  D.display();
	 else
	  cout<<"Wrong choice"<<endl;
	getch();
       }
       else if(ch==5)
	AddAttend();
       clrscr();
     }while(ch!=6);
  }
  }while(ch2!=3);
 fil.close();
 dfil.close();
 getch();
}
/* ***********************************************
ASSIGN FN
************************************************ */
void assign()
{
 fstream fil;
 char dest[30];
 int found=0;
 BUS A;
 fil.open("DATA.dat",ios::binary|ios::in|ios::out);
 cout<<"Enter your Destination: ";
 gets(dest);
 while(fil.read((char*)&A,sizeof(A)))
 {
  if(strcmpi(A.Arearet(),dest)==0)
   {
    found++;
    A.Display();
    A.strenginc();
    fil.write((char*)&A,sizeof(A));
   }
 }
   if(found==0)
   cout<<"Sorry we do not run buses to that location."<<endl;
   fil.close();
   getch();
}
/* **********************************
Driver Attend
************************************* */
void DrvrAttend()
{
 fstream fil1,fil2;
 char ch;
 Driver D,D1;
 int ctr;
 fil1.open("DINFO.dat",ios::binary|ios::in|ios::out);
 fil2.open("DINFO.dat",ios::binary|ios::in|ios::out);
 do
 {fil1.seekg(0);
  ctr=0;
  int dtemp;
  cout<<"give the number of the driver who is absent:";
  cin>>dtemp;
  while(fil1.read((char*)&D,sizeof(D)))
  {
   if(D.Drvrnumret()==dtemp)
    {D.Drvrabsent();

     fil1.write((char*)&D,sizeof(D));
    }
  }
   fil2.seekg(0);
   while(fil2.read((char*)&D1,sizeof(D1))&&(!ctr))
   {
    if(D1.Drvrattendret()==2)
     {
      cout<<"The driver number who will take the place is:"<<D1.Drvrnumret()<<endl;
      D1.Drvrworking();
      int N=fil2.tellg()-sizeof(D1);
      fil2.seekp(N);
      fil2.write((char*)&D1,sizeof(D1));
      ctr++;
     }
  }
  cout<<"press y to enter more absentees:";
  cin>>ch;
  }while(ch=='y');
 getch();
 fil1.close();
 fil2.close();
}
/**********************************
Send Bus
************************************/
void SendBus()
{
 clrscr();
 fstream fil;
 fil.open("DATA.dat",ios::binary|ios::in|ios::out);
 int Busno;
 BUS B,B1;
 int temp=0;
 cout<<"Enter Bus which has become unoperational:";
 cin>>Busno;
 while(fil.read((char*)&B,sizeof(B)))
 {
  if(Busno==B.BusnoRet())
   {B.Busbroken();
    fil.write((char*)&B,sizeof(B));
   }
 fil.seekg(0);
 while(fil.read((char*)&B1,sizeof(B1)))
  if(B1.Busstatret()==2&&(!temp))
  {
   cout<<"Bus no. "<<B1.BusnoRet()<<"will take take the place of the bus "<<Busno<<endl;
   B.Busoperational();
   fil.write((char*)&B1,sizeof(B1));
    temp++;
  }
 }
  fil.close();
  getch();
}
/*    ************************************
MERGING BUSES
*************************************	*/
void AddAttend()
{
 fstream fil;
 fil.open("Data.dat",ios::binary|ios::in|ios::out);
 BUS B,C;

 while(fil.read((char*)&B,sizeof(B)))
 {
  cout<<"Enter Attendence of Bus no "<<B.BusnoRet()<<":";
  B.EnterAttend();
  int N=fil.tellg()-sizeof(B);
  fil.seekp(N);
  fil.write((char*)&B,sizeof(B));
 }
 fil.seekg(0);
 fil.close();
 mergebus();
}
void Sort()
{
 fstream subs;
 subs.open("SUBS.dat",ios::binary|ios::in|ios::out);
 BUS B,B1;
 subs.seekg(0,ios::end);
 int NOR=subs.tellg()/sizeof(BUS);
  for(int i=0;i<NOR-1;i++)
  {
   for(int j=0;j<NOR-i-1;j++)
   {
    subs.seekg(j*sizeof(BUS));
    subs.write((char*)&B,sizeof(BUS));
    subs.write((char*)&B1,sizeof(BUS));
    if(B.areacoderet()>B1.areacoderet())
    {
     subs.seekp(j*sizeof(BUS));
     subs.write((char*)&B1,sizeof(BUS));
     subs.write((char*)&B,sizeof(BUS));
    }
   }
  }
 subs.close();
 subs.open("SUBS.dat",ios::binary|ios::in|ios::out);
 subs.seekg(0);
 while(subs.read((char*)&B,sizeof(B)))
 {
  B.subsdisplay();
 }
 getch();
 subs.close();
}
void mergebus()
{
 fstream fil,subs;
 fil.open("DATA.dat",ios::binary|ios::in);
 subs.open("Subs.dat",ios::binary|ios::out);
 BUS B,B1,B2;
 while(fil.read((char*)&B,sizeof(B)))
 {
  if(B.attret()<((B.strengret())/2)&&B.areacoderet()!=0)
   {
	subs.write((char*)&B,sizeof(B));
   }
 }
 subs.close();
 fil.seekg(0);
// Sort();  //SORT ACCORDING TO AREACODE
 fil.close();
 fil.open("DATA.dat",ios::binary|ios::in);
 int n,m,b1,b2;
 subs.open("Subs.dat",ios::binary|ios::in);
 subs.seekg(0);
 fil.seekg(0);
/* while(subs.read((char*)&B,sizeof(B)))
 {
  B.subsdisplay();
 } */
 while(subs.read((char*)&B,sizeof(B)))
 { n=B.areacoderet();
   b1=B.BusnoRet();
   subs.read((char*)&B,sizeof(B));
   m=B.areacoderet();
   b2=B.BusnoRet();
   if(n==m)
    cout<<"Bus numbers "<<b1<<" and "<<b2<<" are merged"<<endl;
 }
 getch();
}
/* ************************************
  CORECOPY FN
  ************************************ */
void CoreCopy()
{
 fstream fil,fil1;

 fil.open("COREDATA.dat",ios::binary|ios::in);
 fil1.open("DATA.dat",ios::binary|ios::out);
 BUS B;
 Driver D;
 while(fil.read((char*)&B,sizeof(B)))
 {
  fil1.write((char*)&B,sizeof(B));
 }
 fstream dfil,dfil1;
 dfil.open("COREDINFO.dat",ios::binary|ios::in);
 dfil1.open("DINFO.dat",ios::binary|ios::out);

 while(dfil.read((char*)&D,sizeof(D)))
 {
  dfil1.write((char*)&D,sizeof(D));
 }
 fil.close();
 dfil.close();
 fil1.close();
 dfil1.close();
}
/* ************************************************
ENTER FUNCTIONS
*************************************************** */
void BUS::Enter()
 {
  cout<<"Enter Busno:";cin>>Busno;
  cout<<"Enter Number of Stops:";cin>>Stops;
  streng=40;
  do
  {
   cout<<"Enter Areacode:";cin>>areacode;
   if(areacode==1)
	strcpy(AreaNm,"R.K.Puram");
   else if(areacode==2)
	strcpy(AreaNm,"Hauz Khas");
   else if(areacode==3)
	strcpy(AreaNm,"Paharganj");
   else if(areacode==0)
	strcpy(AreaNm,"RESERVE");
   else if(areacode==4)
	strcpy(AreaNm,"Lajpat Nagar");
   else if(areacode==5)
	strcpy(AreaNm,"Chanakyapuri");
   else if(areacode==6)
	strcpy(AreaNm,"Janakpuri");
   else if(areacode==7)
	strcpy(AreaNm,"Paschim Vihar");
   else if(areacode==8)
	strcpy(AreaNm,"Greater Kailash");
   else if(areacode==9)
	strcpy(AreaNm,"Shahdara");
   else if(areacode==10)
	strcpy(AreaNm,"Rohini");
   else
	cout<<"No such area exists enter value between 1 and 10"<<endl;
  }while(areacode>10);
   if(areacode==0)
     status=2;
   else
     status=1;
   cout<<"Enter Driver number driving the bus:";
   cin>>Drvrnum;
  }

 void Driver::Enter(int N,int M)
  {     char ch;
	cout<<"Driver Number: ";Drvrnum=N;
	cout<<Drvrnum<<endl;
	cout<<"Is the driver a reserve?(Y/N)";
	cin>>ch;
	if(ch=='N'||ch=='n')
	{
		cout<<"Driver Shift: ";strcpy(shift,"5:30-15:00");
		puts(shift);
		cout<<endl;
		cout<<"Driver Salary: ";salary=15000;
		cout<<salary<<endl;
		attend=1;
	}
	else
	{
		cout<<"Driver Shift: ";strcpy(shift,"12:30-16:30");
		puts(shift);
		cout<<endl;
		cout<<"Driver Salary: ";salary=10000;
		cout<<salary<<endl;
		attend=2;
	}
	cout<<"Driver Busno:";Busno=M;
	cout<<Busno<<endl;
	cout<<"Driver Name:";gets(Drvrname);
	cout<<endl;
	cout<<"Conductor Name:";gets(CtrctName);
	cout<<endl;
}
/* *******************************************
EDIT ENTER FUNCTIONS
*********************************************** */
void BUS::editEnter()
{
  cout<<"Enter Number of Stops:";cin>>Stops;
  streng=40;
  do
  {
   cout<<"Enter Areacode:";cin>>areacode;
   if(areacode==1)
	strcpy(AreaNm,"R.K.Puram");
   else if(areacode==2)
	strcpy(AreaNm,"Hauz Khas");
   else if(areacode==3)
	strcpy(AreaNm,"Paharganj");
   else if(areacode==0)
	strcpy(AreaNm,"RESERVE");
   else if(areacode==4)
	strcpy(AreaNm,"Lajpat Nagar");
   else if(areacode==5)
	strcpy(AreaNm,"Chanakyapuri");
   else if(areacode==6)
	strcpy(AreaNm,"Janakpuri");
   else if(areacode==7)
	strcpy(AreaNm,"Paschim Vihar");
   else if(areacode==8)
	strcpy(AreaNm,"Greater Kailash");
   else if(areacode==9)
	strcpy(AreaNm,"Shahdara");
   else if(areacode==10)
	strcpy(AreaNm,"Rohini");
   else
	cout<<"No such area exists enter value between 1 and 10"<<endl;
  }while(areacode>10);
   if(areacode==0)
     status=2;
   else
     status=1;
   cout<<"Enter Driver number driving the bus:";
   cin>>Drvrnum;
  }
 void Driver::editEnter()
  {     cout<<"Driver Name:";gets(Drvrname);
	cout<<endl;
	cout<<"Conductor Name:";gets(CtrctName);
	cout<<endl;
  }
/*********************************************
 EDITING FINCTIONS
 ******************************************/
 void Reenter()
 {  fstream fil1,dfil1;
    BUS B;
    fil1.open("COREDATA.dat",ios::binary|ios::out|ios::in);
    cout<<"Enter the data in class"<<endl;
	       for(int i=0;i<6;i++)
	       {
			B.Enter();
			fil1.write((char*)&B,sizeof(B));
	       }
	      fil1.close();
	      fstream dfil;
	      Driver D;
	      cout<<"Enter the data in class"<<endl;
	      fil1.open("COREDATA.dat",ios::binary|ios::in);
		 for(int j=0;j<6;j++)
		{
			int temp,bustemp;
			char ch;
			fil1.read((char*)&B,sizeof(B));
			temp=B.Drvrnumret();
			bustemp=B.BusnoRet();
			D.Enter(temp,bustemp);
			dfil1.write((char*)&D,sizeof(D));
		}
		getch();
		clrscr();
		fil1.close();
		dfil1.close();
}
void Editbus()
{                fstream fil3;
 BUS B1;
 int Bno,f1=0;
	    cout<<"Enter Busno of Record you want to edit:";
	    cin>>Bno;
	    fil3.open("COREDATA.dat",ios::binary|ios::out|ios::in);
	    while(fil3.read((char*)&B1,sizeof(B1)))
	     {if(Bno==B1.BusnoRet()&&!f1)
	      {
	       B1.editEnter();
	       int N=fil3.tellg();
	       fil3.seekg(N-sizeof(B1));
	       fil3.write((char*)&B1,sizeof(B1));
	       f1++;
	      }
	     }
	      fil3.close();
	      getch();
	      clrscr();


}
void EditDriver()
{fstream dfil3;
 Driver D1;
 int Dno,f2=0;
	    cout<<"Enter Driver No of Record you want to edit:";
	    cin>>Dno;
	    dfil3.open("COREDINFO.dat",ios::binary|ios::in|ios::out);
	    while(dfil3.read((char*)&D1,sizeof(D1)))
	     {if(Dno==D1.Drvrnumret()&&!f2)
	      {
	       D1.editEnter();
	       int M=dfil3.tellg();
	       dfil3.seekg(M-sizeof(D1));
	       dfil3.write((char*)&D1,sizeof(D1));
	       f2++;
	      }
	     }
	      dfil3.close();
	      getch();
	      clrscr();
}
