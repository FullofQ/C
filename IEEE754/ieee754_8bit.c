// C program to convert a real value 
// to IEEE 754 floating point representaion 
#include <stdio.h> 

unsigned char decimal[4];


typedef union { 
  
    float f; 
    struct
    { 
        unsigned char ieee754_A : 8;
		unsigned char ieee754_B : 8;
		unsigned char ieee754_C : 8;
		unsigned char ieee754_D : 8;
    } raw; 
} myfloat; 

void printBinary(int n, int i);
void printIEEE(myfloat var);
unsigned char* decimalIEEE754(int n, int i);

// Driver Code 
int main() 
{ 
  
    // Instantiate the union 
    myfloat var; 
  
    // Get the real value 
    var.f = 0.1; 
  
    // Get the IEEE floating point representation 
    printf("IEEE 754 representation of %f is : \n", 
           var.f); 
    printIEEE(var); 
	
	//printf("\n");
	decimal[0]=*(decimalIEEE754(var.raw.ieee754_D,8));
	printf("decimalD:%d\n",decimal[0]);
	return 0; 
} 

void printBinary(int n, int i) 
{ 
  
    // Prints the binary representation 
    // of a number n up to i-bits. 011
    int k; 
	
    for (k = i - 1; k >= 0; k--) { 
  
        if ((n >> k) & 1){ 
			//int decimalExponet = k-1;
            printf("1"); 
			//decimal+=2<<decimalExponet;
			//decimalExponet=0;
			//2<<k+1
        }else
            printf("0"); 
		
		//if(k = 0) decimal = 0;
    } 
}

// Function to convert real value 
// to IEEE foating point representation 
void printIEEE(myfloat var) 
{ 
  
    // Prints the IEEE 754 representation 
    // of a float value (32 bits) 

    printBinary(var.raw.ieee754_D, 8); 
	
	/*/decimal
	printf("(");
	printf("%d",decimal);
	decimal=0;
	printf(")");
	*/

	printf(" | "); 
    printBinary(var.raw.ieee754_C, 8); 

	/*decimal
	printf("(");
	printf("%d",decimal);
	decimal=0;
	printf(")");
	*/

    printf(" | "); 
	printBinary(var.raw.ieee754_B, 8); 
    printf(" | "); 
	printBinary(var.raw.ieee754_A, 8); 
    printf(" | ");  
	//printf("")
} 

unsigned char* decimalIEEE754(int n, int i){
	// Prints the binary representation 
    // of a number n up to i-bits. 011
    int k; 
	unsigned char decimal = 0;
	unsigned char* decimalAddress = &decimal;
    for (k = i - 1; k >= 0; k--) { 
  
        if ((n >> k) & 1){ 
			unsigned int decimalExponet = k;
			if(decimalExponet == 0) decimal++;
			decimal+=2<<decimalExponet-1;
			decimalExponet=0;
			//printf("1");
        }
    }
	return decimalAddress;
}
