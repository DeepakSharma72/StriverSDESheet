#include<vector>

int getPalinLen(string &str,int start,int end)
{
    while(start >= 0 && end < str.size() && str[start] == str[end])
    {
        start--,end++;
    }
    return (end-start-1);
}

string longestPalinSubstring(string str)
{
    int start = 0;
    int maxLen = 0;
    for(int i=0;i<str.size();i++)
    {
        int odd = getPalinLen(str,i,i);
        int even = getPalinLen(str,i,i+1);
        int len = max(odd,even);
        if(maxLen < len)
        {
            maxLen = len;
            start = i - (len-1)/2;
        }
    }
    return str.substr(start,maxLen);
}