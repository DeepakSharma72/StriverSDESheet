void sortStack(stack<int> &s)
{
    if(s.empty())
        return;
    int upper = s.top();
    s.pop();
    sortStack(s);
    stack<int> output;
    while(!s.empty() && s.top() > upper)
    {
        output.push(s.top());
        s.pop();
    }
    s.push(upper);
    while(!output.empty())
    {
        s.push(output.top());
        output.pop();
    }   
}