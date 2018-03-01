#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include "FNASSIGN.h"
#include "FNMERGE.h"
#include "FNORDER.h"
class BUS
{
 int Busno,Stops,streng,areacode,att,status,Drvrnum[20],Connum[20];
 char StpNm[20][5],Area[20];
 public:

 void Display()
{
 cout<<"The Bus Number is: "<<Busno<<endl;
 cout<<"The Status of the Bus is: "<<status<<endl;
 cout<<"The Number of Stops are: "<<Stops<<endl;
 cout<<"The Area you entered is: ";puts(Area);
 cout<<endl;
}
 char *Arearet()
{
 return Area;
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
 void strenginc()
{
 streng++;
}
};
