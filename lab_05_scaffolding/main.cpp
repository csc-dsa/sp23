#include "linked_list.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]){

    LinkedList* ll;
    std::string file_name(argv[1]);

	std::vector<int> file_data;
    std::string line;

	std::ifstream file(file_name);

    // Read the first line from the file & store into vector
    std::getline(file, line);

    std::stringstream ss(line);

    int temp_int;
    while(ss >> temp_int){
        file_data.push_back(temp_int);
    }
//    std::cout<< "WOO" << std::endl;
    // Create a linked_list based on what was in the first line of the file
    if(file_data.size() == 0){
        ll = new LinkedList();
    }else if (file_data.size() == 1){
        ll = new LinkedList(file_data[0]);
    }else{
        ll = new LinkedList(file_data);
    }

    std::cout << ll->to_string() << std::endl;

    // Read the rest of the file
    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string temp;
        std::vector<std::string> line_vals;

        // Get all entries on this line
        while(ss >> temp){
            line_vals.push_back(temp);
        }

        // How is this line handled?
        // 2 entries - insert call
        if(line_vals.size() == 2){
            int val = std::stoi(line_vals[0]);
            int idx = std::stoi(line_vals[1]);
            ll->insert(val, idx);
        }else {
            // 1 entry, is there a ? at the end?
            if (line_vals[0][line_vals[0].size() - 1] == '?') {
                // Extract substring of this element without the trailing '?', convert to int, check if exists
                int temp = std::stoi(line_vals[0].substr(0, line_vals[0].size() - 1));
                std::cout << ll->contains(temp) << std::endl;
                continue;
            } else {
                int temp = std::stoi(line_vals[0]);
                if (temp >= 0) {
                    if (temp % 2 == 1) {
                        ll->push_front(temp);
                    } else {
                        ll->push_back(temp);
                    }
                } else {
                    ll->remove(std::abs(temp));
                }
            }
        }
        std::cout << ll->to_string() << std::endl;
    }
}