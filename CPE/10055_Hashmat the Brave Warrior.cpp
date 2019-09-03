#include<iostream>
#include<cstdlib>//使用abs函數必須引入
using namespace std;

int main(){
   long long int a,b;//輸入值可能等於2^32，所以不使用unsigned int.
   while(cin>>a>>b){
      cout<<abs(a-b)<<endl;//abs()計算兩數差的絕對值
   }
   return 0;
}

