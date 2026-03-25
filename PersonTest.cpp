#include "GodObjectPerson.h"
#include <iostream>
#include <cstdlib> // rand() и srand()
#include <ctime>   // time()
#include <bitset>  // convert uint32_t to binary string


using namespace std;



int main()
{
    GodObjectPerson person;
    uint32_t conditions{};
    std::vector<std::string> invNames;

    invNames.push_back("Eblan");
    invNames.push_back("Mudak");
    invNames.push_back("Ueban");
    invNames.push_back("Hueta");
    invNames.push_back("Valera");

  
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

	person.SetRandomConditions(conditions);
   
    person.SetInvalideNames(invNames);
    person.SetName("John");
    person.SetSurname("Smith");
    person.SetPatronym("Smithovich");
    person.SetAge(30);
    person.SetGender(rand() %2);
    person.SetRace("Caucasian");
    person.SetGrowth(180.25);
    person.SetWeight(80.2);
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

    if (person.GetGender())
        cout << "Gender: " << "Man" << endl;
    else
		cout << "Gender: " << "Woman" << endl;

    cout << "Race: "               << person.GetRace()<< endl;
    cout << "Growth: "             << person.GetGrowth() << endl;
    cout << "Weight: "             << person.GetWeight() << endl;
    cout << "Main activity: "      << person.GetMainActivity() << endl;
    cout << "Current coordinates: "
         << person.GetCurrentCoordinates().x << ", "
         << person.GetCurrentCoordinates().y << ", "
         << person.GetCurrentCoordinates().z << endl;

    return 0;
}