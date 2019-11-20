#include "generator.h"
#include "profile.h"
//#include "hash_set/hash_set.cpp"
#include <set>
#include <unordered_set>


using namespace std;


struct PlateHasher {
    size_t operator() (const Plate& p) {
        size_t result = p.Number;
        result *= 100;
        result += p.Region;

        int s1 = p.C1 - 'A';
        int s2 = p.C2 - 'A';
        int s3 = p.C3 - 'A';
        int s = (s1 * 100 + s2) * 100 + s3;

        result *= 1'000'000;
        result += s;

        return result;
    }
};


int main() {
  //run();
  PlateGenerator pg;
  set<Plate> s_plates;
  unordered_set<Plate, PlateHasher> h_plates;
  const int N = 10;

  for (int i = 0; i < N; ++i) {
    s_plates.insert(pg.GetRandomPlate());
  }

  for (const auto& p : s_plates) {
    cout << p << endl;
  }
  cout << endl;

  for (int i = 0; i < N; ++i) {
    h_plates.insert(pg.GetRandomPlate());
  }

  for (const auto& p : h_plates) {
    cout << p << endl;
  }
  cout << endl;

  return 0;
}
