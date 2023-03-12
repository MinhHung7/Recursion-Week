#include<iostream>
#include<math.h>
using namespace std;
void move(int n, int a, int b, int c){
    if(n==1){
        cout<<a<<" "<<c<<"\n";
    }
    else{
        move(n-1,a,c,b);
        move(1,a,b,c);
        move(n-1,b,a,c);
    }
}
int main(){
    int n; cin>>n;
    cout<<(int)pow(2,n)-1<<"\n";
    move(n,1,2,3);
    return 0;
}
