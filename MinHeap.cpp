

int extractHeap(vector<int> &heap,int &cap)
{
    int res = heap[0];
    heap[0] = heap[cap--];
    heap.pop_back();
    int i = 0;
    while(i < cap)
    {
        int child = (2*i+1 <= cap)?(2*i+1):-1;
        child = (2*i+2 <= cap && heap[child] > heap[2*i+2])?(2*i + 2):child;
        if(child == -1 || heap[child] >= heap[i])
            break;
        int temp = heap[child];
        heap[child] = heap[i];
        heap[i] = temp;
        i = child;
    }
    return res;
}

void pushHeap(vector<int> &heap,int cap,int node)
{
    heap.push_back(node);
    int i = cap;
    while(i > 0)
    {
        int parent = (i-1)/2;
        if(heap[parent] <= heap[i])
        {
            break;
        }
        else
        {
            int temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            i = parent;
        }
    }
}


vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> Heap;
    int ind = -1;
    vector<int> ans;
    for(auto Q:q)
    {
        if(Q[0] == 1)
        {
            int val = extractHeap(Heap,ind);
            ans.push_back(val);
        }
        else
        {
            ind++;
            pushHeap(Heap,ind,Q[1]);
        }
    }
    return ans;
}
