#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    answer.push_back(arr[0]);
    for(int i = 1, size = arr.size(); i < size; ++i)
    {
        if (arr[i] != arr[i - 1])
            answer.push_back(arr[i]);
    }    
    return answer;
}