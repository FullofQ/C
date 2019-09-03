#include<iostream>
using namespace std;

//將數字n分解後存入陣列arr，同時將數字的位數存入變數cnt中
//&cnt為位址，對應到數字的位數
int divide(int n,int arr[],int &cnt){
   for(cnt=0;n!=0;cnt++){
      arr[cnt]=n%10;					//數字n除10取餘數，用來分解數字
      n=n/10;							//數字n每除一次10就少1位數，直到個位數變成0(除到變小數)就知道數字的位數
   }
}

int main(){
   int a, b;
   while(cin>>a>>b && (a!=0||b!=0)){	//讀入兩數皆為0時終止迴圈
      int lenA, lenB;					//數字的位數				
      int arrA[11]={},arrB[11]={};		//儲存分解後數字a、b的陣列,初值為0
      int sum[12]={};					//儲存相加後的值，初值為0
      divide(a,arrA,lenA);				//分解數字a後，存入arra
      divide(b,arrB,lenB);				//分解數字b後，存入arrb
      int lenM=max(lenA,lenB);			//max()取數字a、b長度較大者，後續計算到0~lenM-1為止
      int ans=0;
      
	  //計算0至len-1每位數相加，並記錄進位次數
	  for(int i=0;i<lenM;++i){
         sum[i]+=(arrA[i]+arrB[i]);		//進位變數(sum[])+數字a+數字b
		 
		 //檢查是否超過10，若大於等於10需要進位
         if(sum[i]>=10){
            sum[i]-=10;					//sum[i]=sum[i]-10:把相加的值(不含進位)存入陣列
			sum[i+1]++;					//進位變數(sum[])+1
            ++ans;						//進位統計變數
         }
      }

      if(ans==0)
         cout<<"No carry operation.\n";
      else if(ans==1)
         cout<<"1 carry operation.\n";
      else
         cout<<ans<<" carry operations.\n";
   }
   system("pause");
   return 0;
}
