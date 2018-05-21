#include "List.h"
#include <string>
using std::string;
#include <iostream>
using std::endl;
using std::cout;
#include <fstream>
using std::ifstream;
using std::ofstream;

List::List()
{

}

bool List::remove_item(const int & item){
    if (item > 0 && item <= v_list.size()){
        v_list.erase(v_list.begin()+(item-1));
        return true;
    } else if (item == 1 && v_list.size()==1){
        v_list.clear();
        return true;
    } else {
        return false;
    }
}

bool List::load_list(const string & file){
    string list_item = "";
    ifstream load_file;
    load_file.open(file);

    if (!load_file){
        return false;
    }

    clear();
    while (getline(load_file, list_item)){
        v_list.push_back(list_item);
    }

    return true;
}

bool List::save_list(const string & file){
    ofstream save_file;
    save_file.open(file);

    if (!save_file){
        return false;
    }

    int num_items = v_list.size();

    for (int i=0; i<num_items; i++){
        save_file << v_list[i] << endl;
    }
    return true;
}
