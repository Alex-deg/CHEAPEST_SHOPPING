// main.cpp
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <nlohmann/json.hpp>  // Для работы с JSON

using json = nlohmann::json;

std::string exec_python(const std::string& product) {
    char buffer[128];
    std::string result = "";
    std::string command = "python parser.py " + product;
    
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) throw std::runtime_error("Ошибка вызова Python!");
    
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    
    pclose(pipe);
    return result;
}

int main() {
    std::string product;
    std::cout << "Введите продукт: ";
    std::cin >> product;
    
    std::string json_data = exec_python(product);
    auto products = json::parse(json_data);
    
    std::cout << "Найдено " << products.size() << " товаров:\n";
    for (const auto& p : products) {
        std::cout << p["name"] << " | " << p["price"] << " ₽ | " << p["weight"] << "\n";
    }
    
    return 0;
}