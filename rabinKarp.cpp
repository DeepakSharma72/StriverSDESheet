bool isvalid(int i,int j,int k,string &str,string &pat)
{
    while(j < k)
    {
        if(str[i] != pat[j])
            return false;
        i++,j++;
    }
    return true;
}

vector<int> stringMatch(string &str, string &pat) {
    vector<int> ans;
    int hashval = 0;
    int chash = 0;
    for(int i=0;i<pat.size();i++)
    {
        hashval += (pat[i] - '0');
        chash += (str[i] - '0');
    }
    
    if(hashval == chash)
    {
        if(isvalid(0,0,pat.size(),str,pat))
            ans.push_back(0);
    }
    for(int i=pat.size();i<str.size();i++)
    {
        chash += (str[i] - '0');
        chash -= (str[i - pat.size()] - '0');

        if(hashval == chash)
        {
           if(isvalid(i-pat.size()+1,0,pat.size(),str,pat))
            ans.push_back(i-pat.size()+1);
        }  
    }
    return ans;
}
