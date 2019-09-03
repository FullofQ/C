#include <stdio.h> 

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