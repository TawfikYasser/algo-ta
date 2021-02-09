//Tawfik Yasser
#include <iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int minSeekTime(vector<int> vList,int head,int list_size){
    int total = 0 ;
    for(int i = 0 ; i < list_size ; i++){
        int temp = 0;
        temp = abs(vList[i] - head);
        total+=temp;
        head = vList[i];
    }
    return total;
}
int main()
{
    int list_size = 3 ;
    vector<int> vList = {100,50,190};

    //For testing
    //vector<int> vList = {176,79,34,60,92,11,41,114}; => size = 8, head = 140
    //vector<int> vList = {34,15,62,21,90}; => size = 5, head = 44

    sort(vList.begin(), vList.end(), less<int>());
    int head = 140;
    int diff1 = abs(head - vList[0]);
    sort(vList.begin(), vList.end(), greater<int>());
    int diff2 = abs(head - vList[0]);
    if(diff1 < diff2)
         sort(vList.begin(), vList.end(), less<int>());
    else if(diff1 > diff2)
        sort(vList.begin(), vList.end(), greater<int>());
    cout<<"Minimal Seek Time = "<<minSeekTime(vList,head,list_size)<<endl;

    return 0;
}
