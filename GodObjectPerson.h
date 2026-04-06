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
using uint = unsigned int;						//to shorten code, because this class has a lot of uint variables

/*----------------------------------------------INCLUDES BLOCK----------------------------------------*/
/*---STL---*/
#include <string>								//
#include <cstdint>								//for uint32_t
#include <random>
#include <climits>
#include <stdexcept>							//for throw
#include <algorithm>

/*---Custom/shared lib---*/
#include "includes/magic_enum/magic_enum.hpp"	//to count emum elements; free lib on github https://github.com/Neargye/magic_enum/releases/tag/v0.9.7

/*----------------------------------------------COLOSSAL-CLASS----------------------------------------*/
class Person
{
public:
	Person();									//default constructor
	~Person();									//default destructor

	

	/*------------------------------------------SETTERS-----------------------------------------------*/
	/*---STRINGS---*/
	
	/*Default setters without some checking variable stuff*/
	void SetName(const std::string& name)						{ Name = name; }					//default set name without checking																								
	void SetNickname(const std::string& nickName)				{ NickName = nickName; }			//set nickname	
	void SetSurname(const std::string& surname)					{ Surname = surname; }				//set surname
	void SetPatronym(const std::string& patronym)				{ Patronym = patronym; }			//set patronym
	void SetRace(const std::string& race)						{ Race = race; }					//set race
	void SetMainActivity(const std::string& activity)			{ MainActivity = activity; }		//set mainactivity
	void SetProfession(const std::string& profession)			{ Profession = profession; }		//set profession
	void SetHobbie(const std::string& hobbie)					{ Hobbie = hobbie; }				//set hobbie
	void SetCharacter(const std::string& character)				{ Character = character; }			//set character of person
	void SetFullName(const std::string& name, const std::string& surname, const std::string& patronym)	//setting full name just by values. without checks;
	{
		SetName(name); SetSurname(surname); SetPatronym(patronym);
	}

	/*func++*/
	
	int  SetName(const std::string& name, const std::vector<std::string>& invNames);				//setting name with check and return error code if not good, if 0 - good; it realise in.cpp file
	void SetInvalideName(const std::string invName)				{ InvalidName = invName; }			//set invalide name
	void SetInvalideNames(const std::vector<std::string> names)										//set vector of invalid names
	{ 
		for (auto& invName : names) InvalidNamesVec.push_back(invName); 
	} 

	/*---INTS---*/  
	void SetID(uint id)					{ Id = id; }												//Set person ID; i guess this only 1 way to get only const uint; but you can override it		
	void SetAge(uint age)				{ Age = age; }												//Set person Age; same as id
	void SetGrowth(const auto growth)	{ Growth = static_cast<float> (growth); }					//Setup growth; static_cast to avoid UB
	void SetWeight(const auto weight)	{ Weight = static_cast<float> (weight); }					//Setup weight; static_cast to avoid UB
	void SetPhysConditions(auto& conditionBitField) { physConditionsMask = conditionBitField; }		//Set conditiones bitfield

	/*---BOOLS---*/
	void SetGender(const bool gnd) { const_cast<bool&>(Gender) = gnd; }								//setting gender


	void SetDateOfBirth(const uint day, const uint month, const int year)							//setting date of birth just by values
	{
		birth_date.day = day;
		birth_date.month = month;
		birth_date.year = year;
	}

	/*---STRUCTS---*/
	

	/*----------------------------------------------GETTERS-----------------------------------------*/
	/*---STRINGS---*/
	const std::string GetName()						{ return Name; }						//returning name
	const std::string GetSurname()					{ return Surname; }						//returning surname
	const std::string GetPatronym()					{ return Patronym; }					//returning patronym
	const std::string GetNickname()					{ return NickName; }					//returning nickname
	const std::string GetMainActivity()				{ return MainActivity; }				//return MainActivity
	const std::string GetRace()						{ return Race; }						//return Race
	const std::string GetInvalidName()				{ return InvalidName; }					//return single invalid name
	auto& GetInvalideNames()						{ return InvalidNamesVec; }				//return vector of invalide names


	/*---INTS---*/
	uint GetID()									{ return Id; }							//return ID
	uint GetAge()									{ return Age; }							//return Age
	float GetGrowth()								{ return Growth; }						//return Griwth
	float GetWeight()								{ return Weight; }						//return Weight
	auto& GetPhysConditions()						{ return physConditionsMask; }			//returning bitfield for physConditions. auto& is used to futhurer modify bitfield
	auto& GetMentalConditions()						{ return mentalConditionsMask; }		//return mentalCond bitfield; same for physConditions

	/*---BOOLS---*/
	bool GetGender()								{ return Gender; }						//i guess it returned sex

	/*---STRUCTS---*/
	auto& GetDateOfBirth()							{ return birth_date; }					//return struct of date of birth
	auto& GetCurrentCoordinates3d()					{ return coord3d; }						//return struct of current 3d coord of person
	auto& GetCurrentCoordinates2d()					{ return coord2d; }						//return struct of current 2d coord of person

	/*----------------------------------------------METHODS-------------------------------------------*/

	//comparing current physConditions with incoming conditions
	//bool comparePhysConditiones(const auto conditions) const { return conditions == physConditionsMask; }

	template<class T>
	void trueRandom(T& value)															//a simple template functon to get a good random number, and to have possibility accept many int types coz template T;
	{
		static std::mt19937 gen(std::random_device{}());								//well, if you will try to put some another type it will work, but why. What expect?
		uint64_t val = (static_cast<uint64_t>(gen()) << 32) | gen();
		value = std::decay_t<T>(static_cast<T>(val));
	}

	//easy to delete block, it can be useful, but yeah: additional bytes and managment;
	void SetRandomConditions();															//setting random all conditiones for testing purposes or any other reason
	void SetRandomPhysConditions();														//randomizing phys conditiones
	void SetRandomMentalConditions();													//randomizing phys conditiones



	/*----------------------------------------------ENUMS---------------------------------------------*/
	typedef enum 							//for setting phys bitfield based on enum value. 
	{
		isHealthy		= (1u << 0),  isSick		= (1u << 1), isInjured		= (1u << 2), isDead			= (1u << 3),
		isTired			= (1u << 4),  isRested		= (1u << 5), isDrunk		= (1u << 6), isSober		= (1u << 7),
		isBleeding		= (1u << 8),  isInPain		= (1u << 9), isHungry		= (1u << 10), isThirsty		= (1u << 11),
		isPoisoned		= (1u << 12), isRadiated	= (1u << 13), isInfected	= (1u << 14), isCured		= (1u << 15)
	}physConditions;

	typedef enum 							//for setting mental bitfield based on enum value
	{
		isHappy			= (1u << 0), isAnxious		= (1u << 4), isHysteri		= (1u << 8),  isFocused		= (1u << 12),
		isSad			= (1u << 1), isConfident	= (1u << 5), isBerserk		= (1u << 9),  isDistracted	= (1u << 13),
		isAngry			= (1u << 2), isScared		= (1u << 6), isBored		= (1u << 10), isDepressed	= (1u << 14),
		isCalm			= (1u << 3), isBrave		= (1u << 7), isInterested	= (1u << 11),
	}mentalConditions;

	typedef enum 
	{
		invalidName = 1, nameOverflow, nameExist, nameNotExist, nameIsShort, nameIsWrong, nameContainWrongSymbol, nameIsEmpty
	}ErrorCodesForStrings;

	/*----------------------------------------------BOOLS---------------------------------------------*/
	
	

	/*----------------------------------------------PRIVATE BLOCK-------------------------------------*/
private:
	/*----------------------------------------------BASIC TYPES---------------------------------------*/
	uint Id{};											//for autoincrement with each new person created
	uint Age{};											//age in years
	bool Gender{};										//ture - man, false - woman
	float Growth{};										//float for growth in cm, because some people can be 180.5 cm, for example
	float Weight{};										//float for weight in kg, because some people can be 75.3 kg, for example

	uint64_t physConditionsMask{};						//bitfield (or modern: mask) for current physConditions state; _t is guarantee that is number_of_bits_t; you can use any what
	uint64_t mentalConditionsMask{};					//bitfield for current mentalConditions; 

	/*----------------------------------------------COMPLEX TYPES-------------------------------------*/
	//---STRINGS---//
	std::string Name;									//single string Name
	std::string Surname;								//single string Surname
	std::string Patronym;								//single string Patronym
	std::string NickName;								//nickname single string
	std::string Race;									//Race of person
	std::string MainActivity;							//Desctiption of main activity of person
	std::string Profession;								//Profession of person
	std::string Hobbie;									//Hobbie of person
	std::string Character;								//Character of person
	std::string InvalidName;							//single invalidate name. If you need to check some wrong names, can use this

	//---VECTOR STRINGS---//
	std::vector<std::string> InvalidNamesVec;			//vector of invalide names
	std::vector<std::string> InvalidSurnames;			//vector of invalide surnames
	std::vector<std::string> InvalidPatronyms;			//vector of invalide patronyms

	//---STRUCTS---//
	struct FullName										//struct for Full name of person, to work with struct instead of single field and have some struct mechanic
	{
		std::string name;
		std::string surname;
		std::string patronym;							//can be empty, because not all cultures have patronym
	}full_name{};										//field of full name
	 								

	struct DateOfBirth									//struct for date of birth of person
	{
		uint day;
		uint month;
		int year;										//year can be negative for people born before common era, like Cesar, Diogenes, etc.
	}birth_date{};										//field of DateOfBirth

	struct Coord3D										//struct for coordinates of person in 3D space
	{
		float x;
		float y;
		float z;
	}coord3d{};											//field of 3D coordinates	

	struct Coord2D										//struct of 2d coords
	{
		float x;
		float y;
	}coord2d{};											//field of 2d coordiates

	struct PhysAtt										//struct for phys attributes of person (STR, DEX, VIT e.t.c)
	{

	}phys_att{};										//field of Phys Attributes

	struct MentalAtt									//struct for mental attributes of person (INT, PIETY, WILL, SENSE e.t.c)
	{

	}mental_att{};										//field of mental attributes

};

#endif // !_GODOBJECTPERSON_

