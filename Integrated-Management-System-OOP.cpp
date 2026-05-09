#include <iostream>
#include <string>
using namespace std;

class department {
private:
    string dep_name;
    string manager;
    int num_employees;
    static int total_departments; 

public:
    department(string d, string m, int n) : dep_name(d), manager(m), num_employees(n) {
        total_departments++; // Increment total departments when a new department is created
    }

    void addEmployee() {
        num_employees++;
    }

    void removeEmployee() {
        if (num_employees > 0) {
            num_employees--;
        } else {
            cout << "No employees to remove." << endl;
        }
    }

    double calculateBudget(double salaryPerEmployee) const { 
        return num_employees * salaryPerEmployee;
    }

    string getName() const { 
        return dep_name;
    }

    string getManager() const { 
        return manager;
    }

    int getNumEmployees() const { 
        return num_employees;
    }

    static int getTotalDepartments() { // Static member function to access total departments 
        return total_departments;
    }

    // Overloading the + operator to add number of employees of two departments
    department operator+(const department& other) const {
        return department("", "", num_employees + other.num_employees);
    }

    // Friend function to access private members
    friend ostream& operator<<(ostream& os, const department& dep);
};

// Initialize static member outside the class
int department::total_departments = 0;

ostream& operator<<(ostream& os, const department& dep) { 
    os << "Department Name: " << dep.dep_name << "\nManager: " << dep.manager << "\nNumber of Employees: " << dep.num_employees;
    return os;
}

class emp {
private:
    string name;
    int id;
    string position;
    int age;
    double salary;

public:
    emp(string n, int i, string p, int a, double s) : name(n), id(i), position(p), age(a), salary(s) {}

    void updateInfo(string upd_name, string upd_position, int upd_age, double upd_salary) {
        name = upd_name;
        position = upd_position;
        salary = upd_salary;
        age = upd_age;
    }

    double calculateBonus(double bonusPercentage) const { 
        return salary * (bonusPercentage / 100.0);
    }

    void printSalaryAfterBonus(double bonusPercentage) const { 
        double bonus = calculateBonus(bonusPercentage);
        double salaryAfterBonus = salary + bonus;
        cout << "The new salary after the bonus is $" << salaryAfterBonus << endl;
    }

    string getName() const { 
        return name;
    }

    int getID() const { 
        return id;
    }

    string getPosition() const 
    { 
        return position;
    }

    double getSalary() const { 
        return salary;
    }

    int getAge() const { 
        return age;
    }

    // Friend function to access private members 
    friend ostream& operator<<(ostream& os, const emp& e);
};

ostream& operator<<(ostream& os, const emp& e) {
    os << "Name: " << e.name << "\nID: " << e.id << "\nPosition: " << e.position << "\nAge: " << e.age << "\nSalary: $" << e.salary;
    return os;
}

class library {
private:
    static const int MAX_BOOKS = 100;
    struct Book {
        string title;
        string author;
    };
    Book books[MAX_BOOKS];
    int numBooks;

public:
    library() : numBooks(0) {}

    void addBook() {
        if (numBooks < MAX_BOOKS) {
            cout << "Enter the title of the book: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, books[numBooks].title);
            cout << "Enter the author of the book: ";
            getline(cin, books[numBooks].author);
            numBooks++;
            cout << "Book added successfully." << endl;
        } else {
            cout << "The library is full. Cannot add more books." << endl;
        }
    }

    void displayBooks() const { 
        for (int i = 0; i < numBooks; ++i) {
            cout << "Book " << (i + 1) << ": " << books[i].title << " by " << books[i].author << endl;
        }
    }
};

// Chatbot to interact with the user
void chatbot() {
    cout << "Welcome to the Chatbot! How can I assist you today?\n";
    cout << "1. Department Info\n2. Employee Info\n3. Add Books\n4. Exit\n";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            department dep("IT", "Alice", 10);
            cout << dep << endl;
            break;
        }
        case 2: {
            emp e("Bob", 101, "Developer", 30, 5000);
            cout << e << endl;
            break;
        }
        case 3: {
            library lib;
            char addMoreBooks;
            do {
                lib.addBook();
                cout << "Do you want to add another book? (y/n): ";
                cin >> addMoreBooks;
            } while (addMoreBooks == 'y' || addMoreBooks == 'Y');
            lib.displayBooks();
            break;
        }
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}

int main() {
    // Testing the department class
    cout <<"*************************" <<endl;
    cout << "testing department class" << endl;
    cout <<"*************************" <<endl;
    department node_js("node.js", "Ahmed Farhat", 5);
    department cpp("C++", "John Doe", 8);
    cout << "\nDepartment Information:\n" << node_js << endl;

    // Adding the number of employees of two departments
    cout <<"**************************************************" <<endl;
    cout << "Adding the number of employees of two departments" <<endl;
    cout <<"**************************************************" <<endl;
    department combined_department = node_js + cpp;
    cout << "\nCombined number of employees of node_js and cpp departments: " << combined_department.getNumEmployees() << endl;
    cout << "Total Departments: " << department::getTotalDepartments() << endl; // Accessing static member function 

    // Testing the emp class
    cout <<"*****************" <<endl;
    cout << "testing emp class" << endl;
     cout <<"*****************" <<endl;
    emp emp1("Saea", 12321, "Software Engineer", 25, 5000);
    emp1.updateInfo("Saea", "Software Engineering Manager", 27, 10000);
    double bonusPercentage = 10;
    double bonus = emp1.calculateBonus(bonusPercentage);
    cout << "\nEmployee Information:\n" << emp1 << endl;
    cout << "Bonus: $" << bonus << endl;
    emp1.printSalaryAfterBonus(bonusPercentage);

    // Testing the library class
    cout << "************************" <<endl;
    cout << "tesing the library class" << endl;
     cout <<"************************" <<endl;
    
    library l1;
    char addMoreBooks;
    do {
        l1.addBook();
        cout << "Do you want to add another book? (y/n): ";
        cin >> addMoreBooks;
    } while (addMoreBooks == 'y' || addMoreBooks == 'Y');
    l1.displayBooks();

    // Loop to keep using the chatbot
    char useChatbot;
    do {
        chatbot();
        cout << "Do you want to use the chatbot again? (y/n): ";
        cin >> useChatbot;
    } while (useChatbot == 'y' || useChatbot == 'Y');

    return 0;
}
