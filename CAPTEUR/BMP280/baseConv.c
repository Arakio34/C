#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<wiringPi.h>

uint16_t dig_T1 = 27504;
int16_t dig_T2 = 26435;
int16_t dig_T3 = -1000 ;
uint16_t dig_P1 = 36477;
int16_t dig_P2 = -10685;
int16_t dig_P3 = 3024;
int16_t dig_P4 = 2855;
int16_t dig_P5 = 140;
int16_t dig_P6 = -7;
int16_t dig_P7 = 15500;
int16_t dig_P8 = -14600;
int16_t dig_P9 = 6000;
//int32_t adc_T = 519888;
//int32_t adc_P = 415148;
double var1 = 0;
double var2 = 0;
double t_fine = 0;
double T = 0;
double P = 0;
/*
void initRegister(){
	uint16_t dig_T1 = wiringPiI2CRead16();
	int16_t dig_T2 = 26435;
	int16_t dig_T3 = -1000 ;
	uint16_t dig_P1 = 36477;
	int16_t dig_P2 = -10685;
	int16_t dig_P3 = 3024;
	int16_t dig_P4 = 2855;
	int16_t dig_P5 = 140;
	int16_t dig_P6 = -7;
	int16_t dig_P7 = 15500;
	int16_t dig_P8 = -14600;
	int16_t dig_P9 = 6000;
	int32_t adc_T = 519888;
	int32_t adc_P = 415148;
}
*/

double calcTemp(int32_t adc_T){
	var1 =(((double)adc_T/16384.0)-((double)dig_T1/1024))*dig_T2;
//	printf("var1 = %f\n", var1);	
	var2 =((((double)adc_T/131072.0)-((double)dig_T1/8192.0))*(((double)adc_T)/131072-((double)dig_T1)/8192.0))*((double)dig_T3);	
//	printf("var2 = %f\n", var2);	
	t_fine=var1+var2;
//	printf("t_fine = %f\n", t_fine);	
	T = (var1 + var2)/5120.0;
//	printf("Temperature : %f\n",T);
	return T;
}

double calcPression(int32_t adc_P){
	var1 = ((double)t_fine/2.0)-64000.0;
	printf("var1 = %f\n", var1);	
	var2 = var1*var1*((double)dig_P6)/32768.0;
	printf("var2 = %f\n", var2);	
	var2 = var2+var1*((double)dig_P5)*2.0;
	printf("var2 = %f\n", var2);	
	var2 =(var2/4.0)+(((double)dig_P4)*65536.0);
	printf("var2 = %f\n", var2);	
	var1 =(((double)dig_P3)*var1*var1/524288.0+((double)dig_P2)*var1)/524288.0;
	printf("var1 = %f\n", var1);	
	var1 =(1.0+var1/32768.0)*((double)dig_P1);
	printf("var1 = %f\n", var1);	
	P = 1048576.0 -(double)adc_P;
        printf("P = %f\n",P);
	P = (P-(var2/4096.0))*6250.0/var1;
        printf("P = %f\n",P);
	var1 =((double)dig_P9)*P*P/2147483648.0;
	printf("var1 = %f\n", var1);	
	var2 =P*((double)dig_P8)/32768.0;
	printf("var2 = %f\n", var2);	
	P = P+(var1+var2+((double)dig_P7))/16.0;
        printf("P = %f\n",P);
	return P;	
}

int main(){
	calcTemp(520368);
	calcPression(295868);
	return 0;
}
