#include<iostream>
#include<vector>
using namespace std;
void mergearray(vector<int>&nums1, int m,vector<int>&nums2, int n){
    int end=m+n-1;
    while(n){
        if(m==0||nums1[m-1]>nums2[n-1]){
            nums1[end--]=nums1[m-1];
            m--;
        }
        else{
            nums1[end--]=nums2[n-1];
            n--;
        }
    }
}

int main(int argc, char const *argv[]) {
    vector<int>n1={1,2,3,4,0,0,0};
    vector<int>n2={4,6,7};
    mergearray(n1,4,n2,3);
    int sz=n1.size();
    for(int i=0;i<sz;i++){
        cout<<n1[i]<<' ';
    }
    cout<<endl;
    return 0;
}
