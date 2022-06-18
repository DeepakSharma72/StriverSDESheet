string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    int mnlen = 10000;
    for(auto it:arr)
    {
        int val = it.size();
        mnlen = min(val,mnlen);
    }
    for(int i=0;i<mnlen;i++)
    {
        char ch = arr[0][i];
        for(int j=1;j<n;j++)
        {
            if(arr[j][i] != ch)
            {
                ch = '^';
                break;
            }
        }
        if(ch == '^')
            break;
        ans.push_back(ch);
    }
    return ans;
}


