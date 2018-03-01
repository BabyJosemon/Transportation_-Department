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
		cout<<"Sorry we do not run buses to that location."
	 else
		cout<<"We have a driver for you"<<endl;
		cout<<"Bus Number: "<<A.Busno<<endl;
		cout<<"Status: "<<A.status<<endl;
		cout<<"Driver Number"<<A.Drvrnum<<endl;
		cout<<"Conductor Number"<<A.Connum<<endl;
		A.streng++//Make inbuilt class fn to increase strength
	}
	fil.close();
}

/*
	 order of buses  (print o.o)
	 merging buses (no print)
	 want to use bus temporarily:assign bus (give name
	 ) take NM and area to give busno
	attendence fn:enter status of bus(thukki hai kya?)
	dhanda(school admission)
	CLASS Functions:
	 entering displaying certain member
	 returning values function:
	 struct DRIVER for driver name hours of work, status ,shift,bussassigned
*/
