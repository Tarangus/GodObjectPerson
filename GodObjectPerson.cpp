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

	if (isShort(name))  
		return nameIsShort;

	for (const auto& wrongName : invNames)
	{
		if (name == wrongName)
		{
			Person::InvalidName = wrongName;
			return invalidName;							//return error code if invalide name
		}
				
	}
	Person::Name = name;								//explicit assignment of name
	return 0;											//if all good
}



const std::string Person::GetGenderStr() const
{
	switch (Gender)
	{
		case 0: return "Unknown";
		case 1: return "Male";
		case 2: return "Female";
		default: return "NULL";
	}
}


