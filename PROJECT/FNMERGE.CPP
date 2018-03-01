#include "FNMERGE.h"
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
