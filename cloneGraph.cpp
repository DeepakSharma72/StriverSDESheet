/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
#include<unordered_map>
#include<queue>
graphNode *cloneGraph(graphNode *node)
{
   unordered_map<graphNode*,graphNode*> list;
   list[node] = new graphNode(node->data,{});
   queue<graphNode*> q;
    q.push(node);
    while(!q.empty())
    {
        graphNode* main = q.front();
        q.pop();
        for(auto it:main->neighbours)
        {
            if(list.find(it) == list.end())
            {
                list[it] = new graphNode(it->data,{});
                q.push(it);
            }
            list[main]->neighbours.push_back(list[it]);
        }
    }
    return list[node];
}