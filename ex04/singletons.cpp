# include "singletons.hpp"
# include "Course.hpp"
# include "Room.hpp"
# include "Staff.hpp"
# include "Student.hpp"

// this file was created to the decouple the Room.hpp, Staff.hpp, Student.hpp, Course.hpp
// from the singletons.hpp, because using the delete operator requires depending on the
// declaration of the type.

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
