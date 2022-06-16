#include<unordered_map>
struct Node{
  int key,val,NF;
  Node* next,*prev;
  Node(int k,int v,int f)
  {
      key = k,val = v,NF = f;
      next = prev = NULL;
  }
};

struct DList{
    int size;
    Node* head,*tail;
    DList()
    {
        size = 0;
        head = new Node(-1,-1,0);
        tail = new Node(-1,-1,0);
        head->next = tail;
        tail->prev = head;
    }
    Node* AddNode(int key,int value,int cfreq)
    {
        size++;
        Node* ptr = new Node(key,value,cfreq);
        Node* A = head;
        Node* B = head->next;
        A->next = ptr;
        ptr->prev = A;
        ptr->next = B;
        B->prev = ptr;
        return ptr;
    }
    void DeleteNode(Node* &ptr)
    {
        size--;
        Node* A = ptr->prev;
        Node* B = ptr->next;
        A->next = B;
        B->prev = A;
        ptr = NULL;
    }
    bool isEmpty()
    {
        return (size == 0);
    }
};

class LFUCache {
    unordered_map<int,Node*> NodeMap;
    unordered_map<int,DList*> FrequencyMap;
    int size,minFrequency;
    int cap;
public:
    LFUCache(int capacity) {
        size = 0;
        cap = capacity;
        minFrequency = 1;
    }
    
    void DeletNodeinList(Node* &ptr)
    {
        size--;
        int CF = ptr->NF;
        FrequencyMap[CF]->DeleteNode(ptr);
        if(CF == minFrequency && FrequencyMap[CF]->isEmpty())
        {
            minFrequency++;
        }
    }
    
    void AddNodeinList(int key,int value,int CF)
    {
        minFrequency = min(minFrequency,CF);
        size++;
        if(FrequencyMap.find(CF) == FrequencyMap.end())
        {
            FrequencyMap[CF] = new DList();
        }
        Node* ptr = FrequencyMap[CF]->AddNode(key,value,CF);
        NodeMap[key] = ptr;
    }
    
    int get(int key) {
       if(cap && NodeMap.find(key) != NodeMap.end())
       {
           Node* ptr = NodeMap[key];
           int CF = ptr->NF;
           int value = ptr->val;
           NodeMap.erase(key);
           DeletNodeinList(ptr);
           AddNodeinList(key,value,CF+1);    
           return value;
       }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap == 0)
        {
            return;
        }
        if(NodeMap.find(key) != NodeMap.end())
        {
            Node* ptr = NodeMap[key];
            int CF = ptr->NF;
            NodeMap.erase(key);
            DeletNodeinList(ptr);
            AddNodeinList(key,value,CF+1);
        }
        else
        {
            if(size < cap)
            {
                AddNodeinList(key,value,1);
            }
            else
            {
                Node* ptr = FrequencyMap[minFrequency]->tail->prev;
                int k = ptr->key;
                NodeMap.erase(k);
                DeletNodeinList(ptr);
                AddNodeinList(key,value,1);
            }
        }
    }
};

