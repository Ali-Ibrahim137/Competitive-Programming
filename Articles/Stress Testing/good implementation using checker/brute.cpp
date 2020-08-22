#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(2*n);
    for(int i=0;i<2*n;i++)cin>>a[i];
    sort(a.begin(), a.end());
    do{
        int s1 = 0, s2 = 0;
        for(int i=0;i<n;i++){
            s1+=a[i];
            s2+=a[i+n];
        }
        if(s1!=s2){
            for(auto x:a)cout<<x<<" "; cout<<endl;
            exit(0);
        }
    }while(next_permutation(a.begin(), a.end()));
    cout<<-1<<endl;
}
