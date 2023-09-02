#include <stdio.h>

int main(){
	float age, months, days, hours, minutes, seconds;
	printf("How old are you? ");
	scanf("%f", &age);
	
	//Take age and multiply each variation by their scalar
	months = age * 12;
	days = months * 30.437;
	hours = days * 24;
	minutes = hours * 60;
	seconds = minutes * 60;

	printf("You are %0.02f Years old.\n",age);
	printf("You are %0.02f Months old.\n",months);
	printf("You are %0.02f Days old.\n",days);
	printf("You are %0.02f Hours old.\n",hours);
	printf("You are %0.02f Minutes old.\n",minutes);
	printf("You are %0.02f Seconds old.\n",seconds);
}
