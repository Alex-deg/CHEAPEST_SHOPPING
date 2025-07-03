#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

int main() {
    
    char buffer[128];
    std::string result = "";
    std::string command = "/usr/bin/python3 printhello.py";
   
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) throw std::runtime_error("Ошибка вызова Python!");
 
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
 
    pclose(pipe);

    std::cout << result << std::endl;

    return 0;
}