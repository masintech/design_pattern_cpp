#pragma once
#include <boost/lexical_cast.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class SingletonDatabase {
  SingletonDatabase() {
    std::cout << "Initializing database" << std::endl;

    std::ifstream ifs("../capitals.txt");

    std::string s, s2;
    while (getline(ifs, s)) {
      std::cout<<"s"<<s<<std::endl;
      getline(ifs, s2);
      std::cout<<"s2"<<s2<<std::endl;
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
  int get_population(const std::string& name) { return capitals[name]; }
};
int main(int, char**) {
    std::string city = "Tokyo";
    int population = SingletonDatabase::get().get_population(city);
    std::cout<<"Population in Tokyo City is "<< SingletonDatabase::get().get_population(city)<<std::endl;
}
