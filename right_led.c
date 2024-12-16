#include<LPC21XX.H>
#include"can_fun.c"
#define LED 1<<18

int main(){
 struct frame m;
 int i=0;
 IODIR0=LED;
 IOSET0=LED;
 can_init();
 while(1){
  rxd(&m);
  if(m.id==0x0B){
    if(i==0){
    IOCLR0=LED;
	i=1;
	}
	else{
	IOSET0=LED;
	i=0;
	}        
  }
 
 }
}
