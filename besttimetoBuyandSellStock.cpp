#include <bits/stdc++.h> 
using namespace std;

int maximumProfit(vector<int> &prices){
    int profit = 0;
    int buy = prices[0];
    int n = prices.size();
    for(int i=1;i<n;i++)
    {
        if(buy <= prices[i])
        {
            profit = max(profit,-buy+prices[i]);
        }
        else
        {
            buy = prices[i];
        }
    }
    return profit;
}