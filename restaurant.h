#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <fstream>
#include <cstdlib>
#include "menu.h"
#include "emp_hours.h"

using namespace std;

class Restaurant {
  private:
    Menu menu;
    employee* employees;
    int num_employees;
    hours* week;
    int num_week_days;
    string name;
    string phone;
    string address;

  public:
    
    Restaurant();
    Restaurant( Restaurant&);
    Restaurant& operator=(const Restaurant&);
    //destructors where appropriate
    ~Restaurant();
    
    //Accessors
    string get_name();
    string get_phone();
    string get_address();
    int get_num_week_days();
    hours* get_hours();
    int get_num_employees();
    employee* get_employees();
    Menu get_menu();
    
    //Mutators
    void set_name(string name);
    void set_phone(string phone);
    void set_address(string address);
    void set_num_week_days(int num_week_days);
    void set_hours(hours* week);
    void set_num_employees(int num_employees);
    void set_employees(employee* employees);
    void set_menu(Menu menu);
    
    void load_data(); //reads from files to correctly populate menu, employees, hours, etc.
    bool login();
   
    void view_menu();
    void view_hours();
    void view_address();
    void view_phone();
    void search_menu_by_price();
    void search_by_ingredients();
    void change_hours();
    void add_to_menu();
    void remove_from_menu();
    void view_orders();
    void remove_orders();

    void populate_restaurant_info();
    void populate_employee_info();
    void start_menu();
    void print_customer_choice();
    void print_employee_choice();
    bool check_if_int(string num);
    int get_int(string input);
    void employee_choice();
    void customer_choice();
    void print_employees();
    int check_week_day(string week_day);
    void search_by_cost();
    void write_in();
    
    // Only one of the following two prototypes should be used:
    // selection is a dynamically allocated array of Pizza objects that are being ordered
    // selection_size indicates the number of Pizza objects in the array
    // num_ordered is a dynamically allocated array that indicates how many pizzas of each type were ordered
    //void place_order(Pizza* selection, int selection_size, int* num_ordered);
    // you may also choose to use this prototype:
    void place_order();
    
    
};

#endif