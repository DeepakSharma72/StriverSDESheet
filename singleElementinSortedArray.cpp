int uniqueElement(vector<int> arr, int n)
{
    if(n == 1) 
        return arr[0];
	int lo = 0, hg = n-1;
    while(lo <= hg)
    {
        int mid = (lo + hg)/2;
        if(mid == 0 && arr[mid] != arr[mid+1])
            return arr[mid];
        else if(mid == n-1 && arr[mid] != arr[mid-1])
            return arr[mid];
        else if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1])
            return arr[mid];
        if(mid%2 == 0)
        {
            if(arr[mid] == arr[mid-1])
                hg = mid-1;
            else
                lo = mid+1;
        }
        else
        {
            if(arr[mid] == arr[mid-1])
                lo = mid+1;
            else
                hg = mid-1;
        }
    }
    return -1;
}
