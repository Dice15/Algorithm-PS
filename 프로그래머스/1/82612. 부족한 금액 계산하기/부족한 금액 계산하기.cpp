using namespace std;
typedef long long ll;

ll solution(int price, int money, int count)
{
    ll result=money;
    for(ll i=1;i<=count;i++){
        result-=price*i;
    }
    return result<0 ? -result : 0;
}