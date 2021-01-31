//0-1 Knapsack Problem
// Name: Tawfik Yasser Tawfik
// ID: 20180075
// Group: IS-3
#include <bits/stdc++.h>
#include<string.h>

using namespace std;

int maximumProfit(map<int,int, greater<int>>m,map<int,string, greater<int>> n, int voucher,vector<string> &sd);

int main()
{
    cout<<"Welcome to 0-1 knapsack [Voucher] application\n"<<endl;

    int profit, price, numberOfDevices, voucher; // Initialization of value and weight and number of devices will stored and the voucher of the knapsack
    string deviceName;

    map<int, int, greater<int>> m; // Initialization of a map of two element (int,int) sorted in descending order
    map<int, string, greater<int>> n;
    cout<<"Please enter the number of devices: ";
    cin>>numberOfDevices; // Takes the number of devices
    vector<string> selectedDevices;
    cout<<"Please enter the voucher value: ";
    cin>>voucher; // Takes the voucher

    cout<<"\n\n";

    //The following for loop to take the value and the weight for each device in the kanpsack
    for(int i = 0 ; i <numberOfDevices ; i++)
    {
        cout<<"Enter the name for device #"<<(i+1)<<" : ";
        cin.ignore();
        getline(cin,deviceName);
        cout<<"Enter the profit for device #"<<(i+1)<<" : ";
        cin>>profit;
        cout<<"Enter the price for device #"<<(i+1)<<" : ";
        cin>>price;

        n.insert(pair<int,string>(profit,deviceName));
        m.insert(pair<int,int>(profit,price)); // Add the device (profit,price) to the map
        cout<<"------------------------------------------------"<<endl;
    }
    cout<<"\n\n";

    int maxProfit = maximumProfit(m,n,voucher,selectedDevices,names) ; // Calling the function maximumProfit to calculate the maximum profit with minimum price

    cout<<">> The maximum profit =  "<< maxProfit<<"\n"; // Print the maximum profit

    cout<<"The following devices are devices can select to get maximum profit ["<<maxProfit<<"] and does not exceed the price ["<<voucher<<"]"<<endl;
    for(int i = 0 ; i < selectedDevices.size() ;i++) // Print the devices with maximum profit
    {
        cout<<"Device : "<<selectedDevices[i]<<endl;
    }

    return 0;
}

int maximumProfit(map<int,int, greater<int>> m, map<int,string, greater<int>> n, int voucher, vector<string> &sd)
{
    map<int, int>::iterator itr; // Iterator to traverse the map
    map<int, string>::iterator itrs;
    int total = 0; // Total variable to store the final max total value and return it.
    int temp = 0;  // Temp to store the value of the first device
    int var = 0;   // Used to store the weight for each device
    itr = m.begin();
    itrs = n.begin();
    total = itr->first;
    temp = itr->second;
    sd.push_back(itrs->second);
    m.erase(total);

    for(itr = m.begin(); itr != m.end();itr++){
        var += itr->second;
        if( (var + temp) <= voucher){
            total += itr->first;
            for(itrs = n.begin() ; itrs != n.end(); itrs++){
                if(itrs->first == itr->first){
                    sd.push_back(itrs->second);
                }
            }
        }else{
            var = abs(var-itr->second);
        }
    }
    //return the total value
    return total;
}
