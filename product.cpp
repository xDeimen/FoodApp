#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Product {
public:
    Product(const std::string& name, double price)
        : m_name(name), m_price(price) {}

    std::string getName() const {
        return m_name;
    }

    double getPrice() const {
        return m_price;
    }

private:
    std::string m_name;
    double m_price;
};