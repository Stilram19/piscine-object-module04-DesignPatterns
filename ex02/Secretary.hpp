#ifndef SECRETARY_HPP
# define SECRETARY_HPP

# include "Form.hpp"
# include "Staff.hpp"
# include "CourseFinishedForm.hpp"
# include "NeedMoreClassRoomForm.hpp"
# include "SubscriptionToCourseForm.hpp"

class Secretary : public Staff {
    private:

    public:
        // this function may also be static
        Form* createForm(FormType p_formType) {
            
        }
        void archiveForm();
};

#endif