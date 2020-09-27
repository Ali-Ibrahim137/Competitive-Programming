#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
bool prime(int x){
    if(x == 1)return false;
	for(int i = 2;i * i <= x;i++){
		if(x%i == 0)return false;
	}
	return true;
}
int main(int argc, char** argv){
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1000,"N");
    inf.readEoln();
    bool has_prime = false;
    for(int i = 1;i <= n;i++){
		int x = inf.readInt(1, 1000, "X");
		has_prime|=prime(x);
		if(i != n)inf.readSpace();
	}
	inf.readEoln();
    ensuref(has_prime, "There is no prime number!");
    inf.readEof();
    return 0;
}

