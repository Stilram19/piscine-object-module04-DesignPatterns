#ifndef PROFESSOR_HPP
# define PROFESSOR_HPP

class Course;
class Classroom;
class Headmaster;

# define MANDATORY_NUMBER_OF_CLASSES 12 // mandatory or min number of classes per course
# define MAX_NUMBER_OF_CLASSES 15 // max number of classes per course

# include "Staff.hpp"
# include "observers.hpp"

// the Professor and the Student modules are decoupled using the mediator design pattern

class Professor : public Staff, public BreakBellObserver, public LunchBellObserver, public GraduationBellObserver {
    private:
        int         numberOfClasses;// the number of classes that a student needs to attend
        // in order to graduate the course.
        int         numberOfDoneClasses; // the number of classes done so far by the prof
        Course      *_currentCourse;
        Headmaster  *headmaster;// mediator
        std::string courseName;// the course name that the professor is specialized in

    public:
        Professor(std::string &p_name, const std::string &courseName, Headmaster *headmaster) : Person(p_name), \
            BellObserver(p_name), Staff(p_name), BreakBellObserver(p_name, "Professor"), \
            LunchBellObserver(p_name, "Professor"), \
            GraduationBellObserver(p_name), numberOfClasses(MANDATORY_NUMBER_OF_CLASSES), \
            numberOfDoneClasses(0), _currentCourse(NULL), headmaster(headmaster), courseName(courseName) {
                if (courseName.empty()) {
                    throw std::runtime_error("CourseName can't be empty!");
                }
            }

    private:
        static bool is_classroom_and_empty(Room *room);
        void requestNewClassroomCreation();// request a new class creation from the headmaster

    public:
        void assignCourse(Course *p_course);
        void doClass();
        void closeCourse();
        void requestCourseCreation(); // request a course creation from the headmaster

    public:
        int getNumberOfClasses() const;
        void setNumberOfClasses(int numberOfClasses);
        Classroom *getCurrentClassroom() const;
        Course *getCurrentCourse() const;

    public:
        Room *findFreeRoom();

    // implementing the GraudationBellObserver
    public:
        void prepareForGraduation();
};

#endif