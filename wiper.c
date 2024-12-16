#include<LPC21XX.H>
#include"can_fun.c"
#define PIN1 1<<14
#define PIN2 1<<15


int main(){
 struct frame m;
 int i=0;
 IODIR0=PIN1|PIN2;
 can_init();
 while(1){
  rxd(&m);
  if(m.id==0x0C){
    if(i==0){
    IOCLR0=PIN1;
	IOSET0=PIN2;
	i=1;
	}			    
	else{
	IOSET0=PIN1;
	IOSET0=PIN2;
	i=0;
	}        
  }
 
 }
}
