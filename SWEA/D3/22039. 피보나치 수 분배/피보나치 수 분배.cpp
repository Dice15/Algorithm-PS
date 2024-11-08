#include<iostream>
using namespace std;

int main(int argc, char** argv){
	int test_case, T, n;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        cin>>n;    
        if(n%3==0 || (n-2)%3==0){
            if(!(n%3)){
                for(int i=n/3;i>0;i--) cout<<"BBA";
            }else{
                cout<<"BA";
                for(int i=(n-2)/3;i>0;i--) cout<<"BBA";
            }       
            cout<<'\n';
        }
        else{
            cout<<"impossible"<<'\n';
        }
	}
	return 0;
}