#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    vector<bool> check(10, false);
    for(auto &e : numbers) check[e]=true;
    
    int answer=0;
    for(int i=1;i<10;i++) answer+=check[i] ? 0 : i;
    return answer;
}