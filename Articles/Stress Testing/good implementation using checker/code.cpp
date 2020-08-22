#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	long long n;
	cin>>n;
	long long sum2 = 0;
	for(long long i = 1;i<=2*n;i++){
		cin>>a[i];
		sum2+=a[i];
	}
	sort(a+1,a+1+2*n);
	long long sum=0;
	for(long long i = 1;i<=n;i++){
		sum+=a[i];
	}
	if(sum==sum2/2) cout<<"-1";
	else for(long long i = 1;i<=2*n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
