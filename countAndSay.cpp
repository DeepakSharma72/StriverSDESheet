string getnew(string s)
{
    int i = 0;
    string ans = "";
    while(i<s.size())
    {
        int j = i+1;
        while(j < s.size() && s[j] == s[i])
        {
            j++;
        }
        ans.push_back(j-i+'0');
        ans.push_back(s[i]);
        i = j;
    }
    return ans;
}
string writeAsYouSpeak(int n) 
{
	string s = "1";
    for(int i=1;i<n;i++)
    {
       s = getnew(s);
    }
    return s;
}