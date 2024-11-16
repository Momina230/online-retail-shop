#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
public:
    string name;
    string password;
    double totalSpent;

    User() : name(""), password(""), totalSpent(0.0) {}

    User(string userName, string userPassword) : name(userName), password(userPassword), totalSpent(0.0) {}

    void loadUserData() {
        ifstream infile("user_data.txt");
        if (infile.is_open()) {
            string stored_name, stored_password;
            double stored_totalSpent;
            while (infile >> stored_name >> stored_password >> stored_totalSpent) {
                if (stored_name == name && stored_password == password) {
                    totalSpent = stored_totalSpent;
                    break;
                }
            }
            infile.close();
        }
    }

    void saveUserData() {
        ifstream infile("user_data.txt");
        ofstream tempfile("temp_data.txt");
        bool user_found = false;
        if (infile.is_open() && tempfile.is_open()) {
            string stored_name, stored_password;
            double stored_totalSpent;
            while (infile >> stored_name >> stored_password >> stored_totalSpent) {
                if (stored_name == name && stored_password == password) {
                    stored_totalSpent = totalSpent;
                    user_found = true;
                }
                tempfile << stored_name << " " << stored_password << " " << stored_totalSpent << endl;
            }
            infile.close();
            if (!user_found) {
                tempfile << name << " " << password << " " << totalSpent << endl;
            }
            tempfile.close();
            remove("user_data.txt");
            rename("temp_data.txt", "user_data.txt");
        }
    }

    void recordPurchase(string product, double price) {
        ofstream outfile("purchase_data.txt", ios::app);
        if (outfile.is_open()) {
            outfile << name << " " << product << " " << price << endl;
            outfile.close();
        }
    }

    void displayUserDetails() {
        cout << "User: " << name << endl;
        cout << "Total spent: $" << totalSpent << endl;
        cout << "Purchased products: " << endl;
        ifstream infile("purchase_data.txt");
        if (infile.is_open()) {
            string user, product;
            double price;
            while (infile >> user >> product >> price) {
                if (user == name) {
                    cout << "- " << product << ": $" << price << endl;
                }
            }
            infile.close();
        }
    }
};

class Product {
public:
    string name;
    double price;
     Product(){
	 }
    Product(string productName, double productPrice) : name(productName), price(productPrice) {}

    void display() {
        cout << name << ", $" << price << endl;
    }
};

class ECommercePlatform {
public:
    User currentUser;
    bool loggedIn;

    ECommercePlatform() : loggedIn(false) {}

    void registerUser() {
        cout << "Enter username: ";
        string userName;
        cin >> userName;
        cout << "Enter password: ";
        string userPassword;
        cin >> userPassword;

        User newUser(userName, userPassword);
        newUser.saveUserData();
        cout << "Registration successful!" << endl;
    }

    void loginUser() {
        cout << "Enter username: ";
        string userName;
        cin >> userName;
        cout << "Enter password: ";
        string userPassword;
        cin >> userPassword;

        currentUser = User(userName, userPassword);
        currentUser.loadUserData();
        loggedIn = true;

        cout << "Login successful!" << endl;
    }

    void checkout() {
        if (!loggedIn) {
            cout << "Please log in first." << endl;
            return;
        }
  if (loggedIn==true){
  
        cout << "Welcome to the store, " << currentUser.name << "!" << endl;
        bool shopping = true;
        while (shopping) {
            int categoryChoice;
            cout << "Choose a category: 1. Electronics, 2. Gloves, 3. Beauty Products, 4. Perfumes" << endl;
            cin >> categoryChoice;

            Product products[5];
            int numProducts = 0;

            if (categoryChoice == 1) {
                products[0] = Product("Radio", 200);
                products[1] = Product("TV", 1000);
                products[2] = Product("Speakers", 300);
                products[3] = Product("Smart Watch", 250);
                products[4] = Product("Projector", 2000);
                numProducts = 5;
            } else if (categoryChoice == 2) {
                products[0] = Product("Disposable Gloves", 5);
                products[1] = Product("Canvas Gloves", 10);
                products[2] = Product("Leather Gloves", 15);
                products[3] = Product("Fabric Gloves", 7);
                products[4] = Product("Rubber Gloves", 20);
                numProducts = 5;
            } else if (categoryChoice == 3) {
                products[0] = Product("Perfumes", 200);
                products[1] = Product("Make-up", 100);
                products[2] = Product("Hair Products", 150);
                products[3] = Product("Lotions", 300);
                products[4] = Product("Creams", 150);
                numProducts = 5;
            } else if (categoryChoice == 4) {
                products[0] = Product("Dior Sauvage", 300);
                products[1] = Product("Creed Aventus", 200);
                products[2] = Product("Baccarat Rouge", 500);
                products[3] = Product("Bleu De Chanel", 700);
                products[4] = Product("Acqua Di Gio", 800);
                numProducts = 5;
            } else {
                cout << "Invalid choice." << endl;
                continue;
            }

            for (int i = 0; i < numProducts; ++i) {
                cout << i + 1 << ". ";
                products[i].display();
            }

            int productChoice;
            cout << "Choose a product to buy: ";
            cin >> productChoice;

            if (productChoice >= 1 && productChoice <= numProducts) {
                Product chosenProduct = products[productChoice - 1];
                currentUser.totalSpent += chosenProduct.price;
                currentUser.recordPurchase(chosenProduct.name, chosenProduct.price);
                currentUser.saveUserData();

                if (currentUser.totalSpent >= 5000) {
                    cout << currentUser.name << " is the most active user!" << endl;
                }

                char continueShopping;
                cout << "Do you want to buy another product? (y/n): ";
                cin >> continueShopping;
                if (continueShopping == 'n') {
                    shopping = false;
                }
            } else {
                cout << "Invalid choice." << endl;
            }
        }
    }
}
    void viewUserDetails() {
        if (!loggedIn) {
            cout << "Please log in first." << endl;
            return;
        }

        currentUser.displayUserDetails();
    }

    void displayMenu() {
        int choice;
        while (true) {
            cout << "1. Register\n2. Login\n3. Checkout\n4. User Details\n5. Exit" << endl;
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    registerUser();
                    break;
                case 2:
                    loginUser();
                    break;
                case 3:
                    checkout();
                    break;
                case 4:
                    viewUserDetails();
                    break;
                case 5:
                    cout << "Goodbye!" << endl;
                    return;
                default:
                    cout << "Invalid option. Please try again." << endl;
            }
        }
    }
};

int main() {
    ECommercePlatform platform;
    platform.displayMenu();
    return 0;
}