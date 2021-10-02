#include "pizza.h"
#include "menu.h"
#include "emp_hours.h"
#include "restaurant.h"
using namespace std;
//Constructor
Menu::Menu() {
   this-> num_pizzas = 0;
   this-> pizzas = NULL;
}
//Destructor
Menu::~Menu(){
   if(pizzas != NULL)
       delete [] pizzas;
   pizzas = NULL;
}
/*********************************************************************
** Function: Copy constructor
** Description: This is copy constructor creates copy of the Menu
** Parameters: Reference to the Menu
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
Menu::Menu(const Menu& copy){
   this->num_pizzas = copy.num_pizzas;
   if(this->num_pizzas > 0){
       this->pizzas = new Pizza[this->num_pizzas];
       for(int i =0;i < this->num_pizzas; i++){
           this->pizzas[i] = copy.pizzas[i];
       }
   }
   else
       this->pizzas = NULL;
}
/*********************************************************************
** Function:Menu operator 
** Description: This is Assign operator assigns Menu to the Menu copy
** Parameters: const Reference to the Menu
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
Menu& Menu::operator=(const Menu& copy){
   this->num_pizzas = copy.num_pizzas;
   if(this-> num_pizzas > 0){
       this->pizzas = new Pizza[this->num_pizzas];
       for(int i =0; i < this->num_pizzas; i++){
           this->pizzas[i] = copy.pizzas[i];
       }
   }
   else
       this->pizzas = NULL;
   return *this;
}
/*********************************************************************
** Function: populate_menu
** Description: This fucntion basically populates/read menu from txt file 
** Parameters: none
** Pre-Conditions: 
** Post-Conditions:
*********************************************************************/ 
void Menu::populate_menu()
{
    string tmp;
    int count=0;
    ifstream fin("menu.txt");
    while(getline(fin,tmp))
    {count++;}
    num_pizzas=count;
    fin.close();
    ifstream in("menu.txt");
    pizzas = new Pizza[num_pizzas];
    for (int i = 0; i < num_pizzas; i++)
    {
        pizzas[i].populate_pizza(in);
    }
    delete [] pizzas;
    in.close();
}
/*********************************************************************
** Function: show_menu
** Description: This function prints out menu to the terminal
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Menu::show_menu()
{
    cout << "--------------------------" <<endl;
    cout << "Num of pizzas: " << num_pizzas << endl;
    cout << "--------------------------" <<endl;
    for (int i = 0; i < num_pizzas; i++)
    {
       pizzas[i].print_pizza();
       cout << endl;
    }
    cout << "--------------------------" <<endl;  
}

/*********************************************************************
** Function: add item to menu 
** Description: This function adds item to the menu, by item I mean pizza 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Menu::add_item_to_menu()
{
string tmp;
int count=0;
ifstream fin("menu.txt");
while (getline(fin,tmp))
{
    count++;
}
num_pizzas=count;
cout<<num_pizzas<< endl;
fin.close();
populate_menu();
}
/*********************************************************************
** Function: remove_item_from menu
** Description: This function removes pizza from menu, based on user's choice
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Menu::remove_item_from_menu(){
   string input = "", temp = "";
   bool valid = false;
   int index = 0;
   cout<< "Please give me the name of the item that you would like to remove: " <<endl;
   getline(cin, input);

   while(true){
       for(int i =0; i < input.length(); i++){
           if(input[i] == ' ')
               input[i] = '_';
       }
       if(input == "Q" || input == "q")
           return;
       for(int i =0; i < this->num_pizzas; i++){ 

           temp = pizzas[i].get_name();
           if(temp == input){
               index = i;
               valid = true;
               break;
           }
       }
       if(valid == true)
           break;
       cout<<"\nThat pizza does not appear to be on the menu," 
       << " re-enter or type Q for quit " <<endl;
       getline(cin, input);
   }
   for(int i = index; i < this->num_pizzas; i++){
       if(i+1 == this-> num_pizzas){
           continue;
       }
       else
           pizzas[i] = pizzas[i+1];
   }
   
   this->num_pizzas--;
}
/*********************************************************************
** Function: search pizza by cost
** Description: This function used in Restaurant class as a sorter,
in order to find right pizzas depending on user's provied inputs
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
Menu Menu::search_pizza_by_cost(int upper_bound, string size){
   Menu searched;
   searched = *this;

   for(int i =0; i < searched.num_pizzas; i++){
       if(searched.get_cost(i, size) > upper_bound){
           searched.remove_item_at_index(i);
           i--;
       }
   }
   return searched;
}
void Menu::remove_item_at_index(int index){
   for(int i = index; i < this->num_pizzas; i++){
       if(i+1 == this-> num_pizzas){
           continue;
       }
       else
           pizzas[i] = pizzas[i+1];
   }
   this->num_pizzas--;
}
int Menu::get_cost(int index, string size) {
   if(size == "small")
       return pizzas[index].get_small_cost();
      
   else if(size == "medium")
       return pizzas[index].get_medium_cost();
  
   else
       return pizzas[index].get_large_cost();
      
}
/*********************************************************************
** Function:search pizza by ingredients to include 
** Description: This function basically finds pizzas based on user's input ingredients
** Parameters: reference to the results, ingredients, num of ingredients
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Menu::search_pizza_by_ingredients_to_include(Menu &results, string* ingredients, int num_ingredients){
   bool* present = new bool[num_ingredients];
   string *temp_ingredients;
  

   for(int i = 0; i < this->num_pizzas; i++){ //Pizzas
       for(int v =0; v < num_ingredients; v ++)
           present[v] = false;


       for(int j = 0; j < num_ingredients; j++){ //Ingredients want to include
           for(int k = 0; k < pizzas[i].get_num_ingredients(); k++){ //Ingredients of each pizzas
               temp_ingredients = pizzas[i].get_ingredients();
               if(ingredients[j] == temp_ingredients[k])
                   present[j] = true;

               delete [] temp_ingredients;
           }
       }


       if(check_all_true( present, num_ingredients)){
           results.pizzas[results.num_pizzas] = this->pizzas[i];
           results.num_pizzas++;
       }

   }

   delete [] present;
}
/*********************************************************************
** Function:check all true
** Description: This function used to check if all member of the array are true
** Parameters: bool array intger num
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
bool Menu::check_all_true( bool* arr, int num){
    for(int i =0; i < num; i++)
        if(arr[i] == false)
            return false;
    return true;
}
/*********************************************************************
** Function: search pizza by ingredients to exclude 
** Description: this function excludes pizza based provided ingredients
** Parameters: results, ingredients, num of ingredients 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Menu::search_pizza_by_ingredients_to_exclude(Menu &results, string* ingredients, int num_ingredients){
  
   bool present = false;
   string *temp_ingredients;

   for(int i = 0; i < this->num_pizzas; i++){ //Pizzas
       for(int j = 0; j < num_ingredients; j++){ // Ingredients want to exclude
           present = false;
           for(int k = 0; k < pizzas[i].get_num_ingredients(); k++){ //Ingredients of pizza
               temp_ingredients = pizzas[i].get_ingredients();
               if(ingredients[j] == temp_ingredients[k]){
                   present = true;
                   break;
               }

               delete [] temp_ingredients;
           }
       }
      

       if(present != true){
           results.pizzas[results.num_pizzas] = this->pizzas[i];
           results.num_pizzas++;
       }
   }
}
/*********************************************************************
** Function:create_array 
** Description: This function bassically creates array of pizzas with 
the size int lenght
** Parameters: size int length
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Menu::create_array(int length){
   pizzas = new Pizza[length];
}

