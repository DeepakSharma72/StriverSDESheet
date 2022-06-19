bool findPattern(string p, string s)
{
    s = p + "#" + s;
    int tarlen = p.size();
    vector<int> LPS(s.size(),0);
    for(int i=1;i<s.size();i++)
    {
        int j = LPS[i-1];
        while(s[j] != s[i])
        {
            if(j == 0)
            {
                j = -1;
                break;
            }
            j = LPS[j-1];
        }
        LPS[i] = j+1;
        if(LPS[i] == tarlen)
            return true;
    }
    return false;
}