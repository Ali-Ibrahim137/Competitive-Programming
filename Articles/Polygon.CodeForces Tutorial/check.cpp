#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
bool has[1010];
bool prime(int x){
    if(x == 1)return false;
	for(int i = 2; i * i <= x;i++){
		if(x%i == 0)return false;
	}
	return true;
}
int readAns(InStream& stream) {
    int ans = stream.readInt(1, 1000);
    if(has[ans] == 0)return -1;
    if(prime(ans) == 0)return 0;
    return 1;
}

int main(int argc, char * argv[]){
    registerTestlibCmd(argc, argv);
    int n = inf.readInt();
    for(int i=0;i<n;i++){
		int x = inf.readInt();
		has[x] = 1;
	}
    
    int jans = readAns(ans);
    int pans = readAns(ouf);
    if(jans==0)quitf(_fail, "Jury answer Incorrect, The number is not prime!!!");
    if(jans==-1)quitf(_fail, "Jury answer Incorrect, the number is not from the input array!!!");
    
    if(pans==0)quitf(_wa, "participant answer Incorrect, The number is not prime.");
    if(pans==-1)quitf(_wa, "participant answer Incorrect, the number is not from the input array.");
    if (!ans.seekEof())quitf(_fail, "Jury answer contain extra tokens!!!");
    if (!ouf.seekEof())quitf(_wa, "Participant answer contain extra tokens.");
    quitf(_ok, "Passed all tests.");
}


