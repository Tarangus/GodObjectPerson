#include "GodObjectPerson.h"
#include <random>
#include <climits>


Person::Person()
{

}

Person::~Person()
{

}


template<class T>
void Person::trueRandom(T& value)							//a simple template functon to get a good random number, and to have possibility accept many int types coz template T;
{
	static std::mt19937 gen(std::random_device{}());	
	uint64_t val = (static_cast<uint64_t>(gen()) << 32) | gen();
	value = std::decay_t<T>(static_cast<T>(val));
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
	trueRandom(physConditionsMask);
	trueRandom(mentalConditionsMask);
}

void Person::SetRandomPhysConditions()
{
	trueRandom(physConditionsMask);
}

void Person::SetRandomMentalConditions()
{
	trueRandom(mentalConditionsMask);
}


