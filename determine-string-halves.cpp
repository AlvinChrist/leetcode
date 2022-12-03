#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

bool halvesAreAlike(string &s) {
    unordered_map<char, bool> isVowel = {
        {'a', true},
        {'e', true},
        {'i', true},
        {'o', true},
        {'u', true},
        {'A', true},
        {'E', true},
        {'I', true},
        {'O', true},
        {'U', true},
    };
    int vow[1001];
    vow[0] = isVowel[s[0]] ? 1 : 0;
    int len = s.size();
    for(int i = 1; i < len; i++) {
        vow[i] = vow[i-1];
        if(isVowel[s[i]]) {
            vow[i]++;
        }
    }
    int mid = len / 2;
    // for(int i = 0; i < s.size(); i++) {
    //     cout << vow[i] << ' ';
    // }
    return vow[mid - 1] == vow[len - 1] - vow[mid - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    cout << halvesAreAlike(s);
    return 0;
}