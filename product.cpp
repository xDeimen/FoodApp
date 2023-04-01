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

class User {
public:
    User(const std::string& name) : m_name(name), m_ordersPlaced(0) {}

    void addToCart(const Product& product) {
        m_cart.push_back(product);
    }

    void placeOrder() {
        Orders order(m_name, m_cart);
        std::cout << "Order details:" << std::endl;
        for (const Product& product : m_cart) {
            std::cout << "- " << product.getName() << " $" << product.getPrice() << std::endl;
        }
        std::cout << "Total price: $" << order.getSubtotal() << std::endl;
        m_orders.push_back(order);
        m_cart.clear();
        m_ordersPlaced++;
    }

    std::string getName() const {
        return m_name;
    }

    std::vector<Product> getCart() const {
        return m_cart;
    }

    std::vector<Orders> getOrders() const {
        return m_orders;
    }

    int getOrdersPlaced() const {
        return m_ordersPlaced;
    }

private:
    std::string m_name;
    std::vector<Product> m_cart;
    std::vector<Orders> m_orders;
    int m_ordersPlaced;
};

int main() {
    // Create some sample products
    Product pizza("Pizza", 12.50);
    Product burger("Burger", 8.99);
    Product fries("Fries", 4.50);
    Product soda("Soda", 2.50);

    // Create some sample users
    User john("John Smith");
    User jane("Jane Doe");

    // John adds some products to his cart
    john.addToCart(pizza);
    john.addToCart(burger);
    john.addToCart(fries);

    // Jane adds some products to her cart
    jane.addToCart(burger);
    jane.addToCart(soda);

    // John places his order
    john.placeOrder();

    // Jane places her order
    jane.placeOrder();

    // Print John's order history
    std::cout << john.getName() << "'s order history:" << std::endl;
    for (const Orders& order : john.getOrders()) {
        std::cout << "- Placed on ";
        std::cout << order.getDate().tm_mday << "/" << (order.getDate().tm_mon