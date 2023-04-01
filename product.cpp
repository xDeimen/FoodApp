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

class Orders {
public:
    Orders(const std::string& name, const std::vector<Product>& products)
        : m_name(name), m_products(products) {
        std::time_t now = std::time(nullptr);
        m_date = *std::localtime(&now);
    }

    double getSubtotal() const {
        double subtotal = 0.0;
        for (const Product& product : m_products) {
            subtotal += product.getPrice();
        }
        return subtotal;
    }

    std::string getName() const {
        return m_name;
    }

    std::vector<Product> getProducts() const {
        return m_products;
    }

    std::tm getDate() const {
        return m_date;
    }

private:
    std::string m_name;
    std::vector<Product> m_products;
    std::tm m_date;
};
