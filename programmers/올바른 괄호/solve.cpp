#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool answer = true;
    stack<char> tmp;
    
    for(int i = 0, size = s.size(); i < size; ++i)
    {
        if (s[i] == ')')
        {
            if(tmp.empty())
                return false;
            tmp.pop();
        } else if (s[i] == '(')
            tmp.push('(');
    }
    if (!tmp.empty())
        return false;
    return answer;
}