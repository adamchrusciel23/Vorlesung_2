#include <iostream>
#include <string>

class User {
    protected:
        std::string name;
        int id;

    public:
        User(std::string name, int id) : name(name), id(id) { }

        void printInfo() {
            std::cout << "Name: " << name << "\nID: " << id << "\n";
        }
};

class Student: public User {
    private:
        double GPA = 0;
    public:
        Student(std::string name, int id, double gpa) : User(name, id), GPA(gpa) { }

        void printRole() {
            std::cout << "Name: " << name << "\nID: " << id << "\nRolle: Student\n";
        }
};

class Instructor: public User {
    private:
        double salary = 0;
    public:
        Instructor(std::string name, int id, double salary) : User(name, id), salary(salary) { }

        void printRole() {
            std::cout << "Name: " << name << "\nID: " << id << "\nRolle: Instruktor\n";
        }
};

int main() {
    Instructor instruktor = Instructor("Phillip", 0, 4500);
    Student student = Student("Max", 1, 2.1);

    instruktor.printInfo();
    student.printInfo();
    instruktor.printRole();
    student.printRole();
}