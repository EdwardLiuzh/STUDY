#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>ivec;
    int ival;
    cout<<"Enter numbers('q' to end): "<<endl;
    while(cin>>ival)
    {
        ivec.push_back(ival);
    }
    if(ivec.size()==0)
    {
        cout<<"None!"<<endl;
        return -1;
    }
    cout<<"The sum of elements in vector is: "<<endl;
    vector<int>::iterator first,last;
    for(first=ivec.begin(),last=ivec.end()-1;first<last;++first,--last)
        cout<<*first+*last<<"\t";
    if(first==last)
        cout<<"no sum,the value is: "<<*first<<endl;
    return 0;
}