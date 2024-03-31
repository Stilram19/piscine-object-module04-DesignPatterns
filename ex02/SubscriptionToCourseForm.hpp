#ifndef SUBSCRIPTION_TO_COURSE_FORM_HPP
# define SUBSCRIPTION_TO_COURSE_FORM_HPP

class Student;
class Course;

# include "Form.hpp"

class SubscriptionToCourseForm : public Form {
    private:
        Student *student;
        Course *course;

    public:
        SubscriptionToCourseForm() : student(NULL), course(NULL), Form(FormType::SubscriptionToCourse) {}

    public:
        virtual void execute();
        void fill_in(Student *student, Course *course);
};

#endif