//#include <algorithm>
//#include <iostream>
//#include <iterator>
//#include <set>
//#include <vector>
//using namespace std;
//
//template <typename Iterator>
//class IteratorRange {
//public:
//    IteratorRange(Iterator begin, Iterator end)
//            : first(begin)
//            , last(end)
//    {
//    }
//
//    Iterator begin() const {
//        return first;
//    }
//
//    Iterator end() const {
//        return last;
//    }
//
//private:
//    Iterator first, last;
//};
//
//template <typename Collection>
//auto Head(Collection& v, size_t top) {
//    return IteratorRange{v.begin(), next(v.begin(), min(top, v.size()))};
//}
//
//
//
//int main() {
//    const set<int> numbers = {6, 4, 7, 1, 2, 5};
//    // Этот цикл выводит "1 2 4"
//    for (int x : Head(numbers, 3)) {
//        cout << x << ' ';
//    }
//    cout << '\n';
//
//    const vector<int> numbers_v = {6, 4, 7, 1, 2, 5};
//    // Этот цикл выводит "6 4 7"
//    for (int x : Head(numbers_v, 3)) {
//        cout << x << ' ';
//    }
//}