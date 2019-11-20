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

ostream& operator<< (ostream& out, const Plate& p) {
    out << p.C1;
    out << setw(3) << setfill('0') << p.Number;
    out << p.C2;
    out << p.C3;
    out << setw(2) << setfill('0') << p.Region;
    return out;
}

bool operator < (const Plate& l, const Plate& r) {
    return tie(l.C1, l.Number, l.C2, l.C3, l.Region)
    < tie(r.C1, r.Number, r.C2, r.C3, r.Region);
}

bool operator == (const Plate& l, const Plate& r) {
    return (l.C1 == r.C1)
        && (l.Number == r.Number)
        && (l.C2 == r.C2)
        && (l.C3 == r.C3)
        && (l.Region == r.Region);
}
