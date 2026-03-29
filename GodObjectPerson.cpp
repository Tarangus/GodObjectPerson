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

	for (const auto& invalidateName : invNames)			//cycle to check elements of invalidateName
	{
		if (name == invalidateName)
		{
			Person::InvalidName = invalidateName;
			return invalidName;							//retunr error code if invalide name
		}
				
	}
	Person::Name = name;								//explicit assignment of name
	return 0;											//if all good
}


void Person::SetRandomConditions()
{
	uint32_t cond = 0;				
	for (int i = 0; i < 31; ++i)	//32 coz uint32. if 64 then 63 e.t.c
	{
		if (std::rand() % 2)		//randomly set each bit
		{
			cond |= (1u << i);		//set the i-th bit to 1
		}
	}
	physConditionesBF = cond;		//set the generated bitfield
}


