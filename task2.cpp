//0-1 Knapsack Problem
// Name: Tawfik Yasser Tawfik
// ID: 20180075
// Group: IS-3
#include <bits/stdc++.h>
#include<string.h>

using namespace std;

int maximumProfit(map<int,int, greater<int>>m, int voucher,vector<string> &sd,string devs[]);

int main()
{
    cout<<"Welcome to 0-1 knapsack [Voucher] application\n"<<endl;

    int profit, price, numberOfDevices, voucher; // Initialization of value and weight and number of devices will stored and the voucher of the knapsack
    string deviceName;

    map<int, int, greater<int>> m; // Initialization of a map of two element (int,int) sorted in descending order

    cout<<"Please enter the number of devices: ";
    cin>>numberOfDevices; // Takes the number of devices

    string names[numberOfDevices];
    vector<string> selectedDevices;

    cout<<"Please enter the voucher value: ";
    cin>>voucher; // Takes the voucher

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

        names[i] = deviceName;
        m.insert(pair<int,int>(profit,price)); // Add the device (profit,price) to the map
        cout<<"------------------------------------------------"<<endl;
    }

    cout<<"\n\n";

    int maxProfit = maximumProfit(m,voucher,selectedDevices,names) ; // Calling the function maximumProfit to calculate the maximum profit with minimum price

    cout<<">> The maximum profit =  "<< maxProfit<<"\n"; // Print the maximum profit

    cout<<"The following devices are devices can select to get maximum profit ["<<maxProfit<<"] and does not exceed the price ["<<voucher<<"]"<<endl;
    for(int i = 0 ;i<selectedDevices.size();i++) // Print the devices with maximum profit
    {
        cout<<selectedDevices[i]<<endl;
    }

    return 0;
}

int maximumProfit(map<int,int, greater<int>> m, int voucher, vector<string> &sd,string devs[])
{
    map<int, int>::iterator itr; // Iterator to traverse the map

    int total = 0; // Total variable to store the final max total value and return it.
    int temp = 0;  // Temp to store the value of the first device
    int var = 0;   // Used to store the weight for each device
    itr = m.begin();
    total = itr->first;
    temp = itr->second;
    sd.push_back(devs[0]);
    cout<<sd[0]<<endl;
    m.erase(total);

    for(itr = m.begin(); itr != m.end();itr++){
        var+=itr->second;
        if( (var + temp) <= voucher){
            total += itr->first;
            sd.push_back(devs[distance(m.begin(),itr)+1]);
        }
        else
            var = 0;
    }
    //return the total value
    return total;
}
