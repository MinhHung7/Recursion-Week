#include<iostream>
using namespace std;
void daoNguoc(int n){
    while(n%10==0 && n!=0) n/=10;
    if(n<10){
        cout<<n;
        return;
    }
    else{
        cout<<n%10;
        daoNguoc(n/10);
    }
}
long long X(int);
long long Y(int);
long long x[100000005]={0};
long long y[100000005]={0};
int mark[10000005]={0};
long long X(int n){
    if(n==0){
        x[0] = 1;
        return 1;
    }
    else if(x[n]!=0){
        return x[n];
    }
    else{
        x[n] =  X(n-1)+Y(n-1);
        return x[n];
    }
}
long long Y(int n){
    if(n==0){
        y[0] = 1;
        return 1;
    }
    else if(y[n]!=0){
        return y[n];
    }
    else{
        y[n] = X(n-1)*Y(n-1);
        return y[n];
    }
}

int demTwo(int n){
    if(n==1||n==2){
        mark[n] = n-1;
        return mark[n];
    }
    else if(mark[n]!=0) return mark[n];
    else{
        mark[n] = 1+demTwo(n/2);
        return mark[n];
    }
}
int main(){
    cout<<"Nhap so nguyen duong n: ";
    int n; cin>>n;
    cout<<"Ket qua 1: Dao nguoc cua "<<n<<" la: ";
    daoNguoc(n);
    cout<<"\n";
    cout<<"Ket qua 2: X("<<n<<") = "<<X(n)<<", Y("<<n<<") = "<<Y(n)<<"\n";
    cout<<"Ket qua 3: log(2) cua "<<n<<" la: "<<demTwo(n);
    return 0;
}

