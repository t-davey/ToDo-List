#ifndef LIST_H
#define LIST_H

#include <vector>
#include <string>
#include <iostream>

class List
{
public:
    List();

    bool load_list(const std::string & file);
    bool save_list(const std::string & file);
    void add_item(const std::string & new_item) { v_list.push_back(new_item); }
    bool remove_item(const int & item);
    void display();
    void clear() { v_list.clear(); }

private:
    std::vector<std::string> v_list;
    std::string file_name_;

};

inline void List::display(){
    int num_items = v_list.size();

    for (int i=0; i<num_items; i++){
        std::cout << i+1 << ": " << v_list[i] << std::endl;
    }
}

#endif // LIST_H
