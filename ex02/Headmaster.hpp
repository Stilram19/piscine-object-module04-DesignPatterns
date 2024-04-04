#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

# include "Staff.hpp"
# include "List.hpp"

// this class represents the invoker or the sender (of the Command "Form")
// as you see it is independent from the receiver ("Course" in case of CourseFinishedForm
// and SubscriptionToCourseForm as an example)

class Headmaster : public Staff, public List<Form> {
    public:
        Headmaster(std::string &p_name) : Staff(p_name), List<Form>(true) {}
        ~Headmaster() {}

    public:
        void receiveForm(Form *p_form);
        void executeForm(Form *p_form);
        virtual void sign(Form *p_form);
};

#endif