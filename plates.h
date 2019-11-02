#include <iomanip>
#include <iostream>
#include <tuple>

using namespace std;

struct Plate {
  char C1;
  int Number;
  char C2;
  char C3;
  int Region;
};

ostream& operator<<(ostream& out, const Plate& p) {

}