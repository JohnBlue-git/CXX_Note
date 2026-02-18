#include <iostream>
#include <concepts>

// A C++20 Concept to enforce the Static Interface at compile-time
template <typename T>
concept IsAnimal = requires(T v) {
    { v.make_sound() } -> std::same_as<void>;
};

template <typename Derived>
class Animal {
public:
    // Move the check inside the constructor!
    // This is only checked when an object is actually created,
    // at which point 'Derived' is a fully defined class.
    Animal() {
        static_assert(IsAnimal<Derived>, 
            "\n\n[CRTP Error]: Your Derived class is missing 'void make_sound()'.\n"
            "Remember to make it private and add 'friend class Animal<Derived>;'\n");
    }

    // The Public Interface
    void speak() {
        // Static dispatch: no vtable overhead
        static_cast<Derived*>(this)->make_sound();
    }
};

class Dog : public Animal<Dog> {
private:
    // Granting Base access to private members
    friend class Animal<Dog>;

    void make_sound() {
        std::cout << "Woof! (Static Dispatch)" << std::endl;
    }
};

class Cat : public Animal<Cat> {
private:
    friend class Animal<Cat>;

    void make_sound() {
        std::cout << "Meow... (Static Dispatch)" << std::endl;
    }
};

// This class would cause a COMPILE-TIME error if speak() is called,
// because it doesn't implement make_sound().
class SilentFish : public Animal<SilentFish> {
    // Missing make_sound()
};

int main() {
    Dog d;
    Cat c;

    d.speak();
    c.speak();

    // Uncommenting this will trigger the static_assert error
    // SilentFish f;

    return 0;
}