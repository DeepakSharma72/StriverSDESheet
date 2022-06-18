int atoi(string str) {
    int ans = 0;
    for(auto it:str)
    {
        if('0' <= it && '9' >= it)
        ans = ans*10 + (it - '0');
    }
    if(str.size() > 0 && str[0] == '-')
        ans = -ans;
    return ans;
}