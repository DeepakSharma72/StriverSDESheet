int maximumProduct(vector<int> &arr, int n)
{
    int ans = arr[0];
    int mx = 1, mn = 1;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
        {
            ans = max(ans,0);
            mn = mx = 1;
        }
        else if(arr[i] > 0)
        {
            mx = max(arr[i],mx*arr[i]);
            mn = min(arr[i],mn*arr[i]);
            ans = max(ans,mx);
        }
        else{
            int tmx = max(arr[i],mn*arr[i]);
            int tmn = min(arr[i],mx*arr[i]);
            mx = tmx;
            mn = tmn;
            ans = max(ans,mx);
        }
    }
    return ans;
}
