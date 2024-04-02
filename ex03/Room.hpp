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
		Room() {
			static long long count = 0;

    		this->ID = count++;
		}
		virtual ~Room() {}

	public:
		bool is_free() const;
		virtual bool canEnter(Person *person) const;
		void enter(Person *person);
		void exit(Person *person);
		void printOccupant() const;
};

#endif