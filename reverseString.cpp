string reverseString(string str)
{
    string ans = "";
    int n = str.size();
    int j = n - 1;
    while(j >= 0 && str[j] == ' ')
        j--;
    
    while(j >= 0)
    {
        while(j >= 0 && str[j] == ' ')
            j--;
        
        while(j >= 0 && str[j] != ' ')
            j--;
        
        int i = j + 1;
        while(i<n && str[i] != ' ')
        {
            ans.push_back(str[i]);
            i++;
        }
        ans.push_back(' ');
    }
    return ans;
    
}