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
/*---STL---*/
#include <string>								//
#include <cstdint>								//for uint32_t	
/*---Custom/shared lib---*/
#include "includes/magic_enum/magic_enum.hpp"	//to count emum elements; free lib on github https://github.com/Neargye/magic_enum/releases/tag/v0.9.7

/*----------------------------------------------COLOSSAL-CLASS----------------------------------------*/
class Person
{
public:
	Person();							//default constructor
	~Person();							//default destructor

	/*------------------------------------------SETTERS-----------------------------------------------*/
	/*---STRINGS---*/
	void SetNickname(const std::string& nickName)				{ NickName = nickName; }			//set nickname
	void SetName(const std::string& name)						{ Name = name; }					//set name
	void SetSurname(const std::string& surname)					{ Surname = surname; }				//set surname
	void SetPatronym(const std::string& patronym)				{ Patronym = patronym; }			//set patronym
	void SetRace(const std::string& race)						{ Race = race; }					//set race
	void SetMainActivity(const std::string& activity)			{ MainActivity = activity; }		//set mainactivity
	void SetProfession(const std::string& profession)			{ Profession = profession; }		//set profession
	void SetHobbie(const std::string& hobbie)					{ Hobbie = hobbie; }				//set hobbie
	void SetCharacter(const std::string& character)				{ Character = character; }			//set character of person

	void SetFullName(const std::string& name, const std::string& surname, const std::string& patronym)	//setting full name just by values. if exception - gl;
	{
		SetName(name); SetSurname(surname); SetPatronym(patronym);
	}
	void SetInvalideName(const std::string invName)				{ InvalidName = invName; }			//set invalide name
	void SetInvalideNames(const std::vector<std::string> names)										//set vector of invalid names
	{ 
		for (auto& invName : names) InvalidNames.push_back(invName); 
	} 

	/*---INTS---*/  
	void SetID(uint id)					{ Id = id; }												//Set person ID; i guess this only 1 way to get only const uint; but you can override it		
	void SetAge(uint age)				{ Age = age; }												//Set person Age; same as id
	void SetGrowth(const auto growth)	{ Growth = static_cast<float> (growth); }					//Setup growth; static_cast to avoid UB
	void SetWeight(const auto weight)	{ Weight = static_cast<float> (weight); }					//Setup weight; static_cast to avoid UB
	void SetPhysConditions(uint32_t conditionBitField) { physConditionesBF = conditionBitField; }	//Set conditiones bitfield

	/*---BOOLS---*/
	void SetGender(const bool gnd) { const_cast<bool&>(Gender) = gnd; }


	void SetDateOfBirth(const uint day, const uint month, const int year)			//setting date of birth just by values
	{
		dateOfBirth_.day = day;
		dateOfBirth_.month = month;
		dateOfBirth_.year = year;
	}

	/*---STRUCTS---*/
	void SetCurrentCoordinates3D(auto& str)			//simple setter for current coordinates of person in 3D space
	{
		currCoord3d_ = str;
	}

	/*----------------------------------------------GETTERS-----------------------------------------*/
	/*---STRINGS---*/
	const std::string GetName() const			{ return Name; }						//returning name
	const std::string GetSurname() const		{ return Surname; }						//returning surname
	const std::string GetPatronym() const		{ return Patronym; }					//returning patronym
	const std::string GetNickname() const		{ return NickName; }					//returning nickname
	const std::string GetMainActivity() const	{ return MainActivity; }				//return MainActivity
	const std::string GetRace() const			{ return Race; }						//return Race
	const std::string GetInvalidName() const	{ return InvalidName; }					//return single invalid name
	auto& GetInvalideNames() const				{ return InvalidNames; }				//return vector of invalide names


	/*---INTS---*/
	uint GetID() const					{ return Id; }
	uint GetAge() const					{ return Age; }
	float GetGrowth() const				{ return Growth; }
	float GetWeight() const				{ return Weight; }
	auto& GetPhysConditions() const		{ return physConditionesBF; }		//returning bitfield for physConditiones. auto& is used to futhurer modify bitfield
	auto& GetMentalConditions() const	{ return mentalConditionesBF; }		//return mentalCond bitfield; same for physConditioones

	/*---BOOLS---*/
	bool GetGender() const { return Gender; }

	/*---STRUCTS---*/
	auto& GetDateOfBirth() const			{ return dateOfBirth_; }		//return struct of date of birth
	auto& GetCurrentCoordinates3d() const	{ return currCoord3d_; }		//return struct of current 3d coord of person
	auto& GetCurrentCoordinates2d() const	{ return currCoord3d_; }		//return struct of current 2d coord of person

	/*----------------------------------------------METHODS-------------------------------------------*/

	bool comparePhysConditiones(const uint32_t conditiones) const {}			//comparing current physConditiones with incoming conditions
	
	void SetRandomConditions();													//setting random physConditiones for testing purposes or any other reason


	/*----------------------------------------------ENUMS---------------------------------------------*/
	enum physConditiones							//for setting phys bitfield based on enum value. 
	{
		isHealthy		= (1u << 0),  isSick		= (1u << 1), isInjured		= (1u << 2), isDead			= (1u << 3),
		isTired			= (1u << 4),  isRested		= (1u << 5), isDrunk		= (1u << 6), isSober		= (1u << 7),
		isBleeding		= (1u << 8),  isInPain		= (1u << 9), isHungry		= (1u << 10), isThirsty		= (1u << 11),
		isPoisoned		= (1u << 12), isRadiated	= (1u << 13), isInfected	= (1u << 14), isCured		= (1u << 15)
	};

	enum mentalConditiones							//for setting mental bitfield based on enum value
	{
		isHappy			= (1u << 0), isAnxious		= (1u << 4), isHysteri		= (1u << 8),  isFocused		= (1u << 12),
		isSad			= (1u << 1), isConfident	= (1u << 5), isBerserk		= (1u << 9),  isDistracted	= (1u << 13),
		isAngry			= (1u << 2), isScared		= (1u << 6), isBored		= (1u << 10), isDepressed	= (1u << 14),
		isCalm			= (1u << 3), isBrave		= (1u << 7), isInterested	= (1u << 11),
	};

	enum ErrorCodesForStrings
	{
		invalidName, nameOverflow, nameExist, nameNotExist, nameIsShort, nameIsWrong, nameContainWrongSymbol
	};

	/*----------------------------------------------BOOLS---------------------------------------------*/
	bool* physConditionesPtr = reinterpret_cast<bool*>(&physConditionesBF);		//pointer for bitfield
	bool* mentalConditionPtr = reinterpret_cast<bool*>(&mentalConditionesBF);	//pointer for bitfield

	

	/*----------------------------------------------PRIVATE BLOCK-------------------------------------*/
private:
	/*----------------------------------------------BASIC TYPES---------------------------------------*/
	uint Id{};									//for autoincrement with each new person created
	uint Age{};									//age in years
	bool Gender{};								//ture - man, false - woman
	float Growth{};								//float for growth in cm, because some people can be 180.5 cm, for example
	float Weight{};								//float for weight in kg, because some people can be 75.3 kg, for example

	uint32_t physConditionesBF{};				//bitfield for current physConditiones state; uint32_t guarantees to be 32bit
	uint32_t mentalConditionesBF{};				//bitfield for current mentalConditiones

	/*----------------------------------------------COMPLEX TYPES-------------------------------------*/
	//---STRINGS---//
	std::string Name;							//single string Name
	std::string Surname;						//single string Surname
	std::string Patronym;						//single string Patronym
	std::string NickName;						//nickname single string
	std::string Race;							//Race of person
	std::string MainActivity;					//Desctiption of main activity of person
	std::string Profession;						//Profession of person
	std::string Hobbie;							//Hobbie of person
	std::string Character;						//Character of person
	std::string InvalidName;					//single invalidate name. If you need to check some wrong names, can use this


	//---VECTOR STRINGS---//

	std::vector<std::string> InvalidNames;		//vector of invalide names
	std::vector<std::string> InvalidSurnames;	//vector of invalude surnames
	std::vector<std::string> InvalidPatronyms;	//vector of invalude patronyms


	//---STRUCTS---//
	struct FullName								//struct for Full name of person, to work with struct instead of single field and have some struct mechanic
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

	struct currentCoordinates3D					//struct for current coordinates of person in 3D space
	{
		float x;
		float y;
		float z;
	}currCoord3d_{};

	struct currentCoordinates2D
	{
		float x;
		float y;
	}currCoord2d_{};

	struct PhysAttributes						//struct for phys attributes of person (STR, DEX, VIT e.t.c)
	{

	}physAttributes_{};

	struct MentalAttributes						//struct for mental attributes of person (INT, PIETY, WILL, SENSE e.t.c)
	{

	}mentalAttributes_{};



};

#endif // !_GODOBJECTPERSON_

