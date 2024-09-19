
#include <stdio.h>
include <string.h> // for strcpy

// Define an enumeration for days of the week
typedef enum {
    SUNDAY = 0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY = 14,
    FRIDAY,
    SATURDAY
} DayOfWeek;

// Define a struct for representing a person
typedef struct {
    char name[50];
    int age;
    char gender;
} Person;

int main() {
    // Declare a variable of type DayOfWeek
    DayOfWeek today = SATURDAY;
    printf("Enum number: %d\n", today);

    // Declare a variable of type Person
    Person person1;

    // Assign values to the fields of person1
    strcpy(person1.name, "John");
    person1.age = 30;
    person1.gender = 'M';

    // Print the values of person1
    printf("Person's Name: %s\n", person1.name);

    return 0;
}

