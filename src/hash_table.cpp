#include "hash_table.h"
#include <string>

int main(void){

	hash_table<std::string> table;

	if(table.empty())
		std::cout << "Hash_table vuota!" << std::endl;
	else
		std::cout << table << std::endl;

	table.insert("albinoni","tommaso");
	table.insert("offenbach","jacques");
	table.insert("palestrina","giovanni");
	table.insert("prokofev","sergej");
	table.insert("puccini","giacomo");
	//table.insert("rossini","gioachino");

	std::cout << table << std::endl;

	std::cout << "contains 'albinoni': " << table.contains("albinoni") << std::endl;
	//std::cout << "contains 'rossini': " << table.contains("rossini") << std::endl;
	std::cout << "contains 'rossi': " << table.contains("rossi") << std::endl;
	std::cout << "find 'albinoni': " << table.find("albinoni") << std::endl;
	//std::cout << "find 'rossi': " << table.find("rossi") << std::endl; //key does not exist


	hash_table<std::string> table2(table);
	std::cout << "erase 'albinoni'" << std::endl;
	table2.erase("albinoni");
	std::cout << "modify 'palestrina'" << std::endl;
	table2.modify("palestrina","name");
	std::cout << table2 << std::endl;

	std::cout << table<< std::endl;
}
