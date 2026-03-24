#include "GodObjectPerson.h"
#include <iostream>
#include <cstdlib> // для rand() и srand()
#include <ctime>   // для time()
#include <bitset>  // для отображения битового поля в двоичном виде


using namespace std;



int main()
{
    GodObjectPerson person;
    uint32_t conditions{};
  
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

	person.SetRandomConditions(conditions);

    person.SetName("John");
    person.SetSurname("Smith");
    person.SetPatronym("Smithovich");
    person.SetAge(30);
    person.SetGender(true);
    person.SetRace("Caucasian");
    person.SetGrowth(180);
    person.SetWeight(80);
    person.SetMainActivity("Programmer");
    person.SetPhysConditions(conditions);
	person.SetCurrentCoordinates(10.0f, 20.0f, 30.0f);

	cout << "Current conditions bitfield: " << conditions << endl;
	cout << "Current conditions in binary: ";
    cout << std::bitset<sizeof(conditions)*8>(conditions) << endl;
    cout << "Physical condition: " << person.GetPhysConditions() << endl;
    cout << "Name: "               << person.GetName() << endl;
    cout << "Surname: "            << person.GetSurname() << endl;
    cout << "Patronym: "           << person.GetPatronym() << endl;
    cout << "Age: "                << person.GetAge() << endl;
    cout << "Gender"               << person.GetGender() << endl;
    cout << "Race:"                << person.GetRace()<< endl;
    cout << "Growth: "             << person.GetGrowth() << endl;
    cout << "Weight: "             << person.GetWeight() << endl;
    cout << "Main activity: "      << person.GetMainActivity() << endl;
    cout << "Current coordinates: "
         << person.GetCurrentCoordinates().x << ", "
         << person.GetCurrentCoordinates().y << ", "
         << person.GetCurrentCoordinates().z << endl;

    return 0;
}