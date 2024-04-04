# include "singletons.hpp"
# include "Professor.hpp"
# include "Student.hpp"
# include "Course.hpp"
# include "Headmaster.hpp"
# include "Secretary.hpp"
# include "CourseFinishedForm.hpp"
# include "NeedMoreClassRoomForm.hpp"
# include "NeedCourseCreationForm.hpp"
# include "SubscriptionToCourseForm.hpp"

// this module represents the client, that is creating the concrete commands, injecting
// them into the invoker (HeadMaster) and managing the memory.

Form *createForm(FormType formType) {
    std::string secretaryName("Patric");
    Secretary secretary(secretaryName);

    return (secretary.createForm(formType));
}

void test() {
    std::string headmasterName("Mark");
    std::string profName("Mike");
    std::string studentName("Peter");
    std::string courseName("DesignPatterns");
    Course course(courseName);
    Student student(studentName);
    Professor prof(profName);
    Headmaster headmaster(headmasterName);

    CourseFinishedForm *courseFinishedForm = dynamic_cast<CourseFinishedForm *>(createForm(CourseFinished));
    NeedMoreClassRoomForm *needMoreClassRoomForm = dynamic_cast<NeedMoreClassRoomForm *>(createForm(NeedMoreClassRoom));
    NeedCourseCreationForm *needCourseCreationForm = dynamic_cast<NeedCourseCreationForm *>(createForm(NeedCourseCreation));
    SubscriptionToCourseForm *subscriptionToCourseForm = dynamic_cast<SubscriptionToCourseForm *>(createForm(SubscriptionToCourse));

    // since each concrete command requires parameters injection through a setter
    // and no setter is available in the Command interface, we need to downcast the
    // pointers returned by the factory in order to supply each concrete command by
    // the corresponding parameters.
    courseFinishedForm->fill_in(&course);
    needCourseCreationForm->fill_in(10, 10, "DataStructuresAndAlgorithms", &prof);
    subscriptionToCourseForm->fill_in(&student, &course);

    headmaster.receiveForm(courseFinishedForm);
    headmaster.receiveForm(needMoreClassRoomForm);
    headmaster.receiveForm(needCourseCreationForm);
    headmaster.receiveForm(subscriptionToCourseForm);

    headmaster.sign(courseFinishedForm);
    headmaster.sign(needMoreClassRoomForm);
    headmaster.sign(needCourseCreationForm);
    headmaster.sign(subscriptionToCourseForm);

    RoomList &roomList = RoomList::get_instance();
    CourseList &courseList = CourseList::get_instance();

    std::cout << "After executing the needMoreClassRoomForm, the size of the Room list is " << roomList.size() << std::endl;
    std::cout << "After executing the needCourseCreationForm, the size of the Room list is " << courseList.size() << std::endl;
}

int main() {
    test();
    return (0);
}
