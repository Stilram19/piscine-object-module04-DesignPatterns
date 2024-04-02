#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

# include "Staff.hpp"
# include "Enums.hpp"

class Professor;
class Student;
class Classroom;
class Secretary;

// this class represents the invoker or the sender (of the Command "Form")
// as you see it is independent from the receiver ("Course" in case of CourseFinishedForm
// and SubscriptionToCourseForm as an example)

// this class represents the Mediator for Professor and Student. (the mediator cannot
// depend on concrete Forms because it is also the invoker of the Command "Form").

class Headmaster : public Staff {
    private:
        Secretary           *secretary;
        std::vector<Form *> _formToValidate;

    public:
        Headmaster(Secretary *secretary, std::string &p_name) : Staff(p_name), secretary(secretary) {}
        ~Headmaster();

    private:
        bool hasForm(Form *p_form);
        void deleteForm(Form *p_form);

    public:
        void receiveForm(Form *p_form);
        void executeForm(Form *p_form);
        virtual void sign(Form *p_form);

    public:
        void commandProfToAttendClass(Professor *prof);
        void commandStudentToAttendClass(Student *student, Classroom *classroom);
        Form *getNewForm(FormType formtype);// returns a new form to be filled
};

#endif