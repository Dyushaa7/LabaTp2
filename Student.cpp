#include "Student.h"

STUDENT::STUDENT() : fullName(nullptr), group(nullptr), grades(nullptr), gradesCount(0) {
    std::cout << "Konstruktor po umolchaniyu STUDENT vyzvan.\n";
}

STUDENT::STUDENT(const char* name, const char* grp, int* grds, int count) : gradesCount(count) {
    std::cout << "Konstruktor s parametrami STUDENT vyzvan.\n";
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
    
    group = new char[strlen(grp) + 1];
    strcpy(group, grp);
    
    grades = new int[count];
    for (int i = 0; i < count; i++) {
        grades[i] = grds[i];
    }
}

STUDENT::STUDENT(const STUDENT& other) : gradesCount(other.gradesCount) {
    std::cout << "Konstruktor kopirovaniya STUDENT vyzvan.\n";
    fullName = new char[strlen(other.fullName) + 1];
    strcpy(fullName, other.fullName);

    group = new char[strlen(other.group) + 1];
    strcpy(group, other.group);

    grades = new int[gradesCount];
    for (int i = 0; i < gradesCount; i++) {
        grades[i] = other.grades[i];
    }
}

STUDENT::~STUDENT() {
    std::cout << "Destrokator STUDENT vyzvan.\n";
    delete[] fullName;
    delete[] group;
    delete[] grades;
}

void STUDENT::setFullName(const char* name) {
    if (fullName) delete[] fullName;
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
}

void STUDENT::setGroup(const char* grp) {
    if (group) delete[] group;
    group = new char[strlen(grp) + 1];
    strcpy(group, grp);
}

void STUDENT::setGrades(int* grds, int count) {
    if (grades) delete[] grades;
    gradesCount = count;
    grades = new int[count];
    for (int i = 0; i < count; i++) {
        grades[i] = grds[i];
    }
}

const char* STUDENT::getFullName() const {
    return fullName;
}

const char* STUDENT::getGroup() const {
    return group;
}

double STUDENT::averageGrade() const {
    if (gradesCount == 0) return 0;
    double sum = 0;
    for (int i = 0; i < gradesCount; i++) sum += grades[i];
    return sum / gradesCount;
}

std::istream& operator>>(std::istream& in, STUDENT& student) {
    char name[100], grp[10];
    int count;

    std::cout << "Vvedite familiyu i initsialy: ";
    in >> std::ws;
    in.getline(name, 100);
    student.setFullName(name);

    std::cout << "Vvedite nomer grupy: ";
    in >> grp;
    student.setGroup(grp);

    std::cout << "Vvedite kolichestvo otsenok: ";
    in >> count;
    
    if (count <= 0) throw std::invalid_argument("Kolichestvo otsenok dolzhno byt' polozhitelnym.");

    int* grds = new int[count];
    std::cout << "Vvedite otsenki: ";
    for (int i = 0; i < count; i++) {
        in >> grds[i];
    }

    student.setGrades(grds, count);
    delete[] grds;  // Osvobozhdaem vremenniy massiv

    return in;
}

std::ostream& operator<<(std::ostream& out, const STUDENT& student) {
    out << student.fullName << " (" << student.group << ") - Sredniy ball: " 
        << student.averageGrade();
    return out;
}
