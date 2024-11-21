#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class STUDENT {
private:
    char* fullName;
    char* group;
    int* grades;
    int gradesCount;

public:
    STUDENT();
    STUDENT(const char* name, const char* grp, int* grds, int count);
    STUDENT(const STUDENT& other);
    ~STUDENT();

    void setFullName(const char* name);
    void setGroup(const char* grp);
    void setGrades(int* grds, int count);
    const char* getFullName() const;
    const char* getGroup() const;
    double averageGrade() const;

    friend std::istream& operator>>(std::istream& in, STUDENT& student);
    friend std::ostream& operator<<(std::ostream& out, const STUDENT& student);
};

#endif
