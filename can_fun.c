#include<LPC21XX.H>
struct frame{
  int id;
  int rtr;
  int dlc;
  int byteA;
  int byteB;
};

void can_init(){

  PINSEL1=0x00014000;
  VPBDIV=1;
  C2MOD=0x01;
  AFMR=0x02;
  C2BTR=0x001c001d;
  C2MOD=0x00;

}
void delaymi(int d){
	T0PR=60000-1;
    T0TCR=0x01;
	while(T0TC<d);
	T0TCR=0x03;
	T0TCR=0x00;
}

void txd(struct	frame m){
  
 C2TID1=m.id;
  C2TFI1=(m.dlc<<16);
  if(m.rtr==0){
    	C2TFI1&=~(1<<30);
		C2TDA1=m.byteA;
		C2TDB1=m.byteB;
  
  }
  else{
     C2TFI1|=(m.rtr<<30);
  
  }
  C2CMR=(1<<0)|(1<<5);
  while(((C2GSR>>3)&1)==0);
}

void rxd(struct frame *m){
  while((C2GSR&1)==0);
 m->id=C2RID;
 m->dlc=(C2RFS>>16)&0xf;
 m->rtr=(C2RFS>>30)&0x1;
 if(m->rtr==0){
   m->byteA=C2RDA;
   m->byteB=C2RDB;
 
 }
 C2CMR=(1<<2);

}
