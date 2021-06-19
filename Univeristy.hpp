#pragma once 

#include <iostream>
#include <vector> 
#include <string>
#include <array>
#include <fstream>
#include "Student.hpp"

class University
{
    
public:
    std::vector<Student> university_;
        
    University(const Student&);
    ~University();
  
    void displayStudent(const Student&);
    void dispalayBase();
    void addStudent(std::string, std::string, std::string, size_t, std::string, std::string);
    Student findBySurname(const std::string&);
    Student findByPesel(const std::string&);
    void sortByPesel();
    void sortbyLname();
    void removeByIndexNumber();
    bool validationByPesel(const std::string&);
    void exportDatabase();
    void importDatabase();

    // pomyślec jak dodać walidację pracownika.
};

