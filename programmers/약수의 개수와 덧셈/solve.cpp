#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int cnt = 0;
    int tmp;
    
    for (;left <= right; ++left)
    {
        cnt = 0;
        for (int i = 1; i <= left; ++i)
        {
            if (!(left % i))
                ++cnt;
        }
        if (cnt % 2)
            answer-= left;
        else
            answer+= left;
    }
    return answer;
}