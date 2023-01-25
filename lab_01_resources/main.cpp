#include "Cat.h"
#include "Dog.h"

int main(){

    float hunger_arr[5] = {0, 20, 40, 60, 80};
    float thirst_arr[5] = {10, 30, 50, 70, 90};
    float eat_amount = 25;
    float drink_amount = 50;

    Cat cat1(hunger_arr[0]);	// object constructed during compile-time
    Dog dog1(hunger_arr[1]);	// object constructed during run-time. 'dog1' is a pointer.

    std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    // Note the '->' operator. This is used as a shortcut to de-reference a pointer & access the object.
    // The long-form version would be '(*dog1).GetHunger()' and yes, that set of '()' is required.
    std::cout << "Dog hunger: " << dog1.GetHunger() << std::endl;

    cat1.Eat(10);
    dog1.Eat(20);

    std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    std::cout << "Dog hunger: " << dog1.GetHunger() << std::endl;

    cat1.Speak();
    dog1.Speak();
}
