#include "test_runner.h"

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

struct Record {
  string id;
  string title;
  string user;
  int timestamp;
  int karma;
};

// Реализуйте этот класс
class Database {
public:
  bool Put(const Record &record) {
    if (data.count(record.id) > 0) {
      return false;
    } else {
      data[record.id] = record;
      auto uiter = users.insert(pair<string, Record>(record.user, record));
      auto titer = timestamps.insert(pair<int, Record>(record.timestamp, record));
      auto kiter = karmas.insert(pair<int, Record>(record.karma, record));
      users_iterators.insert(pair<string, multimap<string, Record>::iterator>(record.id, uiter));
      timestamps_iterators.insert(pair<string, multimap<int, Record>::iterator>(record.id, titer));
      karmas_iterators.insert(pair<string, multimap<int, Record>::iterator>(record.id, kiter));
    }
    return true;
  }
  const Record *GetById(const string &id) const {
    if (data.count(id) > 0) {
      return &data.at(id);
    } else {
      return nullptr;
    }
  }

  bool Erase(const string &id) {
    if (data.count(id) > 0) {
      data.erase(id);
    } else {
      return false;
    }
  }

  template <typename Callback>
  void RangeByTimestamp(int low, int high, Callback callback) const {
    auto it = find(timestamps.begin(), timestamps.end(), low);
    for (; it->first <= high; ++it) {
      if (!callback(*GetById(it->second.id))) {
        break;
      }
    }
  }

  template <typename Callback>
  void RangeByKarma(int low, int high, Callback callback) const {
    auto it = find(karmas.begin(), karmas.end(), low);
    for (; it->first <= high; ++it) {
      if (!callback(*GetById(it->second.id))) {
        break;
      }
    }
  }

  template <typename Callback>
  void AllByUser(const string &user, Callback callback) const {
    for (const auto &i : users) {
      if (i.first == user) {
        if (!callback(*GetById(i.second.id))) {
          break;
        }
      }
    }
  }

private:
  unordered_map<string, Record> data;
  multimap<string, Record> users;
  multimap<int, Record> timestamps;
  multimap<int, Record> karmas;
  unordered_map<string, multimap<string, Record>::iterator> users_iterators;
  unordered_map<string, multimap<int, Record>::iterator> timestamps_iterators;
  unordered_map<string, multimap<int, Record>::iterator> karmas_iterators;
};

void TestRangeBoundaries() {
  const int good_karma = 1000;
  const int bad_karma = -10;

  Database db;
  db.Put({"id1", "Hello there", "master", 1536107260, good_karma});
  db.Put({"id2", "O>>-<", "general2", 1536107260, bad_karma});

  int count = 0;
  db.RangeByKarma(bad_karma, good_karma, [&count](const Record &) {
    ++count;
    return true;
  });

  ASSERT_EQUAL(2, count);
}

void TestSameUser() {
  Database db;
  db.Put({"id1", "Don't sell", "master", 1536107260, 1000});
  db.Put({"id2", "Rethink life", "master", 1536107260, 2000});

  int count = 0;
  db.AllByUser("master", [&count](const Record &) {
    ++count;
    return true;
  });

  ASSERT_EQUAL(2, count);
}

void TestReplacement() {
  const string final_body = "Feeling sad";

  Database db;
  db.Put({"id", "Have a hand", "not-master", 1536107260, 10});
  db.Erase("id");
  db.Put({"id", final_body, "not-master", 1536107260, -10});

  auto record = db.GetById("id");
  ASSERT(record != nullptr);
  ASSERT_EQUAL(final_body, record->title);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestRangeBoundaries);
  RUN_TEST(tr, TestSameUser);
  RUN_TEST(tr, TestReplacement);
  return 0;
}
