#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> cash(5001);
  int nominal;
  while (cin >> nominal) {
    cash[nominal]++;
  }

  for (int i = 0; i < cash.size(); ++i) {
    if (cash[i] != 0) {
      cout << i << " - " << cash[i] << endl;
    }
  }
  return 0;
}