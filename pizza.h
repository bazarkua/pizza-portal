#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

class Pizza {
  private:
    string name;
    int small_cost;
    int medium_cost;
    int large_cost;
    int num_ingredients;
    string* ingredients;
  public:
  Pizza();
  Pizza(const Pizza& copy_pizza);
  Pizza & operator=(const Pizza &);
  ~Pizza();
  //Accessors
  string get_name() const;
  int get_small_cost() const;
  int get_medium_cost() const;
  int get_large_cost() const;
  int get_num_ingredients();
  string* get_ingredients() const;
  //Setters
  void set_name(const string name);
  void set_small_cost(const int small_cost);
  void set_medium_cost(const int medium_cost);
  void set_large_cost(const int large_cost);
  void set_num_ingredients(int num_ingredients);
  void set_ingredients(const string* ingredients);

  void populate_ingredients(fstream&);
  void populate_menu();
  void populate_pizza(ifstream&);
  void print_pizza();
  void create_ingredients_arr(int num_ingredients);
  void fill_ingredients_arr(int num, string temp[]);
};

#endif