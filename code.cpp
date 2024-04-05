#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Recipe {
    vector<string> recipe;
    int m = 0;
};

Recipe add_line_in_vector(const string& line) {
    Recipe recipe;
    stringstream get(line);
    string temp;
    while (getline(get, temp, ',')) {
        if (temp != "directions") {
            recipe.m++; // Stop parsing ingredients when "directions" is encountered
        }
        recipe.recipe.push_back(temp);
    }
    return recipe;
}

void searchRecipe(const string& file_name, const string& recipe_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cout<<"ERROR: File is not open!"<<endl;
        return;
    }
    string line;
    Recipe recipe;
    int flag=0;
    while (getline(file, line)) {
        recipe = add_line_in_vector(line);
        if (recipe_name == recipe.recipe[0]) { 
            cout << "Recipe Name: " << recipe.recipe[0] << endl;         
                        cout << "Category: " << recipe.recipe[1] << endl;  
                        cout << "Ingredients:" << endl;
                        for (int i = 2; i < recipe.m-6; ++i) {
                            cout << i - 1 << ") " << recipe.recipe[i] << endl;
                        }
                        cout << "Directions:" << endl;
                        for (int i = recipe.m-4; i < recipe.recipe.size(); ++i) {  
                            {
                               cout << "- " << recipe.recipe[i] << endl; 
                            }
            }
        }
    }
    if (flag==1) {
        cout << "Recipe not found." << endl;
    }
    file.close();
}

int main() {
    string file_name = "Book1.csv";
    string recipe_name;
    string ingredient_name;

    cout << "Enter recipe name to search: ";
    getline(cin, recipe_name);

    searchRecipe(file_name, recipe_name);
    return 0;
}



