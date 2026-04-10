#include "GodObjectPerson.h"
#include <iostream>
#include <cstdlib> // rand() и srand()
#include <bitset>  // convert uint32_t to binary string

using namespace std;

signed main()
{
	Person person;

	std::vector<std::string> invNames;

	invNames.push_back("AZAMAT");
	invNames.push_back("LEXA");
	invNames.push_back("VITYAI");
	invNames.push_back("AGUZOK");
	invNames.push_back("TOLYAN");
	invNames.push_back("JESSIE");

	person.SetName("LEXA");
	person.SetNickname("IMPRESSIVE");
	person.SetSurname("BARANOV");
	person.SetPatronym("BATKOVICH");
	person.SetAge(rand());
	person.SetRace("Lizardman");
	person.SetHeight(180.25);
	person.SetWeight(80.2);
	person.SetMainActivity("Programmer");
	person.SetName("AGUZOK", invNames);

	
	cout << "----Conditiones----" << endl;

	auto tmpSetpCond = 42;
	person.SetPhysConditions(tmpSetpCond);
	cout << "SetPhysConditions:   "				<< person.GetPhysConditions() << endl;

	person.SetRandomConditions();
	cout << "Randomed Physical condition:  "	<< person.GetPhysConditions() << endl;

	cout << "Randomed Mental condition:    "	<< person.GetMentalConditions() << endl;

	auto pConditions = person.GetPhysConditions();
	auto mConditions = person.GetMentalConditions();

	cout << "Current conditiones in binary: " << endl;
	cout << "   Phys binary:    "	<<  std::bitset<sizeof(pConditions) * 8>(pConditions) << endl;
	cout << "   Mental binary:  "	<<  std::bitset<sizeof(mConditions) * 8>(mConditions) << endl;
	cout << "   Flip phys:      "	<< ~std::bitset<sizeof(pConditions) * 8>(pConditions) << endl;
	cout << "   Flip mental:    "	<< ~std::bitset<sizeof(mConditions) * 8>(mConditions) << endl;

	cout << "----STRINGS----"										<< endl;
	cout << "Name:          "		<< person.GetName()				<< endl;
	cout << "Nickname:      "		<< person.GetNickname()			<< endl;
	cout << "Invalid name:  "		<< person.GetInvalidName()		<< endl;
	cout << "Surname:       "		<< person.GetSurname()			<< endl;
	cout << "Patronym:      "		<< person.GetPatronym()			<< endl << endl;

	cout << "Age:           "		<< person.GetAge()				<< endl;
	cout << "Gender:        "		<< person.GetGenderStr()		<< endl;
	cout << "Race:          "		<< person.GetRace()				<< endl;
	cout << "Growth:        "		<< person.GetHeight()			<< endl;
	cout << "Weight:        "		<< person.GetWeight()			<< endl;
	cout << "Main activity: "		<< person.GetMainActivity()		<< endl << endl;

	cout	<< "current coordinates: "
			<< person.GetCurrentCoordinates3d().x << ", "
			<< person.GetCurrentCoordinates3d().y << ", "
			<< person.GetCurrentCoordinates3d().z << endl;

	return 0;
}