#include "GodObjectPerson.h"
#include <iostream>
#include <cstdlib> // rand() и srand()
#include <bitset>  // convert uint32_t to binary string


using namespace std;

uint32_t getuint32(char* p) 
{
	return (*p << 24) | (*(p + 1) << 16) | (*(p + 2) << 8) | (*(p + 3)); //???????????????
}

int main()
{
	Person person;

	//imitation of incoming data
	std::vector<std::string> invNames;

	enum x {ha,b,c} x_;
	person.trueRandom(x_);	//possible, but why and what an expectations? idk

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
	person.SetGender(rand() % 2);
	person.SetRace("Lizardman");
	person.SetGrowth(180.25);
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

	cout << "----STRINGS----"		<< endl;
	cout << "Name:          "		<< person.GetName()				<< endl;
	cout << "Nickname:      "		<< person.GetNickname()			<< endl;
	cout << "Invalid name:  "		<< person.GetInvalidName()		<< endl;
	cout << "Surname:       "		<< person.GetSurname()			<< endl;
	cout << "Patronym:      "		<< person.GetPatronym()			<< endl << endl;

	cout << "Age: " << person.GetAge() << endl;

	if (person.GetGender())
		cout << "Gender: " << "Man" << endl;
	else
		cout << "Gender: " << "Woman" << endl;

	cout << "Race:          "		<< person.GetRace()				<< endl;
	cout << "Growth:        "		<< person.GetGrowth()			<< endl;
	cout << "Weight:        "		<< person.GetWeight()			<< endl;
	cout << "Main activity: "		<< person.GetMainActivity()		<< endl << endl;

	cout	<< "current coordinates: "
			<< person.GetCurrentCoordinates3d().x << ", "
			<< person.GetCurrentCoordinates3d().y << ", "
			<< person.GetCurrentCoordinates3d().z << endl;

	return 0;
}