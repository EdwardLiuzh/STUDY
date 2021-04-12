#include<iostream>
using namespace std;
template <class T>
int getArrayLen(T&array)
{
    return sizeof(array) / sizeof(array[0]);
}

int MostWater(int* nums,int len){
    int i=0;
    int j=len-1;
    int start,end,h,w,Vc,max=0;
    int index[2]={i,j},max_index[2];
    while(i<j){
        start=nums[i];
        end=nums[j];
        w=j-i;
        index[0]=i;
        index[1]=j;
        if(start<end){
            h=start;
            i++;
        }
        else{
            h=end;
            j--;
        }
        Vc=w*h;
        if(Vc>max){
            max=Vc;
            max_index[0]=index[0];
            max_index[1]=index[1];
        }
    }
    cout<<max_index[0]<<" "<<max_index[1]<<endl;
    return max;
}

int main(){
    int array[]={1,8,6,2,5,4,8,3,7};
    int length=getArrayLen(array);
    cout<<MostWater(array,length)<<endl;
    return 0;
}
