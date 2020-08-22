#include <bits/stdc++.h>
using namespace std;
int rnd(int a, int b){
    return a + rand() % (b - a + 1);
}
int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    int n = rnd(1, 5);
    cout<<n<<endl;
    for(int i=0;i<2*n;i++){
        int x = rnd(1, 10);
        cout<<x<<" ";
    }
    cout<<endl;
}
