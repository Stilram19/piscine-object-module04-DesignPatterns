#ifndef COURSE_LIST_HPP
# define COURSE_LIST_HPP

class Course;
class Room;
class Staff;
class Student;

// having all the singletons declared in one module is not good for design.
// but that's what the subject asked for.

# include "List.hpp"

// the repitition seen in the static get_instance functions is mandatory
// no instance can be created outside of the singletons definition

class CourseList : public List<Course> {
    // making it impossible to instantiate objects from outside the class definition
    // to adhere to the Singleton design pattern
    private:
        CourseList() {}
        CourseList(const CourseList &);

    public:
        ~CourseList() {}

    public:
        // returns the only and only instance in the program
        static CourseList &get_instance() {
            static CourseList instance;

            return (instance);
        }
};

class RoomList : public List<Room> {
    // making it impossible to instantiate objects from outside the class definition
    // to adhere to the Singleton design pattern
    private:
        RoomList() {}
        RoomList(const RoomList &);

    public:
        ~RoomList() {}

    public:
        // returns the only and only instance in the program
        static RoomList &get_instance() {
            static RoomList instance;

            return (instance);
        }
};

class StaffList : public List<Staff> {
    // making it impossible to instantiate objects from outside the class definition
    // to adhere to the Singleton design pattern
    private:
        StaffList() {}
        StaffList(const StaffList &);

    public:
        ~StaffList() {}
    public:
        // returns the only and only instance in the program
        static StaffList &get_instance() {
            static StaffList instance;

            return (instance);
        }
};

class StudentList : public List<Student> {
    // making it impossible to instantiate objects from outside the class definition
    // to adhere to the Singleton design pattern
    private:
        StudentList() {}
        StudentList(const StudentList &);

    public:
        ~StudentList() {}

    public:
        // returns the only and only instance in the program
        static StudentList &get_instance() {
            static StudentList instance;

            return (instance);
        }
};

#endif
