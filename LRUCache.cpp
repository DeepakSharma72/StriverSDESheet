#include<unordered_map>
struct Node{
  int key,val;
  Node* prev,*next;
  Node(int k,int v)
  {
      key = k,val = v;
      prev = NULL,next = NULL;
  }
};

class LRUCache
{
    int size;
    Node* head,*tail;
    unordered_map<int,Node*> mp;
public:
    LRUCache(int capacity)
    {
        size = capacity;
        head = new Node(-1,-1);
        tail = new Node(-2,-2);
        head->next = tail;
        tail->prev = head;
    }
    
    void InsertNode(int key,int value)
    {
        Node* ptr = new Node(key,value);
        Node* A = head,*B = head->next;
        A->next = ptr;
        ptr->next = B;
        B->prev = ptr;
        ptr->prev = A;
        mp[ptr->key] = ptr;
    }
    
    void DeleteNode(Node* &ptr)
    {
        Node* A = ptr->prev,*B = ptr->next;
        A->next = B;
        B->prev = A;
        ptr = NULL;
    }
    
    int get(int key)
    {
        if(mp.find(key) == mp.end())
            return -1;
        Node* ptr = mp[key];
        int res = ptr->val;
        DeleteNode(ptr);
        InsertNode(key,res);
        return res;
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end())
        {
            Node* ptr = mp[key];
            mp.erase(key);
            DeleteNode(ptr);
            InsertNode(key,value);
        }
        else if(size > 0)
        {
            InsertNode(key,value);
            size--;
        }
        else
        {
            Node* ptr = tail->prev;
            mp.erase(ptr->key);
            DeleteNode(ptr);
            InsertNode(key,value);
        }
    }
};
