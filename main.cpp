#include <iostream>
#include "Student.h"

void displayMenu() {
    std::cout << "1. Dobavit studenta\n";
    std::cout << "2. Pokazat studentov s otsenkami 4 i 5\n";
    std::cout << "3. Vykhod\n";
}

int main() {
    STUDENT* students = nullptr;
    int studentCount = 0;
    int choice;

    while (true) {
        displayMenu();
        std::cout << "Vyberite deystvie: ";
        std::cin >> choice;
        if (choice == 1) {
            try {
                STUDENT* newStudents = new STUDENT[studentCount + 1];
                for (int i = 0; i < studentCount; i++) {
                    newStudents[i] = students[i]; // Kopiruem suschestvuyushchikh studentov
                }
                delete[] students; // Osvobozhdaem pamat

                std::cin >> newStudents[studentCount]; // Vvod novogo studenta
                students = newStudents;
                studentCount++;
            } catch (const std::exception& e) {
                std::cerr << "Oshibka: " << e.what() << std::endl;
            }
        } else if (choice == 2) {
            bool found = false;
            for (int i = 0; i < studentCount; ++i) {
                if (students[i].averageGrade() >= 4.0) {
                    std::cout << students[i] << std::endl;
                    found = true;
                }
            }
            if (!found) {
                std::cout << "Net studentov s otsenkami 4 i 5." << std::endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Nevernyy vybor. Poprobuyte snova.\n";
        }
    }

    delete[] students; // Osvobozhdaem pamyat
    return 0;
}
