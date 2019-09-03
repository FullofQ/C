#include <stdio.h>
#include <string.h>

//ieee754:010 000 010 100 010 110 | 000 101 000 111 11
float usbKey1 = 12.345;

//ieee754:010 000 100 101 100 101 | 001 000 101 101 00
float usbKey2 = 54.321;

//ieee754:110 000 010 100 010 110 | 000 101 000 111 11
float usbKey3 = -12.345;

//ieee754:110 000 011 010 101 011 | 010 100 111 111 10
float usbKey4 = -21.354;

//ieee754:001 111 111 001 110 100 | 001 110 010 101 10
float usbKey5 = 12.5;

//Struct

//球的結構
struct Ball {
    char color[10];
    double radius;
};

typedef unsigned char uint8;

//4.typedef定義struct名稱，宣告產生對象，不必加上struct
typedef struct Ball ballType;

//transfer floatd data to IEEE754
struct IEEE754float{
    uint8 K:2; 
    uint8 J:3; 
    uint8 I:3; 
    uint8 H:3; 
    uint8 G:3;
	/* ============= */
    uint8 F:3;
    uint8 E:3;
    uint8 D:3; 
    uint8 C:3;
    uint8 B:3;
    uint8 A:3;
};

void clonBall(struct Ball ball);

int main(void) {
	
	//1.初始化並賦值
    struct Ball ball1 = {"red", 5.0};

	//1.初始化
    struct Ball ball2;
    //1.再賦值
	strcpy(ball2.color, "green");
    ball2.radius = 10.0;
	
	//一個結構，可以初始化成好幾個對象:ball1/ball2......

	//宣告結構指標
	struct Ball* ptr;
	//存放實體化資料的位址
	ptr = &ball1;
	//2.1 存取結構成員：宣告的名稱加上 . 運算子
	printf("ball1: %s,\t%.2f\n",ball1.color,ball1.radius);
	//2.2 存取結構成員：利用指標
	printf("ball1: %s,\t%.2f\n",ptr->color,ptr->radius);

	struct IEEE754float* ieeeptr1;
	struct IEEE754float* ieeeptr2;
	/*warning: assignment from incompatible pointer type
	ieeeptr1 = &usbKey1;
	*/

	//void*
	ieeeptr1 = (void*)&usbKey5;
	printf("usbKey1 address:%d\n",ieeeptr1);
	printf("IEEE754float_A: %d\n",ieeeptr1->A);
	printf("IEEE754float_B: %d\n",ieeeptr1->B);
	printf("IEEE754float_C: %d\n",ieeeptr1->C);
	printf("IEEE754float_D: %d\n",ieeeptr1->D);
	printf("IEEE754float_E: %d\n",ieeeptr1->E);
	printf("IEEE754float_F: %d\n",ieeeptr1->F);
	printf("IEEE754float_G: %d\n",ieeeptr1->G);
	printf("IEEE754float_H: %d\n",ieeeptr1->H);
	printf("IEEE754float_I: %d\n",ieeeptr1->I);
	printf("IEEE754float_J: %d\n",ieeeptr1->J);
	printf("IEEE754float_K: %d\n",ieeeptr1->K);

	/* (struct IEEE754float*)
	ieeeptr1 = (struct IEEE754float*) ((void*)&usbKey1);
	ieeeptr2 = (struct IEEE754float*) ((void*)&usbKey2);
	printf("usbKey1 address:%d\n",ieeeptr1);
	printf("usbKey2 address:%d\n",ieeeptr2);
	printf("IEEE754float_A: %d\n",ieeeptr1->A);
	printf("IEEE754float_B: %d\n",ieeeptr1->B);
	printf("IEEE754float_C: %d\n",ieeeptr1->C);
	printf("IEEE754float_D: %d\n",ieeeptr1->D);
	printf("IEEE754float_E: %d\n",ieeeptr1->E);
	printf("IEEE754float_F: %d\n",ieeeptr1->F);
	printf("IEEE754float_G: %d\n",ieeeptr1->G);
	printf("IEEE754float_H: %d\n",ieeeptr1->H);
	printf("IEEE754float_I: %d\n",ieeeptr1->I);
	printf("IEEE754float_J: %d\n",ieeeptr1->J);
	printf("IEEE754float_K: %d\n",ieeeptr1->K);
	*/

    return 0;
}

void clonBall(struct Ball ball){
	ball.radius=100.0;
}
