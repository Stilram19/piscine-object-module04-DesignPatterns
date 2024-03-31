#ifndef COURSE_FINISHED_FORM_HPP
# define COURSE_FINISHED_FORM_HPP

# include "Form.hpp"

class Course;

class CourseFinishedForm : public Form {
    private:
        Course *_course; // course to end

    public:
        CourseFinishedForm() : _course(NULL), Form(FormType::CourseFinished) {}

    public:
        virtual void execute();
        void fill_in(Course *course);
};

#endif