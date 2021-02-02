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

    //sort(vList.begin(), vList.end(), greater<int>());

    int head = 140;

    cout<<"Minimal Seek Time = "<<minSeekTime(vList,head,list_size)<<endl;

    return 0;
}
