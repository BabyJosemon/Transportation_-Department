#include "FNASSIGN.h"
void assign()
{
fstream fil;
char dest[30];
int found=0;
BUS A;
 fil.open("stops.dat",ios::binary|ios::in);
 cout<<"Enter your Destination: ";
 gets(dest);
 while(fil.read((char*)&A,sizeof(A)))
 {
  if(strcmpi(A.Arearet(),dest)==0)
   {
	found++;
   }
 }
  {
   if(found==0)
	cout<<"Sorry we do not run buses to that location.";
   else
	A.Display();
	A.strenginc();//Make inbuilt class fn to increase strength
  }
	fil.close();
}
