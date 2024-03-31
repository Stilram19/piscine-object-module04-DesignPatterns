#ifndef NEED_COURSE_CREATION_FORM_HPP
# define NEED_COURSE_CREATION_FORM_HPP

class Course;

# include "Form.hpp"

// This class is a concrete Command, implementing the Command "Form"

class NeedCourseCreationForm : public Form
{
    private:
        int _minimumGradeToGraduate;
        int _maximumNumberOfStudents;
        std::string course_name;
        Course *course;

    public:
        NeedCourseCreationForm() \
            : _minimumGradeToGraduate(), _maximumNumberOfStudents(0) \
            , course(NULL), Form(FormType::NeedCourseCreation) {}

        ~NeedCourseCreationForm() {}

    public:
        virtual void execute();
        void fill_in(int minimumGradeToGraduate, int maximumNumberOfStudents, std::string &course_name);
};

#endif