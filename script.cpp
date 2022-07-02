/**
 * @file script.py
 * @author Daniel Park (danpark13@github.io)
 * @brief Calculate the Social and Legal Minimum Age to Date (SLMAD) as the elder in the relationship
 * @version 0.1
 * @date 2022-07-01
 *
 * Note: View full context of rules in the README.md
 *
 */
#include<math.h> 
#include<iostream>
using namespace std;
int main(){
	int user_age;
	std::cout << "Type in your legal age: ";
	std::cin >> user_age;

	while(std::cin.fail()){
		std::cout << "That is not a valid age. Please try again: ";
		std::cin.clear();
		std::cin.ignore(256,'\n'); // Clear current cin
		std::cin >> user_age;
	}

	double minimum_age;
	minimum_age = floor((user_age / 2) + 7);

	// If under 14, calculations go wonky but also under 14 year old children shouldn't be in a relationship (yet)
	if (user_age <= 14){
		std::cout << "Please enjoy your childhood before you start dating :(" << std::endl;
		return 0;
	}

	// Catch 'Under 18' Clause when over 18 and minimum_age calculates to under 18
	if (user_age >= 18 && minimum_age < 18){
		std::cout << "Although the calculation says " << minimum_age << ", since you are " << user_age << " and we do not want you to get in trouble with the authorities, your SLMAD is 18" << std::endl;
		return 0;
	}

	std::cout << "Since you are " << user_age << ", your SLMAD is " << minimum_age <<  std::endl;

	return 0;
}
