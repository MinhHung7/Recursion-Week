#include<iostream>
using namespace std;
int add(int a, int b = 3);
int add(int a){
    return a;
}
int add(int a, int b){
    return a+b;
}

int main(){
    cout<<add(5);
    return 0;
}