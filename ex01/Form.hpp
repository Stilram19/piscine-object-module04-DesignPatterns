#ifndef FORM_HPP
# define FORM_HPP

enum FormType {
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
        virtual ~Form() {}

        virtual void execute() = 0;
};

#endif