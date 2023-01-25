#ifndef LAB_01_CODE_ANIMAL_H
#define LAB_01_CODE_ANIMAL_H

#include <iostream>

class Animal{
private:
    float hunger;

public:
    Animal(float initial_hunger);
    void Eat(float sustenance);
    float GetHunger();
    virtual void Speak() = 0;
};

#endif //LAB_01_CODE_ANIMAL_H
