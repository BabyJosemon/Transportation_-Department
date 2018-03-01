#include "FNORDER.h"
void order(char* file)
{  fstream chaos, order,left,right,fil;

   order.open("ORDER.DAT", ios::binary|ios::out);
   left.open("LEFT.DAT", ios::binary|ios::out);
   right.open("RIGHT.DAT", ios::binary|ios::out);
   chaos.open(file, ios::binary|ios::in);
   fil.open("",ios::binary|ios::in);

   BUS B;

   for(fil.read((char*)&B, sizeof(B))   //    function to read direction
   {
	 if(bus.rd == "LEFT")
	 { left.write((char*)&B, sizeof(B));
	 }
	 else
	 { right.write((char*)&B, sizeof(B));
	 }
   }
   //sort left and right according strength;
   for();


   for(left.read((char*)&B, sizeof(B))   //    function to read direction
   {  order.write((char*)&B, sizeof(B));
   }
   for(right.read((char*)&B, sizeof(B))   //    function to read direction
   {  order.write((char*)&B, sizeof(B));
   }
}
face(1-15 left 25-40 right)? strength?


}
