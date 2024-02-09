#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    for(;n;n>>=1) ans+=n%2; 
    return ans;
}