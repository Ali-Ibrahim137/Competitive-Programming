#include <bits/stdc++.h>
using namespace std;
int main() {
    int w;
    cin>>w;
    for(int i=1;i<w;i++){
        int j = w - i;
        if(i%2==0 && j%2==0){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}
