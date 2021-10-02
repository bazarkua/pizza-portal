#include "pizza.h"
//Constructor
Pizza::Pizza() {
   name = "N/A";
   small_cost = 0;
   medium_cost = 0;
   large_cost = 0;
   num_ingredients = 0;
   ingredients = NULL;
}
//Copy constructor
Pizza::Pizza(const Pizza& copy_pizza) {
   this->name = copy_pizza.name;
   this->small_cost = copy_pizza.small_cost;
   this->medium_cost = copy_pizza.medium_cost;
   this->large_cost = copy_pizza.large_cost;
   this->num_ingredients = copy_pizza.num_ingredients;
   if (num_ingredients == 0)
       ingredients = NULL;
   else {
       for (int i = 0; i <this-> num_ingredients; i++) {
           this->ingredients[i] = copy_pizza.ingredients[i];
       }
   }
};
//getters
string Pizza::get_name()const
{return this->name;}
int Pizza::get_small_cost()const
{return this->small_cost;}
int Pizza::get_medium_cost()const
{return this->medium_cost;}
int Pizza::get_large_cost()const
{return this->large_cost;}
int Pizza::get_num_ingredients()
{return this->num_ingredients;}
string * Pizza::get_ingredients() const{
  
   string* temp = new string[num_ingredients];
   for(int i =0; i < num_ingredients; i++){
       temp[i] = ingredients[i];
   }
   return temp;
}
//setters
void Pizza::set_name(const string name)
  {this->name=name;}
  void Pizza::set_small_cost(const int small_cost)
  { this->small_cost = small_cost;}
  void Pizza::set_medium_cost(const int medium_cost)
  {this->medium_cost=medium_cost;}
  void Pizza::set_large_cost(const int large_cost)
  {this->large_cost=large_cost;}
  void Pizza::set_num_ingredients(int num_ingredients)
  {this->num_ingredients=num_ingredients;}

void Pizza::set_ingredients(const string* ingredients)
{
    for (int i = 0; i < num_ingredients; i++)
    {
        this->ingredients[i] = ingredients[i];
    }
}
/*********************************************************************
** Function: create_ingredients_arr
** Description: This function creates array of ingredeints 
** Parameters: Number of ingredients
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Pizza::create_ingredients_arr(int num_ingredients) 
{
   ingredients = new string [num_ingredients];
}
/*********************************************************************
** Function:populate_pizza
** Description:This function basically populates/reads from menu.txt file
** Parameters: ifstream& fin
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Pizza::populate_pizza(ifstream& fin)
{
fin>>name>>small_cost>>
medium_cost>>large_cost>>num_ingredients;
ingredients = new string[num_ingredients];
for(int i = 0; i < num_ingredients; i++)
{
fin>>ingredients[i];
}
}
/*********************************************************************
** Function:prin_pizza
** Description:This function simply prints out the pizzas information to 
the terminal
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Pizza::print_pizza()
{
    cout << this->name << " ";
    cout << this->small_cost << " ";
    cout << this->medium_cost << " ";
    cout << this->large_cost << " ";
    cout << this->num_ingredients << " ";
    
    for (int i = 0; i < num_ingredients; i++)
    {
        cout << this->ingredients[i] << " ";
    } 
}   
/*********************************************************************
** Function: Assign operator Pizza operator
** Description: This is Assign operator assigns pizza to the copy pizza
** Parameters: const Pizza class reference
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
Pizza & Pizza::operator=(const Pizza& copy_pizza) {
   this->name = copy_pizza.name;
   this->small_cost = copy_pizza.small_cost;
   this->medium_cost = copy_pizza.medium_cost;
   this->large_cost = copy_pizza.large_cost;
   this->num_ingredients = copy_pizza.num_ingredients;
   if (ingredients != NULL)
       delete [] ingredients;
  
   this->ingredients = new string [this->num_ingredients];
   if (num_ingredients == 0)
       ingredients = NULL;
   else {
       for (int i = 0; i < num_ingredients; i++) {
           this->ingredients[i] = copy_pizza.ingredients[i];
       }
   }
    
   return *this;
}

//Destructor destroyer
Pizza::~Pizza(){
   if (this->ingredients != NULL)
       delete[] this->ingredients;
       ingredients=NULL;
}