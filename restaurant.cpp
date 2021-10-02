#include "emp_hours.h"
#include "restaurant.h"
#include "menu.h"
#include <iostream>
using namespace std;
//Default constructor
Restaurant::Restaurant() {
    cout << "Restaurant constructor called" << endl;
    Menu menu;
    employees = NULL;
    num_week_days = 0;
    week = NULL;
    name = "default";
    phone = "default";
    address = "default";
}
//getters
string Restaurant::get_name()
{
    return this->name;
}
string Restaurant::get_phone()
{
    return this->phone;
}
string Restaurant::get_address()
{
    return this->address;
}
int Restaurant::get_num_week_days()
{
    return this->num_week_days;
}
hours* Restaurant::get_hours()
{
    return this->week;
}
Menu Restaurant::get_menu()
{
    return this->menu;
}
int Restaurant::get_num_employees()
{
    return this->num_employees;
}
employee* Restaurant::get_employees()
{
    return this->employees;
}
//setters
void Restaurant::set_name(string new_name) 
{this->name = new_name;}

void Restaurant::set_phone(string new_phone) 
{this->phone = new_phone;}

void Restaurant::set_address(string new_address) 
{this->address = new_address;}

void Restaurant::set_num_week_days(int new_week_days) 
{this->num_week_days = new_week_days;}

void Restaurant::set_hours(hours* week)
{
    for (int i = 0; i < num_week_days; i++)
    {
        this->week[i].day=week[i].day;
        this->week[i].open_hour=week[i].open_hour;
        this->week[i].close_hour=week[i].close_hour;
    }
}
void Restaurant::set_num_employees(int new_num_employees)
{this->num_employees=new_num_employees;}

void Restaurant::set_employees(employee* employees)
{
    for (int i = 0; i < num_employees; i++)
    {
        this->employees[i].id=employees[i].id;
        this->employees[i].password=employees[i].password;
        this->employees[i].first_name=employees[i].first_name;
        this->employees[i].last_name=employees[i].last_name;
    }
    
}
//this function made for skipping lines for reading from restaurant 
//info
void skip_lines(fstream& fin, string tmp)
{
    getline(fin, tmp);
    getline(fin, tmp);
    getline(fin, tmp);
}
/*********************************************************************
** Function:get_num_lines_orders
** Description:This function made for getting lines from the file being read
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
int get_num_lines_orders(fstream& fin) {

    int count = 0;
    string tmp;
   
   while (!fin.eof()) {
        getline(fin, tmp);
        count++;
    }
    fin.clear();
    fin.seekg(0, ios::beg); //Go to begining of file again
    return count;
}
/*********************************************************************
** Function:get_num_lines_restaurant
** Description:This function made for getting lines from the file being read
** Parameters: fstream& fin
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int get_num_lines_restaurant(fstream& fin) {

    int count = 0;
    string tmp;
    skip_lines(fin, tmp);
   
   while (!fin.eof()) {
        getline(fin, tmp);
        count++;
    }
    fin.clear();
    fin.seekg(0, ios::beg); //Go to begining of file again
    return count;
}
/*********************************************************************
** Function:get_num_lines_employee
** Description:This function made for getting lines from the file being read
** Parameters: fstream& fin
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int get_num_lines_employee(fstream& fin) {

    int count = 0;
    string tmp;
   
   while (!fin.eof()) {
        getline(fin, tmp);
        count++;
    }
    fin.clear();
    fin.seekg(0, ios::beg); //Go to begining of file again
    return count;
}
/*********************************************************************
** Function: populate_restaurant_info
** Description: This function basically populates/reads from restaurant_info.txt file
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Restaurant::populate_restaurant_info()
{
string tmp;
fstream fin;
fin.open("restaurant_info.txt");

num_week_days=get_num_lines_restaurant(fin);
cout << "Number of week days: " << num_week_days << endl;
set_num_week_days(num_week_days);

getline(fin, tmp);
set_name(tmp);

getline(fin, tmp);
set_phone(tmp);

getline(fin, tmp);
set_address(tmp);

this->week  = new hours [this->num_week_days];

for (int i = 0; i < num_week_days; i++)
    {
    fin>>week[i].day>>week[i].open_hour>>week[i].close_hour;
    }
fin.close();
}
/*********************************************************************
** Function: populate_employee_info
** Description: populates/reads from file employee.txt
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Restaurant::populate_employee_info()
{
string tmp;
fstream fin;
fin.open("employee.txt");

num_employees=get_num_lines_employee(fin);
cout<<"Number of employees: "<<num_employees << endl;
set_num_employees(num_employees);
this->employees=new employee[this->num_employees];
for (int i = 0; i < num_employees; i++)
{
    fin>>employees[i].id>>employees[i].password>>employees[i].first_name>>employees[i].last_name;
}
fin.close();
}
void Restaurant::view_menu()
{
    menu.show_menu();
}
/*********************************************************************
** Function: view_orders
** Description: This function allows to view orders by reading orders
from the file and printing them to the terminal
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::view_orders()
{
    string tmp;
    cout << "List of all orders: " << endl;
    fstream order;
    order.open("orders.txt");
    int num_orders = get_num_lines_orders(order);
    for (int i = 0; i < num_orders; i++)
    {
        getline(order, tmp);
        cout << tmp << endl;
    }
    order.close();
}
void Restaurant::place_order()
{

}
void Restaurant::remove_from_menu()
{
    menu.remove_item_from_menu();
}
/*********************************************************************
** Function:remove orders
** Description: This function removes orders, based on the number of order,
provied by the user
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::remove_orders()
{
    fstream fin;
    fin.open("orders.txt");
    int line;
    cout << "Num of order you want to remove"<<endl;
    cin>>line;
    string tmp;
    int num_lines = get_num_lines_orders(fin);
    fin.close();
    ifstream fin1;
    fin1.open("orders.txt");
    string* str = new string[num_lines];
    for(int i = 0; i < num_lines; i++)
    {
        getline(fin1,tmp);
        str[i]=tmp;
    }
    for(int i = 0; i < num_lines; i++)
    {
        cout << str[i] << endl;
    }
    fin1.close();
    ofstream ofs;
    ofs.open("orders.txt");
    for(int i = 0; i < num_lines; i++)
    {
        if(i==line-1)
        {
            continue;
        }
        else {
            ofs << str[i] << endl;
        }
    }
    ofs.close();
    delete [] str;
}
/*********************************************************************
** Function:load data
** Description: this function used to call all other populate data functions
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::load_data()
{
populate_restaurant_info();
populate_employee_info();
menu.populate_menu();
}
/*********************************************************************
** Function: print employees 
** Description: This function prints employees, I used it to check if 
employees populated correctly
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::print_employees()
{
for (int i = 0; i < num_employees; i++) {
        cout << employees[i].id << ' ' 
        << employees[i].password << ' ' 
        << employees[i].first_name << ' '
        << employees[i].last_name << endl;
    }
}
void Restaurant::view_address()
{
    cout << get_address() << endl;
}
void Restaurant::view_phone()
{
    cout << get_phone() << endl;
}
void Restaurant::view_hours()
{
    cout << "--------------------------" <<endl;
    cout << "Here is our working hours:" <<endl;
    for (int i = 0; i < num_week_days; i++) {
        cout << week[i].day << ' ' 
        << week[i].open_hour << ' ' 
        << week[i].close_hour << endl;
    }
    cout << "--------------------------" <<endl;
}
/*********************************************************************
** Function: start_menu
** Description: This is my start menu function, I call it in main
to start my program and promt user for inputs as well as call for other
functions
** Parameters:none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Restaurant::start_menu()
{
    string input = "";
    cout<<"Are you a customer (C), an employee (E), or logout (Q)\n";
    getline(cin, input);
    if(input == "C")
    {
        customer_choice();
    }      
    else if(input == "E")
    {
        int id;
        string password;
        if (login()==true){
            employee_choice();
        }
    }
    else
    return;
}
/*********************************************************************
** Function:login
** Description:This is login validation checker, it checks if user's
password and id input are valid compare to password and id in employee.txt
** Parameters:none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
bool Restaurant::login()
{
    int id;
    string password;
    bool valid = false;
    int attempt = 3;
    while(true){  
    
    cout<<"employee ID and Password: \n";
    cin>>id>>password;
    cin.clear();
    cin.ignore(256,'\n');  
        
        for(int i =0; i < num_employees; i++)
        {
            if(employees[i].id==id && employees[i].password==password)
            {
            cout << "\n\n\nEmployee login succeed!" <<endl;
            cout << "Employee name: " << employees[i].first_name <<' '<<
            employees[i].last_name<< "\nEmployee ID: " << employees[i].id <<endl;
            return true;
            break;
            }
        }
    attempt --;
    cout << "Invalid Password or ID, Attempts left: " << attempt << endl;
    
    if (attempt == 0)
    {
        cout << "Too many attempts, access denied" << endl;
        return false;
    }
      id = 0;
      password = "";
}
}
/*********************************************************************
** Function: add_to_menu
** Description: This function asks user for the parameters of the order
such as name price for small and other and then adds the completed order to the text file 
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::add_to_menu()
{
    cout<< "Add a new item to menu" << endl;
    cout<< "Please include following parameters for new item in a menu: "<<endl;
    cout<<"<name> <price for small> <price for medium> <price for large> <number of ingredients> <ingredients>"
    << endl;
    cout<<" : ";
    string item;
    getline(cin,item);
    cout<<item<<endl;
    string file_name="menu.txt";
    ofstream add;
    add.open(file_name.c_str(),ios::app);
    add<<endl<<item;
    add.close();
    menu.add_item_to_menu();
}
/*********************************************************************
** Function:employee_choice
** Description:This is employee choice function promts user for options, only
after user succesfully logged in as a employee
** Parameters:none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Restaurant::employee_choice() 
{
    bool logout = false;
    string input = "";
    int input_int = -1;
    do {
        print_employee_choice();
        getline(cin, input);
        if (!check_if_int(input)) {
            cout << "--------------------------" <<endl;
            cout<<"INVALID INPUT! TRY AGAIN\n";
            cout << "--------------------------" <<endl;
            continue;
        }
        input_int = get_int(input);

        switch (input_int) {
        case 1: change_hours(); break;
        case 2: cout << "--------------------------" <<endl;
        view_orders(); 
        cout << "--------------------------" <<endl; break;
        case 3: remove_orders(); break;
        case 4: add_to_menu(); break;
        case 5: remove_from_menu(); break;
        case 6: view_menu(); break;
        case 7: view_hours(); break;
        case 8: cout << "--------------------------" <<endl;
        cout<<"ADDRESS: \n"; view_address(); 
        cout << "--------------------------" <<endl;break;
        case 9: cout << "--------------------------" <<endl;
        cout<<"PHONE:\n"; view_phone(); 
        cout << "--------------------------" <<endl;break;
        case 10: return; break;
        default: cout << "default" << endl; break;

        }

    } while (!logout);
}
/*********************************************************************
** Function:customer_choice
** Description:This function promts user for customer options, if user
choose to be a customer
** Parameters:none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Restaurant::customer_choice() {
    bool logout = false;
    string input = "";
    int input_int = -1;

    do {
        print_customer_choice();
        getline(cin, input);
        if (!check_if_int(input)) {
            cout << "--------------------------" <<endl;
            cout<<"INVALID INPUT! TRY AGAIN\n";
            cout << "--------------------------" <<endl;
            continue;
        }
        input_int = get_int(input);

        switch (input_int) {
        case 1: view_menu(); break;
        case 2: search_by_cost(); break;
        case 3: search_by_ingredients(); break;
        case 4: place_order(); break;
        case 5: view_hours(); break;
        case 6: cout << "--------------------------" <<endl;
         cout<<"ADDRESS: \n"; view_address(); 
         cout << "--------------------------" <<endl;break;
        case 7: cout << "--------------------------" <<endl;
        cout<<"PHONE:\n"; view_phone(); 
        cout << "--------------------------" <<endl;break;
        case 8: return; break;
        default: cout << "Invalid input" << endl; break;

        }

    } while (!logout);
}
bool Restaurant::check_if_int(string num) {
    for (int a = 0; a < num.length(); a++) {
        if (num[a] >= 48 && num[a] <= 57)
            ;
        else
            return false;
    }
    return true;
}
int Restaurant::get_int(string input) {
    int get_int = 0;
    for (int i = 0; i < input.length(); i++) {
        get_int *= 10;
        get_int += (int(input[i]) - 48);
    }
    return get_int;
}
/*********************************************************************
** Function:print customer choice
** Description: This function basically do the same thing as the function
print employee choice, but this time prints choice for customer
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::print_customer_choice() {
     
  cout<<"What would you like to do?\n";
  cout<<"1. View menu\n";
  cout<<"2. Search by Cost\n";
  cout<<"3. Search by Ingredients\n";
  cout<<"4. Place Order\n";
  cout<<"5. View Hours\n";
  cout<<"6. View Address\n";
  cout<<"7. View Phone\n";
  cout<<"8. Log out\n";
}
/*********************************************************************
** Function:print_employee_choice
** Description: This function prints employee choice with 10 possible 
options 
** Parameters:none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::print_employee_choice() {
    cout<<"Welcome back employee!\n";
    cout<<"1. Change hours \n";
    cout<<"2. View Orders\n";
    cout<<"3. Remove Order \n";
    cout<<"4. Add Item to Menu\n";
    cout<<"5. Remove Item from Menu\n";
    cout<<"6. View Menu\n";
    cout<<"7. View Hours\n";
    cout<<"8. View Address\n";
    cout<<"9. View phone\n";
    cout<<"10. Logout\n";
}
/*********************************************************************
** Function: check_week_day 
** Description: This function check if week day is a really week day string,
for example the program promts user for Sunday, Monday and other
if user writes numbers or other symbols the function prints that it isn't
valid integer
** Parameters: string week day
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
int Restaurant::check_week_day(string week_day){
    while(true){
        for(int i = 0; i < this->num_week_days; i++){
            if(this->week[i].day == week_day)
                return i;
        }
        cout << "That is not a valid day of the week! Please re-enter it! " << endl;
        cin >> week_day;
        cin.clear();
        cin.ignore(256,'\n');

    }
}
/*********************************************************************
** Function:change_hours 
** Description:This is important function that promts employee for 
choice, where employee can change working hours in any day of the week
** Parameters:none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Restaurant::change_hours(){
    string input = "";
    int day_index = 0;
    this->view_hours();
    cout << "What day would you like to change? "<< endl;
    getline(cin, input);
    day_index = check_week_day(input);
    cout<<"What opening time would you like? "<<endl;
    getline(cin, input);
    week[day_index].open_hour = input;
    cout<<"What closing time would you like? "<<endl;
    getline(cin, input);
    week[day_index].close_hour = input;
    cout << "Updated working hours:" << endl;
    write_in();
    view_hours();
}
void Restaurant::write_in()
{
    ofstream ofs;
    ofs.open("restaurant_info.txt");
    ofs<<get_name()<<endl;
    ofs<<get_address()<<endl;
    ofs<<get_phone()<<endl;
    for (int i = 0; i < num_week_days; i++)
    {
        ofs<<week[i].day<< ' ' << week[i].open_hour<<' '<< week[i].close_hour<<endl;
    }
    ofs.close();  
}

/*********************************************************************
** Function:search by cost fucntion
** Description: this function sorts pizzas by cost, depending from their size
** Parameters: Input, size
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::search_by_cost(){
    string input ="", size = "";
    int price = 0;
    while(true){
        printf("What size are you looking for? (small, medium, large) \n");
        getline(cin, size);
        if(size == "small" || size == "medium" || size == "large")
            break;

        printf("Invalid input, lower case only\n");
    }
    while(true){
        printf("What is the max price you're looking for? \n");
        getline(cin, input);
        if(check_if_int(input)){
            price = get_int(input);
            break;
        }
    }
    
    Menu results;
    results = menu.search_pizza_by_cost(price, size);
    results.show_menu();
}
/*********************************************************************
** Function:Search ingredients
** Description: This function sorts pizzas and find propiate pizzas
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::search_by_ingredients(){
    Menu results;
    results.create_array(100);

    string input = "";
    int num_ingredients_to_ei = 1;
    string * sort_ingredients;
    bool continue_searching = true;
  
        printf("Would you like to include (I), exclude (E), exit (Q) ");
        getline(cin, input);

        if(input == "e" || input == "E"){
        
            sort_ingredients = new string[num_ingredients_to_ei];
            for(int i = 0; i < num_ingredients_to_ei; i++){
                printf("Ingredient: ");
                getline(cin, sort_ingredients[i]);
                for(int j = 0; j < sort_ingredients[i].length(); j++)
                {
                    if(sort_ingredients[i][j]== ' ')
                        sort_ingredients[i][j] = '_';
                }
            };

            menu.search_pizza_by_ingredients_to_exclude(results, sort_ingredients, num_ingredients_to_ei);
            results.show_menu();
            delete [] sort_ingredients;
        }


        else if(input == "i" || input == "I"){
            
            sort_ingredients = new string[num_ingredients_to_ei];

            for(int i = 0; i < num_ingredients_to_ei; i++){
                printf("Ingredient: ");
                getline(cin, sort_ingredients[i]);
                for(int j = 0; j < sort_ingredients[i].length(); j++)
                    if(sort_ingredients[i][j]== ' ')
                        sort_ingredients[i][j] = '_';
            };

            menu.search_pizza_by_ingredients_to_include(results, sort_ingredients, num_ingredients_to_ei);
            results.show_menu();
            delete [] sort_ingredients;
      
        } 
        else {

        }

    // printf("Would you like to order off the results? Y/N ");
    // getline(cin, input);
    // if(input == "y" || input == "Y")
    //     this->place_order();
}
//Destructor
Restaurant::~Restaurant(){
    if(employees != NULL)
        delete [] this->employees;
    if(week != NULL)
        delete [] this->week;
  
    employees = NULL;
    week = NULL;
}


