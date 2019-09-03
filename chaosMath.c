#include <stdio.h> 

//-------------------------------------------------------------------
//chaos system default parameter
//-------------------------------------------------------------------
float y1[4], y2[4], y3[4], 
      u1, u2, 
      ax1, ax2, ax3, 
      dx1, dx2, dx3, 
      g1, g2, g3, g4, 
      h1, h2, j1, j2, 
      c1 = -0.5, c2 = 0.06, 
      A = 0.1;

//-------------------------------------------------------------------
//chaos system default key
//-------------------------------------------------------------------
float chaosKey,
      synControll = 0.1,
      USBKey1 = -12345, 
      USBKey2 = -543.21, 
      USBKey3 = 21.354;

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

void choasMath(float Us);
unsigned char* decimalIEEE754(int n, int i);

int main(){

	// Instantiate the union 
    myfloat var; 

    // Get the real value 
    var.f = USBKey1; 

	choasMath(var.f);

	

	return 0;
}

//-------------------------------------------------------------------
// @fn          choasMath
// @brief       This is the main entry of the "portion" application.
// @return      none
//-------------------------------------------------------------------
void choasMath(float Us){
  g1 = - ( ax1 / (ax2 * ax2) );
  g2 = 2 * ax1 * dx2 / (ax2 * ax2);
  g3 = - 0.1 * ax1 / ax3;
  g4 = ax1 * ( 1.76 - (dx2 * dx2) /  (ax2 * ax2) + 0.1 * ax1 * dx3 / ax3 ) + dx1;

  h1 = ax2 / ax1;
  h2 = - ( ax2 * dx1 ) / ax1 + dx2;
   
  j1 = ax3 / ax2;
  j2 = - ( ax3 * dx2 )/ ax2 + dx3;

  u2 = -(y2[k] * y2[k]) * g1 - y2[k] * g2 - y3[k] * g3 - y1[k] * c1 * h1 - y2[k] * c2 * j1 + y1[k] * A + y2[k] * c1 * A + y3[k] * c2 * A;

  y1[k+1]= g1 * y2[k] * y2[k] + g2 * y2[k] + g3 * y3[k] + g4 + Us + u2 ;//
  y2[k+1]= h1 * y1[k] + h2;
  y3[k+1]= j1 * y2[k] + j2;
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
