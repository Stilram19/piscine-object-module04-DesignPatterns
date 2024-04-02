#ifndef SUBSCRIPTION_TO_COURSE_FORM_HPP
# define SUBSCRIPTION_TO_COURSE_FORM_HPP

class Student;
class Course;

# include "Form.hpp"

// This class is a concrete Command, implementing the Command "Form"

class SubscriptionToCourseForm : public Form {
    private:
        Student *student;
        Course *course; // the receiver in this context (it means the Course knows how
        // execute this concrete command)

    public:
        SubscriptionToCourseForm() : Form(SubscriptionToCourse) ,student(NULL), course(NULL) {}

    public:
        virtual void execute();
        void fill_in(Student *student, Course *course);
};

#endif