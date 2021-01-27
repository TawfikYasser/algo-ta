#include <bits/stdc++.h>

using namespace std;

int maxTotalValue(map<int,int, greater<int>>m, int capacity);

int main()
{
    cout<<"Welcome to knapsack application\n"<<endl;

    int value, weight, numberOfItems, capacity; // Initialization of value and weight and number of items will stored and the capacity of the knapsack

    map<int, int, greater<int>> m; // Initialization of a map of two element (int,int) sorted in decreasing order

    cout<<"Please enter the number of items: ";
    cin>>numberOfItems; // Takes the number of elements

    cout<<"Please enter the capacity of the knapsack: ";
    cin>>capacity; // Takes the capacity of the kanpsack

    //The following for loop to take the value and the weight for each item in the kanpsack
    for(int i = 0 ; i <numberOfItems ; i++)
    {
        cout<<"Enter the value for item #"<<(i+1)<<" : ";
        cin>>value;
        cout<<"Enter the weight for item #"<<(i+1)<<" : ";
        cin>>weight;
        m.insert(pair<int,int>(value/weight,weight)); // Add the item (value,weight) to the map sorted by average value for each item
        cout<<"------------------------------------------------"<<endl;
    }

    cout<<"\n\n";

    cout<<">> The maximum total value in the knapsack =  "<<maxTotalValue(m,capacity)<<"\n"; // Calling the function maxTotalValue to calculate the max total value

    return 0;
}

int maxTotalValue(map<int,int, greater<int>> m, int capacity)
{
    map<int, int>::iterator itr; // Iterator to traverse the map

    int total = 0; // Total variable to store the final max total value and return it

    for( itr = m.begin(); itr != m.end(); ++itr )
    {
        int temp = itr->second; // Temp variable and store the weight of each item

        if( temp < capacity )
        {
            // If the weight still less than the capacity, so increase the total value by the weight * value,
            // then decrease the total capacity by the temp
            total += temp*(itr->first);
            capacity -= temp;

        }else{
            //If the weight not less than the capacity, so increase the total by the capacity * value,
            // then make the capacity zero which is now **full** and break
            total+=capacity*(itr->first);
            capacity=0;
            break;

        }
    }
    //return the total value
    return total;
}
