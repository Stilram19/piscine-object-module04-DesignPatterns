#ifndef ISECRETARY_HPP
# define ISECRETARY_HPP

# include "Enums.hpp"
# include "Staff.hpp"

class Form;

// this class's purpose is to decouple the headmaster from the concrete commands,
// because in this exercise the headmaster must have a factory (aggregation) and since
// the headmaster is the invoker of the Command and the concrete factory class is dependent
// on the concrete commands, making the former depend on Abstract factory will solve the issue.

class ISecretary : public Staff {
    public:
        ISecretary(std::string &p_name) : Staff(p_name) {}

    public:
        static Form* createForm(FormType p_formType);
};

#endif