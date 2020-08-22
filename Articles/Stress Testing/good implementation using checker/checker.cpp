#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int a[22];
int b[22];
int n;
int readAns(ifstream &fin){
    int ans;
    fin>>ans;
    if(ans==-1)return ans;
    b[0] = ans;
    for(int i=1;i<2*n;i++)fin>>b[i];
    int s1 = 0, s2 = 0;
    for(int i=0;i<n;i++){
        s1+=b[i];
        s2+=b[i+n];
    }
    if(s1==s2)return -2;                // Sums are equal
    sort(b,b+2*n);
    for(int i=0;i<2*n;i++){
        if(a[i]!=b[i])return 0;         // Printing another array
    }
    return 1;                           // Correct answer
}
int main(int argc, char * argv[]){
    ifstream fin("input_file", ifstream::in);
    ifstream ans("myAnswer", ifstream::in);
    ifstream cor("correctAnswer", ifstream::in);
    fin>>n;
    for(int i=0;i<2*n;i++)fin>>a[i];
    sort(a,a+2*n);
    int myAnswer = readAns(ans);
    int correctAnswer = readAns(cor);
    if(myAnswer==-2){
        cout<<"WA Sums are equal"<<endl;
        return -1;
    }
    if(myAnswer==0){
        cout<<"WA Printing another array"<<endl;
        return -1;
    }
    if(myAnswer == -1 && correctAnswer == 1){
        cout<<"Brute force found a solution, but the code didn't find"<<endl;
        return -1;
    }
    return 0;
}
