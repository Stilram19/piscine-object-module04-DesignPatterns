#ifndef NEED_COURSE_CREATION_FORM_HPP
# define NEED_COURSE_CREATION_FORM_HPP

class Course;
class Professor;

# include "Form.hpp"

// This class is a concrete Command, implementing the Command "Form"

class NeedCourseCreationForm : public Form
{
    private:
        std::string course_name;
        Professor *responsable;

    public:
        NeedCourseCreationForm() \
            : Form(NeedCourseCreation), responsable(NULL) {}

        ~NeedCourseCreationForm() {}

    public:
        virtual void execute();
        void fill_in(const std::string &course_name, Professor *responsable);
};

#endif