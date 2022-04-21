#include <gtest/gtest.h>

#include <boost/lexical_cast.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class DataBase {
 public:
  virtual int get_population(const std::string  &name) = 0;
};

class SingletonDatabase : public DataBase {
  SingletonDatabase() {
    std::cout << "Initializing database" << std::endl;

    std::ifstream ifs("./capitals.txt");
    std::string s, s2;
    while (getline(ifs, s)) {
      getline(ifs, s2);
      int pop = boost::lexical_cast<int>(s2);
      capitals[s] = pop;
    }
  }

  std::map<std::string, int> capitals;

 public:
  // Supress copy contructor
  SingletonDatabase(SingletonDatabase const&) = delete;
  void operator=(SingletonDatabase const&) = delete;

  static SingletonDatabase& get() {
    static SingletonDatabase db;
    return db;
  }
  int get_population(const std::string& name) override { return capitals[name]; }
};

class DummyDatabase : public DataBase {
  std::map<std::string, int> capitals;

 public:
  DummyDatabase() {
    capitals["alpha"] = 1;
    capitals["beta"] = 2;
    capitals["gamma"] = 3;
  }
  int get_population(const std::string& name) override {
    return capitals[name];
  }
};

struct SingletonRecordFinder {
  int total_population(std::vector<std::string> names) {
    int result{0};
    for (auto& name : names)
      result += SingletonDatabase::get().get_population(name);
    return result;
  }
};

struct ConfigurableRecordFinder
{
    DataBase& db;
    ConfigurableRecordFinder(DataBase &db): db(db) {}
    
    int total_population(std::vector<std::string> names)
    {
        int result{0}; // new method for cpp initialization
        for (auto & name : names)
            result += db.get_population(name);
        return result;
    }
};

// Integration test
TEST(RecordFinderTests, SingletonTotalPopulationTest) {
  SingletonRecordFinder rf;
  std::vector<std::string> names{"Seoul", "Mexico City"};
  int tp = rf.total_population(names);
  EXPECT_EQ(3000 + 3000, tp);
}

// Independent test
TEST(RecordFinderTest, DependentTotalPopulationTest) {
    DummyDatabase db;
    ConfigurableRecordFinder rf {db};
    EXPECT_EQ(4, rf.total_population(std::vector<std::string>{"alpha", "gamma"}));
}

int main(int ac, char** av) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
