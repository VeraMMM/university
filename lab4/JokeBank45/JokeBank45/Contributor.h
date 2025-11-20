#pragma once
#include <iostream> 
#include <string> 
using namespace std;

class Contributor
{
private:
    string name;
    int age;
    double size;


public:

    string getName() const { return name; }
    int getAge() const { return age; }
    double getSize() const { return size; }

    //Person(const string& personName, const int& personAge) : name(personName), age(personAge) {}
    Contributor(const string& personName, const int& personAge): name(personName), age(personAge), size(0.0) {}
    Contributor(const string& personName, const int& personAge, double personSize) : name(personName), age(personAge), size(personSize) {}
    void setSize(double newSize) { size = newSize; }
    void displayContributor() const {
        cout << "Person: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "size: " << size << endl;
        
    }

};