int search(int* arr, int n, int key) {
    int lo = 0, hg = n-1;
    while(lo <= hg)
    {
        int mid = (lo + hg)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] >= arr[lo])
        {
            if(arr[lo] <= key && key < arr[mid])
                hg = mid-1;
            else
                lo = mid+1;
        }
        else
        {
            if(arr[mid] < key && key <= arr[hg])
                lo = mid+1;
            else
                hg = mid-1;
        }
    }
    return -1;
}