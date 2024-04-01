#ifndef ROOM_HPP
# define ROOM_HPP

# include <iostream>
# include <vector>

class Person;

class Room {
	private:
		long long ID;
		std::vector<Person*> _occupants;

	public:
		Room();

	public:
		bool canEnter(Person *person);
		void enter(Person *person);
		void exit(Person *person);
		void printOccupant() const;
};

#endif