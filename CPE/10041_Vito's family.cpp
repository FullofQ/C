#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> num;	//宣告vector

int main(){
   int n,r,s;
   cin>>n;			//輸入測試資料筆數
   while(n--){
		cin>>r;		//輸入親戚個數
		num.clear();

		//將親戚接號輸入到vector
		for(int i=0;i<r;i++){
			cin>>s;
			num.push_back(s);
		}

		sort(num.begin(),num.end());//將vector內的號碼做升冪排序
		int mid=num[r/2];//取出中位數

		//計算Vito;s home到各親戚家距離總和
		int sum=0;
		for(int i=0;i<r;i++){
			sum+=abs(num[i]-mid);
		}

		cout<<sum<<endl;
   }
   system("pause");
   return 0;
}
