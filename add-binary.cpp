#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

string addBinary(string a, string b) {
  int diff = a.length() - b.length();
  diff = abs(diff);
  if(a.size() > b.size()) {
    b = string(diff, '0') + b;
  } else if(a.size() < b.size()) {
    a = string(diff, '0') + a;
  }
  char tmp = '0';
  vector<char> v;
  char res = ' ';
  int len = b.length() - 1;
  for(int i = len; i >= 0; i--) {
    char cur_tmp = '0';
    if(a[i] == b[i]) {
      if(a[i] == '1') {
        cur_tmp = '1';
      }
      res = '0';
    } else {
      res = '1';
    }

    if(tmp == res) {
      if(tmp == '1') {
        cur_tmp = '1';
      }
      res = '0';
    } else {
      res = '1';
    }
    tmp = cur_tmp;
    v.push_back(res);
  }
  if(tmp == '1') v.push_back(tmp);
  return string(v.rbegin(), v.rend());
}

int main() {
  string a = "1010";
  string b = "1011";
  cout << addBinary(a, b);
  return 0;
}