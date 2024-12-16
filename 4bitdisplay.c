#include<LPC21XX.H>
#include"can_fun.c"
#define lcd 0xf<<20
#define rs 1<<17
#define e 1<<19
#define rw 1<<18
void lcd_init(void);
void lcdcmd(unsigned char);
void display(unsigned char);
void str(unsigned char *);

void lcd_init(void){
  IODIR1=lcd|rs|rw|e;
  lcdcmd(0x01);
  lcdcmd(0x02);
  lcdcmd(0x0c);
  lcdcmd(0x28);
  lcdcmd(0x80);
}
void lcdcmd(unsigned char c){
IOCLR1=lcd;
IOSET1=(c&0xf0)<<16;
IOCLR1=rs;
IOCLR1=rw;
IOSET1=e;
delaymi(2);
IOCLR1=e;
IOCLR1=lcd;
IOSET1=(c&0x0f)<<20;
IOCLR1=rs;
IOCLR1=rw;
IOSET1=e;
delaymi(2);
IOCLR1=e;
}
void display(unsigned char p){
 IOCLR1=lcd;
 IOSET1=(p&0xf0)<<16;
 IOSET1=rs;
 IOCLR1=rw;
 IOSET1=e;
 delaymi(2);
 IOCLR1=e;
 IOCLR1=lcd;
 IOSET1=(p&0x0f)<<20;
 IOSET1=rs;
 IOCLR1=rw;
 IOSET1=e;
 delaymi(2);
 IOCLR1=e;
}
void str(unsigned char *p){
while(*p){
 display(*p++);
 }
 }
