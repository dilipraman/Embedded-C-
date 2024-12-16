#include<LPC21XX.H>
#include"can_fun.c"
#include"4bitdisplay.c"
#define SW1 14
#define SW2 15
#define SW3 16

int main(){
	struct frame m1,m2,m3;
	int l=0,r=0,w=0;
	can_init();
	lcd_init();
	m1.id=0x0A;
	m1.rtr=0;
	m1.dlc=4;
	m1.byteA=0;
	m1.byteB=0;
	m2.id=0x0B;
	m2.rtr=0;
	m2.dlc=4;
	m2.byteA=0;
	m2.byteB=0;
	m3.id=0x0C;
	m3.rtr=0;
	m3.dlc=4;
	m3.byteA=0;
	m3.byteB=0;
	str("BODY CONTROL");
while(1){

 if(((IOPIN0>>SW1)&1)==0){
    //delaymi(100);
    lcdcmd(0x01);
	lcdcmd(0x80);
    str("BODY CONTROL");
    lcdcmd(0xc0);
 	if(l==0){
 	str("LEFT LED ON");
	l=1;
	}
	else{
	  str("LEFT LED OFF");
	  l=0;
	}
	txd(m1);
	delaymi(2);

 }
 if(((IOPIN0>>SW2)&1)==0){
     //delaymi(100);
    lcdcmd(0x01);
	lcdcmd(0x80);
    str("BODY CONTROL");
    lcdcmd(0xc0);
	if(r==0){
 	str("RIGHT LED ON");
	r=1;
	}
	else{
	  str("RIGHT LED OFF");
	  r=0;
	}
    txd(m2);
	delaymi(2);
 }
 if(((IOPIN0>>SW3)&1)==0){
    //delaymi(250);
    lcdcmd(0x01);
	lcdcmd(0x80);
    str("BODY CONTROL");
    lcdcmd(0xc0);
    if(w==0){
 	str("WIPER ON");
	w=1;
	}
	else{
	  str("WIPER OFF");
	  w=0;
	}
	txd(m3);
	delaymi(2);
 }


}


}

