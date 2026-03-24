/**
 *       █████████               █████
 *      ███░░░░░███             ░░███
 *     ███     ░░░   ██████   ███████
 *    ░███          ███░░███ ███░░███
 *    ░███    █████░███ ░███░███ ░███
 *    ░░███  ░░███ ░███ ░███░███ ░███
 *     ░░█████████ ░░██████ ░░████████
 *      ░░░░░░░░░   ░░░░░░   ░░░░░░░░
 *
 *
 *
 *        ███████    █████          ███                     █████
 *      ███░░░░░███ ░░███          ░░░                     ░░███
 *     ███     ░░███ ░███████      █████  ██████   ██████  ███████
 *    ░███      ░███ ░███░░███    ░░███  ███░░███ ███░░███░░░███░
 *    ░███      ░███ ░███ ░███     ░███ ░███████ ░███ ░░░   ░███
 *    ░░███     ███  ░███ ░███     ░███ ░███░░░  ░███  ███  ░███ ███
 *     ░░░███████░   ████████      ░███ ░░██████ ░░██████   ░░█████
 *       ░░░░░░░    ░░░░░░░░       ░███  ░░░░░░   ░░░░░░     ░░░░░
 *                             ███ ░███
 *                            ░░██████
 *                             ░░░░░░
 *     ███████████
 *    ░░███░░░░░███
 *     ░███    ░███  ██████  ████████   █████   ██████  ████████
 *     ░██████████  ███░░███░░███░░███ ███░░   ███░░███░░███░░███
 *     ░███░░░░░░  ░███████  ░███ ░░░ ░░█████ ░███ ░███ ░███ ░███
 *     ░███        ░███░░░   ░███      ░░░░███░███ ░███ ░███ ░███
 *     █████       ░░██████  █████     ██████ ░░██████  ████ █████
 *    ░░░░░         ░░░░░░  ░░░░░     ░░░░░░   ░░░░░░  ░░░░ ░░░░░
 *
 *
 *
 */

 /*----------------------------------------------PREPROCESSOR BLOCK------------------------------------*/
#pragma once
#ifndef _GODOBJECTPERSON_ 
#define _GODOBJECTPERSON_

/*----------------------------------------------DEFINE BLOCK------------------------------------------*/
#define uint unsigned int						//to shorten code, because this class has a lot of uint variables

/*----------------------------------------------INCLUDES BLOCK----------------------------------------*/
#include <string>
#include <cstdint>
#include "includes/magic_enum/magic_enum.hpp"	//free lib on github https://github.com/Neargye/magic_enum/releases/tag/v0.9.7

/*----------------------------------------------COLOSSAL-CLASS----------------------------------------*/
class GodObjectPerson
{
public:
	GodObjectPerson();							//default constructor
	~GodObjectPerson();							//default destructor

	/*------------------------------------------SETTERS-----------------------------------------------*/
	void SetName(const std::string& name) { fullname_.name = name; }
	void SetSurname(const std::string& surname) { fullname_.surname = surname; }
	void SetPatronym(const std::string& patronym) { fullname_.patronym = patronym; }

	void SetID(const uint id) { const_cast<uint&>(Id) = id; }
	void SetAge(const uint age) { const_cast<uint&>(Age) = age; }
	void SetGrowth(const uint growth) { Growth = growth; }
	void SetWeight(const uint weight) { Weight = weight; }
	void SetGender(const bool gnd) { const_cast<bool&>(Gender) = gnd; }
	void SetRace(const std::string& race) { Race = race; }
	void SetMainActivity(const std::string& activity) { MainActivity = activity; }



	void SetDateOfBirth(const uint day, const uint month, const int year)			//setting date of birth just by values
	{
		dateOfBirth_.day = day;
		dateOfBirth_.month = month;
		dateOfBirth_.year = year;
	}

	void SetPhysConditions(const uint32_t conditionBitField)						//setting physConditiones just by value
	{
		physConditionesBF = conditionBitField;
	}

	void SetRandomConditions(uint32_t& cond)										//setting random physConditiones for testing purposes or any other reason
	{
		cond = 0;						// 0 initially means that all conditions are false
		for (int i = 0; i < 31; ++i)
		{
			if (std::rand() % 2)		// randomly set each bit with 50% chance
			{
				cond |= (1u << i);		// set the i-th bit to 1
			}
		}
		physConditionesBF = cond;		// assign the generated bitfield to the class member
	}

	void SetCurrentCoordinates(const float x, const float y, const float z)			//simple setter for current coordinates of person in 3D space
	{
		currCoord_.x = x;
		currCoord_.y = y;
		currCoord_.z = z;
	}

	/*----------------------------------------------GETTERS-----------------------------------------*/
	/*---STRINGS---*/
	std::string GetName() const { return fullname_.name; }					//returning name from struct
	std::string GetSurname() const { return fullname_.surname; }			//returning surname from struct
	const std::string GetPatronym() const { return fullname_.patronym; }	//returning patronym from struct, can be empty
	const std::string GetMainActivity() const { return MainActivity; }
	const std::string GetRace() const { return Race; }

	/*---INTS---*/
	uint GetID() const { return Id; }
	uint GetAge() const { return Age; }
	uint GetGrowth() const { return Growth; }
	uint GetWeight() const { return Weight; }
	auto& GetPhysConditions() const { return physConditionesBF; }			//returning bitfield for physConditiones. auto& is used to futhurer modify bitfield

	/*---BOOLS---*/
	bool GetGender() const { return Gender; }

	/*---STRUCTS---*/
	auto& GetDateOfBirth() const { return dateOfBirth_; }
	auto& GetCurrentCoordinates() const { return currCoord_; }

	/*----------------------------------------------METHODS-----------------------------------------*/




	/*----------------------------------------------ENUMS----------------------------------------------*/
	enum physConditiones						//for setting phys bitfield based on enum value
	{
		isHealthy = (1u << 0),
		isSick = (1u << 1),
		isInjured = (1u << 2),
		isDead = (1u << 3),
		isTired = (1u << 4),
		isRested = (1u << 5),
		isDrunk = (1u << 6),
		isSober = (1u << 7),
		isBleeding = (1u << 8),
		isInPain = (1u << 9),
		isHungry = (1u << 10),
		isThirsty = (1u << 11),
		isPoisoned = (1u << 12),
		isRadiated = (1u << 13),
		isInfected = (1u << 14),
		isCured = (1u << 15)
	} pCond_;

	enum mentalConditiones						//for setting mental bitfield based on enum value
	{
		isHappy = (1u << 0),
		isSad = (1u << 1),
		isAngry = (1u << 2),
		isCalm = (1u << 3),
		isAnxious = (1u << 4),
		isConfident = (1u << 5),
		isScared = (1u << 6),
		isBrave = (1u << 7),
		isHysteri = (1u << 8),
		isBerserk = (1u << 9),
		isBored = (1u << 10),
		isInterested = (1u << 11),
		isFocused = (1u << 12),
		isDistracted = (1u << 13),
		isDepressed = (1u << 14)
	}mCond_;

	/*----------------------------------------------BOOLS---------------------------------------------*/
	bool* physConditionesPtr = reinterpret_cast<bool*>(&physConditionesBF);		//pointer for bitfield
	bool* mentalConditionPtr = reinterpret_cast<bool*>(&mentalConditionesBF);	//pointer for bitfield

	bool comparePhysConditiones(const uint32_t conditiones) const				//comparing current physConditiones with incoming conditions, return true if they are the same
	{
		return (physConditionesBF == conditiones);
	}

	/*----------------------------------------------PRIVATE BLOCK-------------------------------------*/
private:
	const uint Id{};							//for autoincrement with each new person created
	const uint Age{};							//age in years
	const bool Gender{};						//ture - man, false - woman
	uint Growth{};								//in cm
	uint Weight{};								//in kg

	std::string Race;							//Race of person
	std::string MainActivity;					//Desctiption of main activity of person

	struct FullName								//struct for Full name of person
	{
		std::string name;
		std::string surname;
		std::string patronym;					//can be empty, because not all cultures have patronym
	}fullname_{};

	struct dateOfBirth							//struct for date of birth of person
	{
		uint day;
		uint month;
		int year;								//year can be negative for people born before common era, like Cesar, Diogenes, etc.
	}dateOfBirth_{};

	struct currentCoordinates					//struct for current coordinates of person in 3D space
	{
		float x;
		float y;
		float z;
	}currCoord_{};

	struct PhysAttributes						//struct for phys attributes of person
	{

	}physAttributes_{};

	struct MentalAttributes						//struct for mental attributes of person
	{

	}mentalAttributes_{};

	uint32_t physConditionesBF{};				//bitfield for current physConditiones state; uint32_t guarantees to be 32bit
	uint32_t mentalConditionesBF{};				//bitfield for current mentalConditiones

};

#endif // !_GODOBJECTPERSON_

