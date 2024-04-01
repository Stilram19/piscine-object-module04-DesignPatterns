#ifndef COURSE_FINISHED_FORM_HPP
# define COURSE_FINISHED_FORM_HPP

# include "Form.hpp"

class Course;

// This class is a concrete Command, implementing the Command "Form"

class CourseFinishedForm : public Form {
    private:
        Course *_course; // the receiver in the command design pattern

    public:
        CourseFinishedForm() : Form(CourseFinished), _course(NULL) {}

    public:
        virtual void execute();
        void fill_in(Course *course);
};

#endif