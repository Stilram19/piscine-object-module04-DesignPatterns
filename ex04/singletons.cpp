# include "singletons.hpp"
# include "Course.hpp"
# include "Student.hpp"
# include "Room.hpp"
# include "Staff.hpp"

// This repitition is necessary, because if having a general destructor in the List template
// class requires making it depend on all of its derived classes, this violate
// the Open/Closed principle and will increase coupling between modules.

CourseList::~CourseList() {
    for (std::vector<Course *>::iterator item = this->items.begin(); item != this->items.end(); item++) {
        delete *item;
    }
}

RoomList::~RoomList() {
    for (std::vector<Room *>::iterator item = this->items.begin(); item != this->items.end(); item++) {
        delete *item;
    }
}

StaffList::~StaffList() {
    for (std::vector<Staff *>::iterator item = this->items.begin(); item != this->items.end(); item++) {
        delete *item;
    }
}

StudentList::~StudentList() {
    for (std::vector<Student *>::iterator item = this->items.begin(); item != this->items.end(); item++) {
        delete *item;
    }
}
