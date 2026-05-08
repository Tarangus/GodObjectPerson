/**
 * @brief God object anti-pattern class.
 * @details Anti-pattern not means that you can write code badly. 
 *			But you can make a good realisation of your great class of everything; Because gods knowing everything
 *			 
 *
 * @author Victor Bersenev aka Tarangus 
 * @github https://github.com/Tarangus
 * @date 2026-04-10
 * @version 1.0
 */

 /*---------------------------------------------PREPROCESSOR BLOCK------------------------------------*/
#pragma once
#ifndef _GODOBJECTPERSON_ 
#define _GODOBJECTPERSON_

/*----------------------------------------------DEFINE BLOCK------------------------------------------*/
using uint = unsigned int;						// to shorten code, because this class has a lot of uint variables

/*----------------------------------------------INCLUDES BLOCK----------------------------------------*/
/*---STL---*/
#include <string>								// good std class to work with strings
#include <cstdint>								// for unsigned ints 8/16/32/64
#include <random>								// to create a template trueRandom func with good return number

/*---custom/shared lib---*/

/*----------------------------------------------COLOSSAL-CLASS----------------------------------------*/
class Person
{
/*----------------------------------------------PRIVATE BLOCK-----------------------------------------*/
private:
	/*------------------------------------------BASIC TYPES-------------------------------------------*/
	uint Id{};											// any object have id; {} - is default initialization.
	uint Age{};
	float Height{};										
	float Weight{};										

	uint16_t physConditionsMask{};						// bitfield
	uint16_t mentalConditionsMask{};
	
	/*------------------------------------------COMPLEX TYPES-----------------------------------------*/
	//---STRINGS---//
	std::string Name;									
	std::string Surname;								
	std::string Patronym;								// Patronym can be empty, be care
	std::string NickName;								
	std::string Race;									
	std::string MainActivity;							
	std::string Profession;								
	std::string Hobbie;									
	std::string Character;								
	std::string InvalidName;							// single invalidate name. If you need to check some wrong names, can use this

	//---VECTOR STRINGS---//
	std::vector<std::string> InvalidNamesVec;			
	std::vector<std::string> InvalidSurnames;			
	std::vector<std::string> InvalidPatronyms;			

	//---STRUCTS---//
	struct FullName										// struct for Full name of person, to work with struct instead of single field and have some struct mechanic
	{
		std::string name;
		std::string surname;
		std::string patronym;							// can be empty, because not all cultures have patronym
	}full_name{};										


	struct DateOfBirth
	{
		uint day;
		uint month;
		int year;										// year can be negative
	}birth_date{};										

	struct Coord3D										
	{
		float x;
		float y;
		float z;
	}coord3d{};	

	struct Coord2D
	{
		float x;
		float y;
	}coord2d{};											

	struct PhysAtt										// struct for phys attributes of person
	{

	}phys_att{};
	struct MentalAtt
	{

	}mental_att{};

public:
	Person();	
	~Person();	

	/*------------------------------------------SETTERS-----------------------------------------------*/
	/*---STRINGS---*/
	
	/*Default setters without some checking variable stuff*/
	void SetName(const std::string& name)						{ Name = name; }																							
	void SetNickname(const std::string& nickName)				{ NickName = nickName; }				
	void SetSurname(const std::string& surname)					{ Surname = surname; }				
	void SetPatronym(const std::string& patronym)				{ Patronym = patronym; }			
	void SetRace(const std::string& race)						{ Race = race; }					
	void SetMainActivity(const std::string& activity)			{ MainActivity = activity; }		
	void SetProfession(const std::string& profession)			{ Profession = profession; }		
	void SetHobbie(const std::string& hobbie)					{ Hobbie = hobbie; }				
	void SetCharacter(const std::string& character)				{ Character = character; }			
	void SetInvalidName(const std::string invName)				{ InvalidName = invName; }			

	/*Setters with some functional*/
	int  SetName(const std::string& name, const std::vector<std::string>& invNames);					// setting name with check and return error code if not good, if 0 - good; it realise in GodObjectPerson.cpp file
	void SetFullName(const std::string& name, const std::string& surname, const std::string& patronym)	// using single setters
	{
		SetName(name); SetSurname(surname); SetPatronym(patronym);
	}
	
	void SetInvalidNames(const std::vector<std::string> names)											// set vector of invalid names. income outside
	{ 
		for (auto& invName : names) InvalidNamesVec.push_back(invName); 
	} 

	/*---INTS---*/  
	void SetID(uint id)											{ Id = id; }						
	void SetAge(uint age)										{ Age = age; }					
	void SetHeight(auto height)									{ Height = height; }
	void SetWeight(auto weight)									{ Weight = weight; }

	void SetPhysConditions(auto& conditionBitField) { physConditionsMask = conditionBitField; }	

	auto SetGender(auto gender)
	{
		Gender = gender;
	}

	/*---STRUCTS---*/
	void SetDateOfBirth(const uint day, const uint month, const int year)								// setting date of birth just by values
	{
		birth_date.day = day;
		birth_date.month = month;
		birth_date.year = year;
	}

	/*----------------------------------------------GETTERS-----------------------------------------*/
	/*---STRINGS---*/
	const std::string GetName()						const		{ return Name; }						
	const std::string GetSurname()					const		{ return Surname; }						
	const std::string GetPatronym()					const		{ return Patronym; }					// returning patronym (can be empty, need to check)
	const std::string GetNickname()					const		{ return NickName; }				
	const std::string GetMainActivity()				const		{ return MainActivity; }				
	const std::string GetRace()						const		{ return Race; }						
	const std::string GetInvalidName()				const		{ return InvalidName; }	
	const auto& GetInvalidNames()					const		{ return InvalidNamesVec; }				// return vector of invalid names

	/*---INTS---*/
	uint GetID()									const		{ return Id; }							
	uint GetAge()									const		{ return Age; }							
	float GetHeight()								const		{ return Height; }						
	float GetWeight()								const		{ return Weight; }	
	
	const auto& GetPhysConditions()					const		{ return physConditionsMask; }			// returning bitfield for physConditions. auto& is used to futhurer modify bitfield
	const auto& GetMentalConditions()				const		{ return mentalConditionsMask; }		
	const auto& GetGender()							const		{ return Gender; }						

	/*---STRUCTS---*/
	const auto& GetDateOfBirth()					const		{ return birth_date; }
	const auto& GetCurrentCoordinates3d()			const		{ return coord3d; }						
	const auto& GetCurrentCoordinates2d()			const		{ return coord2d; }						

	/*----------------------------------------------METHODS-------------------------------------------*/


	const std::string GetGenderStr()const;																// check .cpp file

	template<class T>
	void TrueRandom(T& value)																			// a simple template functon to get a good random number
	{
		thread_local static std::mt19937 gen(std::random_device{}());								
		uint64_t val = (static_cast<uint64_t>(gen()) << 32) | gen();
		value = std::decay_t<T>(static_cast<T>(val));
	}
	template<typename T, typename RangeType>
	void TrueRandom(T& value, RangeType min, RangeType max)												// Universal template func with floating
	{
		thread_local static std::mt19937_64 gen(std::random_device{}());
		if constexpr (std::is_floating_point_v<T>)
		{
			std::uniform_real_distribution<T> dis(static_cast<T>(min), static_cast<T>(max));
			value = dis(gen);
		}
		else 
		{
			std::uniform_int_distribution<T> dis(static_cast<T>(min), static_cast<T>(max));
			value = dis(gen);
		}
	}
	//easy to delete block, it can be useful, but yeah: additional bytes and managment;
	void SetRandomConditions();																			// setting random all conditiones for testing purposes or any other reason
	void SetRandomPhysConditions();														
	void SetRandomMentalConditions();													

	/*----------------------------------------------ENUMS---------------------------------------------*/
	typedef enum GenderType 
	{ 
		Unknown,
		Male, 
		Female
	};	
	GenderType Gender{ GenderType::Unknown };

	typedef enum 							// for setting phys bitfield based on enum value. 
	{
		isHealthy		= (1u << 0),  isSick		= (1u << 1), isInjured		= (1u << 2), isDead			= (1u << 3),
		isTired			= (1u << 4),  isRested		= (1u << 5), isDrunk		= (1u << 6), isSober		= (1u << 7),
		isBleeding		= (1u << 8),  isInPain		= (1u << 9), isHungry		= (1u << 10), isThirsty		= (1u << 11),
		isPoisoned		= (1u << 12), isRadiated	= (1u << 13), isInfected	= (1u << 14), isCured		= (1u << 15)
	}physConditions;

	typedef enum 							// for setting mental bitfield based on enum value
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
};

#endif // !_GODOBJECTPERSON_

