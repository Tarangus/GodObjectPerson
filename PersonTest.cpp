#include "GodObjectPerson.h"
#include <iostream>
#include <cstdlib> // rand() и srand()
#include <ctime>   // time()
#include <bitset>  // convert uint32_t to binary string


using namespace std;

int main()
{
    Person person;

    //imitation of incoming data
    uint32_t conditions{};
    std::vector<std::string> invNames;

    invNames.push_back("AZAMAT");
    invNames.push_back("LEXA");
    invNames.push_back("VITYAI");
    invNames.push_back("AGUZOK");
    invNames.push_back("TOLYAN");
    invNames.push_back("JESSI");

  
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

   
    person.SetInvalideNames(invNames);
    person.SetName("John");
    person.SetNickname("JESSI");
    person.SetSurname("Smith");
    person.SetPatronym("Smithovich");
    person.SetAge(30);
    person.SetGender(rand() %2);
    person.SetRace("Lizardman");
    person.SetGrowth(180.25);
    person.SetWeight(80.2);
    person.SetMainActivity("Programmer");
    person.SetPhysConditions(conditions);
    person.SetName("AGUZOK");
  

	cout << "Current conditions bitfield: " << conditions << endl;
	cout << "Current conditions in binary: ";
    cout << std::bitset<sizeof(conditions)*8>(conditions) << endl;
    cout << "Physical condition: "  << person.GetPhysConditions() << endl;
    cout << "Name: "                << person.GetName() << endl;
    cout << "Nickname: "            << person.GetNickname() << endl;
    cout << "Invalid name: "        << person.GetInvalidName() << endl;
    cout << "Surname: "             << person.GetSurname() << endl;
    cout << "Patronym: "            << person.GetPatronym() << endl;
    cout << "Age: "                 << person.GetAge() << endl;

    if (person.GetGender())
        cout << "Gender: " << "Man" << endl;
    else
		cout << "Gender: " << "Woman" << endl;

    cout << "Race: "               << person.GetRace()<< endl;
    cout << "Growth: "             << person.GetGrowth() << endl;
    cout << "Weight: "             << person.GetWeight() << endl;
    cout << "Main activity: "      << person.GetMainActivity() << endl;
    cout << "Current coordinates: "
         << person.GetCurrentCoordinates3d().x << ", "
         << person.GetCurrentCoordinates3d().y << ", "
         << person.GetCurrentCoordinates3d().z << endl;

    return 0;
}