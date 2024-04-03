#ifndef PROFESSOR_HPP
# define PROFESSOR_HPP

class Course;
class Headmaster;

# define MANDATORY_NUMBER_OF_CLASSES 12 // mandatory or min number of classes per course
# define MAX_NUMBER_OF_CLASSES 15 // max number of classes per course

# include "Staff.hpp"
# include "observer.hpp"

// the Professor and the Student modules are decoupled using the mediator design pattern

class Professor : public Staff, public BellObserver {
    private:
        int         numberOfClasses;// the number of classes that a student needs to attend
        // in order to graduate the course.
        int         numberOfDoneClasses; // the number of classes done so far by the prof
        Course      *_currentCourse;
        Headmaster  *headmaster;// mediator
        Room        *lastAttendedClassroom;

    public:
        Professor(std::string &p_name, Headmaster *headmaster) : Staff(p_name), numberOfClasses(MANDATORY_NUMBER_OF_CLASSES), \
            numberOfDoneClasses(0), _currentCourse(NULL), headmaster(headmaster) {}

    private:
        static bool is_classroom_and_empty(Room *room);
        void requestNewClassroomCreation();// request a new class creation from the headmaster

    public:
        void assignCourse(Course *p_course);
        void doClass();
        void closeCourse();
        void requestCourseCreation(int _minimumGradeToGraduate, \
            int _maximumNumberOfStudents, const std::string &courseName); // request a course creation from the headmaster

    public:
        int getNumberOfClasses() const;
        void setNumberOfClasses(int numberOfClasses);

    public:
        Room *findFreeRoom();

    public:
        virtual void pauseStarts();
        virtual void pauseOver();
};

#endif