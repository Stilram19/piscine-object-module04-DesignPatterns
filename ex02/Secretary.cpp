#ifndef SECRETARY_HPP
# define SECRETARY_HPP

# include "CourseFinishedForm.hpp"
# include "NeedCourseCreationForm.hpp"
# include "NeedMoreClassRoomForm.hpp"
# include "SubscriptionToCourseForm.hpp"

Form* createForm(FormType p_formType) {
    if (p_formType == FormType::CourseFinished) {
        return (new CourseFinishedForm());
    }
    if (p_formType == FormType::NeedCourseCreation) {
        return (new NeedCourseCreationForm());
    }
    if (p_formType == FormType::NeedMoreClassRoom) {
        return (new NeedMoreClassRoomForm());
    }
    if (p_formType == FormType::SubscriptionToCourse) {
        return (new SubscriptionToCourseForm());
    }
    return (NULL);
}

void archiveForm() {

}


#endif