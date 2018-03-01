 class BUS
{
 int Busno,Stops,streng,areacode,att,status,Drvrnum[20],Connum[20];
 char StpNm[20][5],Area[20];
 public:

 void Display()
{
 BUS C;
 cout<<"The Bus Number is: "<<C.Busno<<endl;
 cout<<"The Status of the Bus is: "<<C.status<<endl;
 cout<<"The Number of Stops are: "<<C.Stops<<endl;
 cout<<"The Area you entered is: ";puts(Area);
 cout<<endl;
}
 void AreaRet()
{
 puts(Area);
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
};

/*
   order of buses  (print o.o)  DONE
   merging buses (no print)
   want to use bus temporarily:assign bus (give name
   ) take NM and area to give busno  DONE
	attendence fn:enter status of bus(thukki hai kya?)
	dhanda(school admission)
	CLASS Functions:
   entering displaying certain member
   returning values function:
   struct DRIVER for driver name hours of work, status ,shift,bussassigned
*/
