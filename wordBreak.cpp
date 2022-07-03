#include<set>
bool wordBreak(vector < string > & arr, int n, string & target) {
    set<string> list;
    for(auto it:arr)
    {
        list.insert(it);
    }
    vector<int> DP(target.length()+1,false);
    DP[0] = true;
    for(int i=0;i<target.size();i++)
    {
        string temp = "";
        for(int j=i;j>=0 && (i-j+1) <= 10;j--)
        {
            temp = target[j] + temp;
            if(list.find(temp) != list.end() && DP[j] == true)
            {
                DP[i+1] = true;
            }
        }
    }
    return DP[target.length()];
}