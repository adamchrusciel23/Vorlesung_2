#include <iostream>
#include <limits>
#include <string>

void readStudentData(std::string& name, double& homework, double& midterm, double& finalExam) {

    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    
    std::cout << "Homework score: ";
    while(!(std::cin >> homework) || homework < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Bitte Ganzzahl eingeben: ";
    }
    
    std::cout << "Midterm score: ";
    while(!(std::cin >> midterm) || midterm < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Bitte Ganzzahl eingeben: ";
    }
    
    std::cout << "Final exam score: ";
    while(!(std::cin >> finalExam) || finalExam < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Bitte Ganzzahl eingeben: ";
    }
}

void calculateGrade(double& homework, double& midterm, double& finalExam, double& finalGrade, std::string& letterGrade) {
    finalGrade = 0.4*homework + 0.25*midterm + 0.35*finalExam;
    if(finalGrade < 50) {
        letterGrade = "F";
    }
    else if (finalGrade < 59) {
        letterGrade = "E";
    }
    else if (finalGrade < 69) {
        letterGrade = "D";
    }
    else if (finalGrade < 79) {
        letterGrade = "C";
    }
    else if (finalGrade < 89) {
        letterGrade = "B";
    }
    else {
        letterGrade = "A";
    }
}

void status(std::string& letterGrade) {
    if (letterGrade == "A" || letterGrade == "B" || letterGrade == "C") {
        std::cout << "PASS";
    }
    if (letterGrade == "D" || letterGrade == "E") {
        std::cout << "CONDITIONAL PASS";
    }
    if (letterGrade == "F") {
        std::cout << "FAIL";
    }
}

void printReport(std::string& name, double& homework, double& midterm, double& finalExam, double& finalGrade, std::string& letterGrade) {
    
    
    std::cout << "-------------------------------------" << "\n" << "Student Report\n" << "-------------------------------------\n" << "Name: " << name << "\n";
    std::cout << "Scores\n" << "-------------------------------------\n";
    std::cout << "Homework              : " << homework << "\n";
    std::cout << "Midterm               : " << midterm << "\n";
    std::cout << "Final Exam            : " << finalExam << "\n";
    std::cout << "\n";
    std::cout << "Final Grade           : " << finalGrade << "\n";
    std::cout << "Letter Grade          : " << letterGrade << "\n";
    std::cout << "Status                : ";
    status(letterGrade);
    std::cout << "\n";
}

int main() {
    std::string name;
    double homework = 0;
    double midterm = 0;
    double finalExam = 0;
    double finalGrade = 0;
    std::string letterGrade;

    readStudentData(name, homework, midterm, finalExam);
    calculateGrade(homework, midterm, finalExam, finalGrade, letterGrade);
    printReport(name, homework, midterm, finalExam, finalGrade, letterGrade);
}