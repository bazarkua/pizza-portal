#ifndef EMP_HOURS_H
#define EMP_HOURS_H

#include <string>
using namespace std;

struct employee {
  int id;
  string password;
  string first_name;
  string last_name;
};

struct hours {
  string day;
  string open_hour;
  string close_hour;
};

#endif