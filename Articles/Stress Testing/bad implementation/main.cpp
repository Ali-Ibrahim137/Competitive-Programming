#include <bits/stdc++.h>
using namespace std;

int rnd(int a, int b){
    return a + rand() % (b - a + 1);
}
int generator(){
    // This function acts as a generator.
    int w = rnd(1, 100);
    return w;
}
string solve(int w){
    // This function acts as the WA solution to test.
    if(w%2==0)return "YES";
    return "NO";
}

string bruteForce(int w){
    // This function acts as the brute force solution.
    for(int i=1;i<w;i++){
        int j = w - i;
        if(i%2==0 && j%2==0)return "YES";
    }
    return "NO";
}
void check(int w, string myAnswer, string correctAnswer){
    // This function acts as the checker.
    if(myAnswer == correctAnswer)return;
    cout<<"Found the WA test"<<endl;
    cout<<"W = "<<w<<endl;
    cout<<"myAnswer = "<<myAnswer<<endl;
    cout<<"correctAnswer = "<<correctAnswer<<endl;
    exit(0);
}
int main() {
    for(int i=1;;i++){
        int w = generator();
        string myAnswer = solve(w);
        string correctAnswer = bruteForce(w);
        check(w, myAnswer, correctAnswer);
        cout<<"Passed test: "<<i<<endl;
    }
}
