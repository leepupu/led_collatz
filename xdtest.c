#include<wiringPi.h>
#include<stdio.h>
#define d0 1
#define d1 4
#define d2 5
#define d3 6
#define e0 7
#define e1 0
#define e2 2
#define e3 3
void pinreset(void){
	digitalWrite(e0,0);
	digitalWrite(e1,0);
	digitalWrite(e2,0);
	digitalWrite(e3,0);
}

int main(){
	int input_r;
	wiringPiSetup();
	digitalWrite(e0,0);
	digitalWrite(e1,0);
	digitalWrite(e2,0);
	digitalWrite(e3,0);
	while(scanf("%d",&input_r)){
		pinreset();
		if(input_r==0){
			digitalWrite(d1,1);
			digitalWrite(d0,0);
			digitalWrite(e0,1);
			digitalWrite(e1,1);
		}
		if(input_r==1){
			digitalWrite(d1,0);
			digitalWrite(d3,1);
			digitalWrite(e1,1);
			digitalWrite(e3,1);
		}
		if(input_r==2){
			digitalWrite(d0,0);
			digitalWrite(d2,1);
			digitalWrite(e0,1);
			digitalWrite(e2,1);
		}
		if(input_r==3){
			digitalWrite(d0,1);
			digitalWrite(d1,0);
			digitalWrite(e0,1);
			digitalWrite(e1,1);
		}
		if(input_r==4){
			digitalWrite(d1,1);
			digitalWrite(d3,0);
			digitalWrite(e1,1);
			digitalWrite(e3,1);
		}
		if(input_r==5){
			digitalWrite(d1,0);
			digitalWrite(d2,1);
			digitalWrite(e1,1);
			digitalWrite(e2,1);
		}
		if(input_r==6){
			digitalWrite(d1,1);
			digitalWrite(d2,0);
			digitalWrite(e1,1);
			digitalWrite(e2,1);
		}
		if(input_r==7){
			digitalWrite(d0,1);
			digitalWrite(d2,0);
			digitalWrite(e0,1);
			digitalWrite(e2,1);
		}
		if(input_r==8){
			digitalWrite(d2,0);
			digitalWrite(d3,1);
			digitalWrite(e2,1);
			digitalWrite(e3,1);
		}
		if(input_r==9){
			digitalWrite(d2,1);
			digitalWrite(d3,0);
			digitalWrite(e2,1);
			digitalWrite(e3,1);
		}
}}
