#include<vector>
#include<algorithm>
int minCharsforPalindrome(string str) {
    int len = str.size();
    string rev = str;
    reverse(rev.begin(),rev.end());
    str = str + "#" + rev;
    vector<int> LPS(str.size(),0);
    for(int i=1;i<str.size();i++)
    {
        int j = LPS[i-1];
        while(str[j] != str[i])
        {
            if(j == 0)
            {
                j = -1;
                break;
            }
            j = LPS[j-1];
        }
        LPS[i] = j + 1;
    }
    int val = LPS.back();
    return (len - val);
}
