#include <bits/stdc++.h>
using namespace std;

string solution(string my_string) {
    return regex_replace(my_string, regex("[aeiou]"), "");
}