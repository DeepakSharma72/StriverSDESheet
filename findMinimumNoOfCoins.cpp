int findMinimumCoins(int amount) 
{
   int ans = 0;
   vector<int> money = {1000,500,100,50,20,10,5,2,1};
    for(int i=0;i<money.size();i++)
    {
        int notes = amount/money[i];
        ans += notes;
        amount = amount - notes*money[i];
    }
    return ans;
}
