#include<queue>
class Kthlargest {
    priority_queue<int,vector<int>,greater<int>> main;
    priority_queue<int,vector<int>> extra;
public:
    Kthlargest(int k, vector<int> &arr) {
        for(int i=0;i<arr.size();i++)
         main.push(arr[i]);
    }

    void add(int num) {
        if(main.top() < num)
        {
            extra.push(main.top());
            main.pop();
            main.push(num);
        }
        else
        {
            extra.push(num);
        }
    }

    int getKthLargest() {
       return main.top();
    }

};