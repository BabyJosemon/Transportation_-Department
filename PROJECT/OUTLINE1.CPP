#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
class BUS
{
 int Busno,Stops,streng,areacode,att,status,subarea,Drvrnum[20],Connum[20];
 char StpNm[20][5],Area[20];
 public:
 void Display()     {

					}
 void AreaRet()     {
					}
 int BusnoRet()     {
					}
 int attret()       {
					}
 int strengret()    {
					}
 int areacoderet()  {
					}
 };
struct Driver
{
 int num,shift,attend,Busno;
 float salary;
 char Drvrname[20],CtrctName[20];
};

void Recdel()
{
 fstream subs,del;
 BUS B;
 subs.open("Subs.dat",ios::binary|ios::in);
 del.open("del.dat",ios::binary|ios::out);
 int delbusno,Delete=0;;
 cout<<"Record to delete:";
 cin>>delbusno;
 while(subs.read((char*)&B,sizeof(B)))
 {
  if(delbusno!=B.BusnoRet())
  {
   del.write((char*)&B,sizeof(B));
  }
  else
  Delete++;
 }
 if(Delete)
 {
  remove("subs.dat");
  rename("del.dat","subs.dat");
 }

 subs.close();
}
void Sort()
{
 fstream subs;
 subs.open("subs.dat",ios::binary|ios::in|ios::out);
 subs.seekg(0,ios::end);
 int NOR=subs.tellg()/sizeof(BUS);
 BUS B,B1;
 for(int i=0;i<NOR-1;i++)
  for(int j=0;j<NOR-i-1;j++)
  {
   subs.seekg(j*sizeof(BUS));
   subs.write((char*)&B1,sizeof(BUS));
   subs.write((char*)&B,sizeof(BUS));
   if(B.areacoderet()>B1.areacoderet())
   {
	subs.seekp(j*sizeof(BUS));
	subs.write((char*)&B1,sizeof(BUS));
	subs.write((char*)&B,sizeof(BUS));
   }
  }
 subs.close();
}
void mergerecords()
{
 fstream fil;

}
void mergebus()
{
 fstream fil,subs;
 fil.open("Data.dat",ios::binary|ios::in);
 subs.open("Subs.dat",ios::binary|ios::out);
 BUS B,B1,B2;
 while(fil.read((char*)&B,sizeof(B)))
 {
  if(B.attret()<((B.strengret())/2))
   {
   /*	cout<<"Bus number"<<B.Busnoret()<<"is up for merging:"<<endl;
   */
	subs.write((char*)&B,sizeof(B));
   }
 }

 Sort();  //SORT ACCORDING TO AREACODE
 int n;
 fstream subs2;
 subs2.open("subs2.dat",ios::binary|ios::out|ios::in);
 while(subs.read((char*)&B,sizeof(B)))
 {
  n=B.areacoderet();
  subs2.write((char*)&B,sizeof(B));
  while(B.areacoderet()==n&&fil.read((char*)&B,sizeof(B)))
   {
	subs2.write((char*)&B,sizeof(B));
   }
  while(subs2.read((char*)&B1,sizeof(B1)))
  {
   if(subs2.read((char*)&B2,sizeof(B2)))
   cout<<"Bus Number:"<<B1.BusnoRet()<<"&"<<B2.BusnoRet()<<"have been merged";
  }
 }
 remove("subs2.dat");

}

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



/* while(subs.read((char*)&B,sizeof(B)))
 {
  char Subs[20];
  strcpy(B.AreaRet(),Subs);
  int no;
  no=B.Busnoret();
  while(subs.read((char*)&B,sizeof(B)))
   {
	if(strcmpi(Subs,B.AreaRet())==0)
	 {
	  cout<<"Bus number:"<<no<<"and"<<B.Busnoret()<<"are merged"<<endl;
	 }
   }

 }*/












