#include<iostream>
int a[1005];
int n;
bool flag = false;
void binarySearch(int left,int right, int x){
    if(left==right && a[left] != x){
        return;
    }
    else if(left==right && a[left] ==x){
        flag=true;
        return;
    }
    else{
        int mid =(right+left)/2;
        if(a[mid]==x){
            flag=true;
            return ;
        }
        else{
            if(a[mid] < x){
                binarySearch(left, (right+left)/2, x);
            }
            else{
                binarySearch((right+left)/2+1, right, x);
            }
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
    binarySearch(0,n-1,x);
    if(flag) cout<<"1";
    else cout<<"0";
    return 0;
}
