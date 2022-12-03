#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
typedef unordered_map<char,int> umpci;

umpci mp;

static bool cmp(const pair<char, int> &a, const pair<char, int> &b) {
    return a.second > b.second;
}

string frequencySort(string s) {
    for(char ch: s) { // tree -> ch = 't', 'r', 'e', 'e'
        !mp[ch] ? mp[ch] = 0 : mp[ch]++; // mp['t'] = 0; mp['t'] = 1, mp['e'] = 2
    }
    
    vector<pair<char,int>> v;
    for(auto it: mp) {
        v.push_back(make_pair(it.first, it.second));
    }

    sort(v.begin(), v.end(), cmp);

    string res= "";
    for(pair<char,int> p: v) {
        for(int i = 0; i < p.second; i++) {
            res += p.first;
        }
    }
    return res;
}

int main() {
    string s; cin >> s;
    cout << frequencySort(s);
    return 0;
}