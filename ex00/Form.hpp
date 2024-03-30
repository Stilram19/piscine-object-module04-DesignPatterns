#ifndef FORM_HPP
# define FORM_HPP

enum class FormType {
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Form {
    private:
        FormType _formType;

    public:
        Form(FormType p_formType) : _formType(p_formType) {}

        virtual void execute() = 0;
};

#endif