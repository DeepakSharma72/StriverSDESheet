bool areAnagram(string &str1, string &str2){
    int count[26] = {0};
    for(auto it:str1)
    {
        count[it-'a']++;
    }
    for(auto it:str2)
    {
        count[it-'a']--;
    }
    for(int i=0;i<26;i++)
    {
        if(count[i])
            return false;
    }
    return true;
}