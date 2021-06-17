#pragma once 

#include <iostream>
#include <vector> 
#include "student.hpp"

class University {
    std::vector<Student> university_;
public: 
    University(const Student&);
    ~University();
   
    void dispalayBase();
    void addStudent(std::string, std::string, std::string, long long, long long, std::string);
    Student findBySurname(const std::string&);
    Student findByPesel(const long long&);
    void sortByPesel();
    void sortbyLname();
    void removeByIndexNumber();
  
    //bool validationByPESEL();
    //void writeToFIle();
    //void readFile();

    // pomyślec jak dodać walidację pracownika.
};

