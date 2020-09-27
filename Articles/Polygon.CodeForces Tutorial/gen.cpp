#include "testlib.h"
#include <bits/stdc++.h>
#define pb push_back
#define ll long long int
#define ii pair<int, int>
using namespace std;
bool prime(int x){
    if(x == 1)return false;
	for(int i = 2; i * i <= x;i++){
		if(x%i == 0)return false;
	}
	return true;
}
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	int min_n = atoi(argv[1]);
	int max_n = atoi(argv[2]);
	int n = rnd.next(min_n, max_n);
	cout<<n<<endl;
	vector<int>a(n);
	bool has_prime = false;
	for(int i = 0;i < n;i++){
		a[i] = rnd.next(1, 1000);
		has_prime|=prime(a[i]);
	}
	while(!has_prime){
		int x = rnd.next(1, 1000);
		has_prime|=prime(x);
		a[0] = x;
	}
	shuffle(a.begin(), a.end());
	cout<<a[0];
	for(int i = 1;i < n;i++){
		cout<<" "<<a[i];
	}
	cout<<endl;
    return 0;
}
