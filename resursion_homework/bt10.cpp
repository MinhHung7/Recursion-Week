#include<iostream>
#include<time.h>
using namespace std;
int arr[100000005];
int soLuong = 0;
void random(int n){
    if(n==0) return;
    else{
        int x = rand()%100 + 1;
        arr[soLuong++] = x;
        cout<<x<<" ";
        random(n-1);
    }
}

int maxNum(int a[], int n){
    if(n==1){
        return a[0];
    }
    else{
        if(a[n-1] > maxNum(a, n-1)){
            return a[n-1];
        }
        else return maxNum(a, n-1);
    }
}
int maxNumPos(int a[], int n){
    if(n==1) return 0;
    if(a[n-1] > maxNum(a, n-1)) return n-1;
    else{
        return maxNumPos(a, n-1);
    }
}
void hoanVi(int a[], int b,int c){
    int t = a[b];
    a[b] = a[c];
    a[c]  =t;
}
void sapXep(int a[], int n){
    if(n==1){
        return ;
    }
    else{
        hoanVi(a, maxNumPos(a, n), n-1);
        sapXep(a, n-1);
    }
}
int main(){
    srand(time(NULL));
    cout<<"Nhap so nguyen duong n: ";
    int n; cin>>n;
    cout<<"Ket qua 1: "<<n<<" phan tu random tu 1->100 la: ";
    random(n);
    cout<<"\n";
    sapXep(arr, soLuong);
    cout<<"Ket qua 2: Day so sau khi sap xep la: ";
    for(int i=0;i<soLuong;++i){
        cout<<arr[i]<<" ";
    }
    return 0;
}
