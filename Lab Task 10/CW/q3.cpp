#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct User {
    int user_id;
    string first_name;
    string last_name;
    string address;
    string email;
};

struct Product {
    int product_id;
    string product_name;
    string description;
    int price;
};

struct Order {
    int order_id;
    int user_id;
    int product_ordered;
    int total_paid;
};

class FileDatabase {
private:
    string usersFile = "users.dat";
    string productsFile = "products.dat";
    string ordersFile = "orders.dat";

    void writeUsersToFile(const vector<User>& users) {
        ofstream file(usersFile, ios::binary);
        for (const auto& user : users) {
            file.write(reinterpret_cast<const char*>(&user.user_id), sizeof(int));
            file.write(user.first_name.c_str(), user.first_name.size() + 1);
            file.write(user.last_name.c_str(), user.last_name.size() + 1);
            file.write(user.address.c_str(), user.address.size() + 1);
            file.write(user.email.c_str(), user.email.size() + 1);
        }
        file.close();
    }

    vector<User> readUsersFromFile() {
        vector<User> users;
        ifstream file(usersFile, ios::binary);
        if (file) {
            while (file.peek() != EOF) {
                User user;
                file.read(reinterpret_cast<char*>(&user.user_id), sizeof(int));
                
                getline(file, user.first_name, '\0');
                getline(file, user.last_name, '\0');
                getline(file, user.address, '\0');
                getline(file, user.email, '\0');
                
                users.push_back(user);
            }
        }
        file.close();
        return users;
    }

    void writeProductsToFile(const vector<Product>& products) {
        ofstream file(productsFile, ios::binary);
        for (const auto& product : products) {
            file.write(reinterpret_cast<const char*>(&product.product_id), sizeof(int));
            file.write(product.product_name.c_str(), product.product_name.size() + 1);
            file.write(product.description.c_str(), product.description.size() + 1);
            file.write(reinterpret_cast<const char*>(&product.price), sizeof(int));
        }
        file.close();
    }

    vector<Product> readProductsFromFile() {
        vector<Product> products;
        ifstream file(productsFile, ios::binary);
        if (file) {
            while (file.peek() != EOF) {
                Product product;
                file.read(reinterpret_cast<char*>(&product.product_id), sizeof(int));
                
                getline(file, product.product_name, '\0');
                getline(file, product.description, '\0');
                file.read(reinterpret_cast<char*>(&product.price), sizeof(int));
                
                products.push_back(product);
            }
        }
        file.close();
        return products;
    }

    void writeOrdersToFile(const vector<Order>& orders) {
        ofstream file(ordersFile, ios::binary);
        for (const auto& order : orders) {
            file.write(reinterpret_cast<const char*>(&order.order_id), sizeof(int));
            file.write(reinterpret_cast<const char*>(&order.user_id), sizeof(int));
            file.write(reinterpret_cast<const char*>(&order.product_ordered), sizeof(int));
            file.write(reinterpret_cast<const char*>(&order.total_paid), sizeof(int));
        }
        file.close();
    }

    vector<Order> readOrdersFromFile() {
        vector<Order> orders;
        ifstream file(ordersFile, ios::binary);
        if (file) {
            while (file.peek() != EOF) {
                Order order;
                file.read(reinterpret_cast<char*>(&order.order_id), sizeof(int));
                file.read(reinterpret_cast<char*>(&order.user_id), sizeof(int));
                file.read(reinterpret_cast<char*>(&order.product_ordered), sizeof(int));
                file.read(reinterpret_cast<char*>(&order.total_paid), sizeof(int));
                orders.push_back(order);
            }
        }
        file.close();
        return orders;
    }

public:
    void initializeDatabase() {
        ofstream ufile(usersFile, ios::binary);
        ofstream pfile(productsFile, ios::binary);
        ofstream ofile(ordersFile, ios::binary);
        ufile.close();
        pfile.close();
        ofile.close();
    }

    void addDummyData() {
        // Users
        vector<User> users = {
            {1, "Linus", "Torvalds", "123 Linux Lane", "linus@linux.com"},
            {2, "Bill", "Gates", "456 Microsoft Way", "bill@microsoft.com"},
            {3, "Steve", "Jobs", "789 Apple Street", "steve@apple.com"}
        };

        // Products
        vector<Product> products = {
            {1, "Linux OS", "Open-source operating system", 0},
            {2, "Windows", "Proprietary operating system", 199},
            {3, "MacOS", "Apple operating system", 299},
            {4, "Git", "Version control system", 0}
        };

        // Orders
        vector<Order> orders = {
            {1, 1, 1, 0},   
            {2, 1, 4, 0},    
            {3, 2, 2, 199},  
            {4, 3, 3, 299}  
        };

        writeUsersToFile(users);
        writeProductsToFile(products);
        writeOrdersToFile(orders);
    }

    vector<string> getProductsForUser(const string& firstName) {
        vector<string> result;
        
        vector<User> users = readUsersFromFile();
        vector<Product> products = readProductsFromFile();
        vector<Order> orders = readOrdersFromFile();

        int userId = -1;
        for (const auto& user : users) {
            if (user.first_name == firstName) {
                userId = user.user_id;
                break;
            }
        }

        if (userId == -1) {
            return result; 
        }

        for (const auto& order : orders) {
            if (order.user_id == userId) {
                for (const auto& product : products) {
                    if (product.product_id == order.product_ordered) {
                        result.push_back(product.product_name);
                        break;
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    FileDatabase db;
    db.initializeDatabase();
    db.addDummyData();

    vector<string> linusProducts = db.getProductsForUser("Linus");

    cout << "Products associated with Linus:" << endl;
    for (const auto& product : linusProducts) {
        cout << "- " << product << endl;
    }

    return 0;
}