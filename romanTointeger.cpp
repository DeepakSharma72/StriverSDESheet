int value(char ch)
{
        if(ch == 'I')
            return 1;
        else if(ch == 'V')
            return 5;
        else if(ch == 'X')
            return 10;
        else if(ch == 'L')
            return 50;
        else if(ch == 'C')
            return 100;
        else if(ch == 'D')
            return 500;
        return 1000;
}
int romanToInt(string s) {
    int ans = 0;
    for(int i=0;i<s.size();i++)
    {
        if(i < s.size()-1 && value(s[i]) < value(s[i+1]))
            ans -= value(s[i]);
        else
            ans += value(s[i]);
    }
    return ans;
}
