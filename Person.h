#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person
{
protected:
    int id;
    string name;
    int age;

public:
    Person() {}

    Person(int id, string name, int age)
    {
        this->id = id;
        this->name = name;
        this->age = age;
    }

    virtual void display() = 0;

    int getId()
    {
        return id;
    }
};

#endif