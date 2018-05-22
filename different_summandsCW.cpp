#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> allAs;

  while (n != 0) {
      if(allAs.empty()) { 
          if(n >= 1) { 
              allAs.push_back(1);
              n -= 1;
          } else {
            break;
          }
      }

      if( n > allAs.back() ) {
          // n is strictly larger than the last element
            int toPush = allAs.back() + 1;
                    n -= allAs.back() + 1;

            allAs.push_back(toPush);

      } else {
          //smaller
            allAs.back() = n + allAs.back();


            n = 0;
            break;
      }

  }

  return allAs;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
