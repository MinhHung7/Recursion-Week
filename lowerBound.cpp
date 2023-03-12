#include<iostream>
int a[1005];
int n;
int pos=0;
void lowerBound(int left,int right, int x){
    if(left==right){
        if(a[left]==x){
            pos = left;
        }
        return;
    }
    else{
        int mid = (right+left)/2;
        if(a[mid] >= x){
            pos = mid;
            lowerBound(left, mid, x);
        }
        else{
            lowerBound(mid+1, right, x);
        }
    }
}
using namespace std;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int x; cin>>x;
    if(a[n-1]<x){
        cout<<n;
    }
    else{
        lowerBound(0,n-1,x);
        cout<<pos;
    }
    return 0;
}
