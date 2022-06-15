bool isValidParenthesis(string expression)
{
    stack<char> s;
    for(auto it:expression)
    {
        if(it == ']')
        {
            if(s.empty() || s.top() != '[')
                return false;
            s.pop();
        }
        else if(it == '}')
        {
            if(s.empty() || s.top() != '{')
                return false;
            s.pop();
        }
        else if(it == ')')
        {
            if(s.empty() || s.top() != '(')
                return false;
            s.pop();
        }
        else
        {
            s.push(it);
        }
    }
    return (s.size() == 0);
}