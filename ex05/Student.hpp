#ifndef STUDENT_HPP
# define STUDENT_HPP

class Course;
class Classroom;
class Headmaster;

# include "observers.hpp"
# include "Person.hpp"
# include <map>

// the Professor and the Student modules are decoupled using the mediator design pattern

class Student : public BreakBellObserver, public LunchBellObserver, public GraduationBellObserver {
    private:
        int passedCoursesCount;
        Headmaster *headmaster;
        std::map<Course*, int> _subscribedCourse; // mapping the course to the number of
        // times the student attended the course class.

    public:
        Student(Headmaster *headmaster, std::string &p_name) : Person(p_name),\
            BellObserver(p_name), \
            BreakBellObserver(p_name, "Student"), LunchBellObserver(p_name, "Student"), \
            GraduationBellObserver(p_name), passedCoursesCount(0), \
            headmaster(headmaster) {}

        ~Student() {}

    private:
        void erase_course(Course *p_course);

    public:
        void attendClass(Classroom *p_classroom);
        void exitClass();
        void graduate(Course *p_course); // pass or finish the given course
        void fail(Course *p_course); // fail the given course
        void subscribe(Course *p_course);

    public:
        bool is_subscribed(Course *p_course) const;
        int getPassedCoursesCount() const;
        int getNumberOfAttendedClasses(Course *course);
        int getCoursesCount() const;

    // implementing the GraudationBellObserver
    public:
        void prepareForGraduation();
};

#endif