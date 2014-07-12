#include <stdio.h>
#include <wiringPi.h>
#define EN_1 7
#define EN_2 0
#define EN_3 2
#define EN_4 3
#define DT_1 1
#define DT_2 4
#define DT_3 5
#define DT_4 6
int num2dt[][2] = {{DT_2, DT_1}, {DT_4, DT_2}, {DT_3, DT_1}, {DT_1, DT_2}, {DT_2, DT_4}, {DT_3, DT_2}, {DT_2, DT_3},
		   {DT_1, DT_3}/* 7 */, {DT_4, DT_3}, {DT_3, DT_4}};
int num2en[][2] = {{EN_1, EN_2}, {EN_2, EN_4}, {EN_3, EN_1}, {EN_1, EN_2}, {EN_2, EN_4}, {EN_2, EN_3}, {EN_2, EN_3},
		   {EN_1, EN_3}/* 7 */, {EN_4, EN_3}, {EN_4, EN_3}};

void light_off_all()
{
	digitalWrite(EN_1, 0);
	digitalWrite(EN_2, 0);
	digitalWrite(EN_3, 0);
	digitalWrite(EN_4, 0);
}

void light_on(int n)
{
	printf("tail: %d\n", n);
	light_off_all();
	delay(50);
	digitalWrite(num2en[n][0], 1);
	digitalWrite(num2en[n][1], 1);
	digitalWrite(num2dt[n][0], 1);
	digitalWrite(num2dt[n][1], 0);
	delay(400);
}

void setupWiring()
{
	wiringPiSetup();
	pinMode(EN_1, OUTPUT);
	pinMode(EN_2, OUTPUT);
	pinMode(EN_3, OUTPUT);
	pinMode(EN_4, OUTPUT);
	pinMode(DT_1, OUTPUT);
	pinMode(DT_2, OUTPUT);
	pinMode(DT_3, OUTPUT);
	pinMode(DT_4, OUTPUT);
}

void test()
{
	int i=0;
	for(i=0;;i++)
	{
		if(i==10)
			i=0;
		light_on(i);
	}
}

int main()
{
	setupWiring();
	unsigned int n;
	//test();
	while(scanf("%d", &n))
	{
		light_on(n%10);
		while(n != 1)
		{
			if(n %2 == 0)
				n /= 2;
			else
				n = 3*n + 1;
			light_on(n%10);
		}
	}
}
