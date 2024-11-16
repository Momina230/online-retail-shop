# **E-Commerce Platform**
## **Description**:
This project is a console-based E-Commerce Platform developed in C++ that provides users with functionalities such as user registration, login, shopping, managing purchasing history, and viewing or leaving reviews and comments. The platform maintains user data, purchase history, and reviews in external files, ensuring data persistence.

The program is designed to provide a seamless shopping experience and introduces features like discounts for top purchasers, shipping charges, and categorized shopping.

 # **Features**:
## **User Registration and Login**:
- **Register**: Users can create an account by providing a username (alphabets only) and a password.
- **Login**: Existing users can log in to access their account and view their purchasing history.
- **Shopping and Checkout**:
# **Categorized shopping experience with the following categories:**
- Electronics
- Gloves
- Beauty Products
- Perfumes
Users can select products, purchase them, and record transactions.
### **Discount for Top Purchasers** :
A 40% discount is applied if the user is identified as the highest purchaser.
### **Shipping Charges:**
A flat shipping charge of $20 is applied once per session.
## **User Management**:
- ### **View User Details**:
  Displays the user’s purchasing history, total spent, and details of all past purchases.
-### **Highest Purchaser**:
Tracks and identifies the user with the maximum purchases and stores the information in a file.
- ### **Reviews and Comments**:
View all user reviews and comments.
- ### **Leave a review or comment about the platform**.
## **File Structure**:

ECommercePlatform/
- main.cpp                   ( Source code for the platform )

- user_data.txt                ( Stores user information (username, password, total spent))
- purchase_data.txt            ( Logs user purchases (username, product, price))
- reviews_comments.txt         ( Contains reviews and comments from users)
- top_purchasers.txt           ( Stores the highest purchaser information)


## **How to Run**:
- Compile the Code.
- Copy code.
// g++ main.cpp -o ECommercePlatform
## **Follow the Menu**: 
Use the menu options to register, log in, shop, view details, or manage reviews.

## **Future Enhancements**:
- Add search functionality for products and users.
- Introduce update and delete options for user data and purchases.
- Integrate a graphical user interface (GUI).
- Improve file handling with error checks and validations.
- Enhance shopping categories and add product inventory management.
## **Requirements**:
- A C++ compiler (e.g., GCC).
- Basic understanding of file handling and OOP in C++.
## **Contributing**:
Contributions are welcome! Feel free to fork this repository, add features, and submit a pull request. 😊

