#include "Viewer.h"
#include "List.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <cstdlib>

void Viewer::run(){
    bool done = false;
    bool invalid = false;
    const string long_separator(79, '-');
    const string default_list = "list.txt";

    todo.load_list("list.txt");
    cout << "Loaded default list: " << default_list << endl;

    while(!done){
        cout << long_separator << endl;
        if (!invalid){
            display();
        }
        invalid = false;
        string command = "";
        string new_item = "";
        cout << long_separator << endl;
        cout << "-Add Item   -Remove Item   -Save List   -Load List   -Clear List   -Quit" << endl;
        cout << "Command: ";
        cin >> command;
        switch (command[0]){
            case 'a':{
                cout << "Enter item: ";
                cin.sync();
                getline(cin, new_item);
                todo.add_item(new_item);
                system("cls");
                break;
            }
            case 'r':{
                int choice;
                cout << "Enter item number: ";
                cin >> choice;
                cin.clear();
                system("cls");
                if (!todo.remove_item(choice)){
                    cout << "Unable to remove item " << choice << '.' << endl;
                    }
                break;
            }
            case 's':{
                string save_file_name = "";
                cout << "Save as: ";
                cin >> save_file_name;
                system("cls");
                if (!todo.save_list(save_file_name)){
                    cout << "Unable to save list to " << save_file_name << '.' << endl;
                    break;
                } else {
                    cout << "List saved to " << save_file_name << '.' << endl;
                    break;
                }
            }
            case 'l':{
                string load_file_name = "";
                cout << "Enter file name: ";
                cin >> load_file_name;
                system("cls");
                if (!todo.load_list(load_file_name)){
                    cout << "Unable to load list from " << load_file_name << '.' << endl;
                }
                break;
            }
            case 'c':{
                cout << "Clear list? (y/n)" << endl;
                cin >> command;
                if (command[0] == 'y'){
                    todo.clear();
                }
                cin.sync();
                system("cls");
                break;
            }
            case 'q':{
                cout << "Goodbye!" << endl;
                done = true;
                break;
            }
            default :{
                invalid = true;
                cout << "Invalid command." << endl;
                cout << "Command: ";

                break;
            }

        }
    }
}

void Viewer::display(){
    todo.display();
}
