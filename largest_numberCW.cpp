#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>     /* atoi */

using namespace std;

bool isGreaterOrEqual(int digit, int maxDigit) {
  if (maxDigit < 0) return true;
  stringstream st;
  stringstream st1;

  st << to_string(digit) << to_string(maxDigit);
  st1 << to_string(maxDigit) << to_string(digit);

  string r1;
  string r2;
  st >> r1;
  st1 >> r2;

  if(stoi(r1) >= stoi(r2)) {
    return true;
  } else {
    return false;
  }
}


string largest_number(vector<string> a) {
  std::stringstream ret;

  while(!a.empty()) {
    int maxDigit = -999999999;

    vector<string>::iterator toRemove;

    for (auto it = a.begin(); it != a.end(); it++) {
        int digit = stoi(*it);
      // if (digit >= maxDigit) {
         if(isGreaterOrEqual(digit, maxDigit)) {
            maxDigit = digit;
            toRemove = it;
        }
    }
    ret << to_string(maxDigit);
    a.erase(toRemove);
  }

  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
