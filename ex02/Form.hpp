#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Enums.hpp"

// this is the Command interface (the Command design pattern)

class Form {
    private:
        FormType _formType;

    public:
        Form(FormType p_formType) : _formType(p_formType) {}
        virtual void execute() = 0;
};

#endif