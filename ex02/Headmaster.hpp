#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

# include "Staff.hpp"

// this class represents the invoker or the sender (of the Command "Form")
// as you see it is independent from the receiver ("Course" in case of CourseFinishedForm
// and SubscriptionToCourseForm as an example)

class Headmaster : public Staff {
    private:
        std::vector<Form *> _formToValidate;

    public:
        Headmaster(std::string &p_name) : Staff(p_name) {}
        ~Headmaster() {}

    private:
        bool hasForm(Form *p_form);
        void deleteForm(Form *p_form);

    public:
        void receiveForm(Form *p_form);
        void executeForm(Form *p_form);
        virtual void sign(Form *p_form);
};

#endif