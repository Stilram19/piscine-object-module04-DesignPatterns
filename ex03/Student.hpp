#ifndef STUDENT_HPP
# define STUDENT_HPP

class Course;
class Classroom;
class Headmaster;

# include "Person.hpp"
# include <map>

class Student : public Person {
    private:
        int passedCoursesCount;
        Headmaster *headmaster;
        std::map<Course*, int> _subscribedCourse; // mapping the course to the number of
        // times the student attended the course class.

    public:
        Student(Headmaster *headmaster, std::string &p_name) : Person(p_name), passedCoursesCount(0), \
            headmaster(headmaster) {}

    private:
        bool is_subscribed(Course *p_course) const;
        void erase_course(Course *p_course);

    public:
        void attendClass(Classroom *p_classroom);
        void exitClass();
        void graduate(Course *p_course); // pass or finish the given course
        void fail(Course *p_course); // fail the given course
        void subscribe(Course *p_course);

    public:
        int getPassedCoursesCount() const;
        int getNumberOfAttendedClasses(Course *course);
};

#endif