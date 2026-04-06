#include "GodObjectPerson.h"



Person::Person()
{

}

Person::~Person()
{

}


int Person::SetName(const std::string& name, const std::vector<std::string>& invNames)
{
	if (name.empty())									//if name empty - just return error int number means name is empty;
		return nameIsEmpty;

	for (const auto& worngName : invNames)				//cycle to check elements of invalidateName; auto is:	std::vector<std::string>::const_iterator::value_type = std::string; 
	{
		if (name == worngName)
		{
			Person::InvalidName = worngName;
			return invalidName;							//return error code if invalide name
		}
				
	}
	Person::Name = name;								//explicit assignment of name
	return 0;											//if all good
}



void Person::SetRandomConditions()						//set both mental and phys RAND 										
{
	trueRandom(physConditionsMask);
	trueRandom(mentalConditionsMask);
}

void Person::SetRandomPhysConditions()					//set phys RAND 
{
	trueRandom(physConditionsMask);
}

void Person::SetRandomMentalConditions()				//set mental RAND
{
	trueRandom(mentalConditionsMask);
}


