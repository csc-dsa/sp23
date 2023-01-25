#include "Animal.h"

Animal::Animal(float initial_hunger){
    this->hunger = initial_hunger;
}

float Animal::GetHunger(){
    return this->hunger;
}

void Animal::Eat(float sustenance){
    this->hunger += sustenance;
}
