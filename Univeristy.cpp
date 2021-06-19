#include "Univeristy.hpp"

#include "Student.hpp"

University::University(const Student& s) {
    university_.push_back(s);
}
University::~University() {}


void University::displayStudent(const Student& student) {
    std::cout << student.getName() << ", "
            << student.getLname() << ", "
            << student.getAdress() << ", "
            << student.getIndex() << ", "
            << student.getPesel() << ", "
            << student.getGender() << '\n';
}

void University::dispalayBase() {
    for (int i = 0; i < university_.size() - 1; i++) {
        std::cout << i << "." << university_[i].getName() << ", "
                  << university_[i].getLname() << ", "
                  << university_[i].getAdress() << ", "
                  << university_[i].getIndex() << ", "
                  << university_[i].getPesel() << ", "
                  << university_[i].getGender() << '\n';
    }
}

void University::addStudent(std::string name, std::string l_name, std::string adress, size_t indexNumber, std::string pesel, std::string gender) {
    Student newStudent(name, l_name, adress, indexNumber, pesel, gender);
    university_.push_back(newStudent);
}

Student University::findBySurname(const std::string& surname){
    auto isTheSame = [&surname](Student student){ return student.getLname() == surname; };
    auto result = std::find_if(university_.begin(), university_.end(), isTheSame);
 
    if (result == university_.end()) {
        std::cout << "There is no such student in our database with given surname" << '\n';
        return *result;
    }
 
    return *result;
}
 
Student University::findByPesel(const std::string& pesel){
    auto isTheSame = [&pesel](Student student){ return student.getPesel() == pesel; };

    auto result = std::find_if(university_.begin(), university_.end(), isTheSame);
 
    if (result == university_.end()) {
        std::cout << "There is no such student in our database with given PESEL number" << '\n';
        return *result;
    }
 
    return *result;
}

void University::sortByPesel() {
    std::sort(university_.begin(), university_.end(),
              [](const Student& lhsPtr, const Student& rhsPtr) {
                  return lhsPtr.getPesel() < rhsPtr.getPesel();
              });
}
// Implemented sort by LName
void University::sortbyLname() {
    std::sort(university_.begin(), university_.end(),
              [](const Student& lhsPtr, const Student& rhsPtr) {
                  return lhsPtr.getLname() < rhsPtr.getLname();
              });
}

bool University::validationByPesel(const std::string& pesel){
    static constexpr std::array<int,10> weightFactors {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int result = 0;
    int number = 0;
    
    for(size_t i = 0; i < weightFactors.size(); i++){
        number = pesel[i] - '0';
        result += number*weightFactors[i];
    }
    
    result = result % weightFactors.size();
    
    if (result != 0) {
        result = weightFactors.size() - result;
    }
    
    int lastNumber = (pesel.back()-'0');

    return result == lastNumber;
}

void University::exportDatabase() {
    std::ofstream Database;
    Database.open("university-db-exported.csv");
    if (Database.is_open()) {
        for (auto& itStudent : university_) {
            Database << itStudent.getName() << ","
                     << itStudent.getLname() << ","
                     << itStudent.getAdress() << ","
                     << itStudent.getIndex() << ","
                     << itStudent.getPesel() << ","
                     << itStudent.getGender() << "\n";
        }
        Database.close();
    } else
        std::cout << "Unable to open file";
}

void University::importDatabase() {
    std::ifstream Database("university-db.csv");
    std::string line;
    if (Database.is_open()) {
        size_t iLine = 0;
        while (Database.peek()) {
            getline(Database, line, ',');
            university_[iLine].setName(line);
            getline(Database, line, ',');
            university_[iLine].setLname(line);
            getline(Database, line, ',');
            university_[iLine].setAdress(line);
            getline(Database, line, ',');
            university_[iLine].setIndex(std::stoi(line));
            getline(Database, line, ',');
            university_[iLine].setPesel(line);
            getline(Database, line, ',');
            university_[iLine].setGender(line);
            iLine += 1;
        }
        Database.close();
    } else
        std::cout << "Unable to open file";
}
