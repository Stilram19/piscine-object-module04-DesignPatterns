# include "Secretary.hpp"
# include "CourseFinishedForm.hpp"
# include "NeedCourseCreationForm.hpp"
# include "NeedMoreClassRoomForm.hpp"
# include "SubscriptionToCourseForm.hpp"

Form* Secretary::createForm(FormType p_formType) {
    if (p_formType == CourseFinished) {
        return (new CourseFinishedForm());
    }
    if (p_formType == NeedCourseCreation) {
        return (new NeedCourseCreationForm());
    }
    if (p_formType == NeedMoreClassRoom) {
        return (new NeedMoreClassRoomForm());
    }
    if (p_formType == SubscriptionToCourse) {
        return (new SubscriptionToCourseForm());
    }
    return (NULL);
}

void Secretary::archiveForm() {
    // no idea
}
