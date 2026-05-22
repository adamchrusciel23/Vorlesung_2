#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    /*std::vector<int> data = {42, 17, 42, 5, 99, 17, 63, 12};
    for (int current_data : data) {
        std::cout << current_data << " ";
    }
    std::sort(data.begin(), data.end());
    std::cout << "\n" << std::endl;
    for (int current_data : data) {
        std::cout << current_data << " ";
    }
    std::cout << "\n" << std::endl;
    for (int current_data : data) {
        if(current_data == 63) {
            std::cout << current_data << std::endl;
        }
    }*/

    std::vector<int> data2 = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    /*int count = 0;
    for(int &current_data : data2) {
        std::cout << "\n";
        for(int print_data : data2) {
            std::cout << print_data << " ";
        }
        if(current_data == -1) {
            current_data = 0;
        }
        if(current_data == 8) {
            count++;
        }
    }
    std::reverse(data2.begin(), data2.end());
    std::cout << "\n";
    for(int current_data : data2) {
        std::cout << current_data << " ";
    }
    std::cout << "\n" << count << std::endl;*/
    std::cout << "\n";
    for (auto it = data2.begin(); it != data2.end(); ++it ) {
        std::cout << *it << " ";
    }
}