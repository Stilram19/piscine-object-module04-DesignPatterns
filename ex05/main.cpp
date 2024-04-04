# include "Headmaster.hpp"
# include "Professor.hpp"
# include "Student.hpp"
# include "Secretary.hpp"
# include "singletons.hpp"
# include "Bell.hpp"
# include "observer.hpp"

// Headmaster requires Professor to attend his class
void test1() {
    std::string headmasterName("Donald");
    std::string ProfName("Bob");
    std::string SecretaryName("Bob");
    std::string StudentName("Bob");
    Bell        bell;

    Secretary secretary(SecretaryName);
    Headmaster headmaster(&secretary, &bell, headmasterName);
    Professor prof(ProfName, &headmaster);
    Student student(&headmaster, StudentName);

    prof.requestCourseCreation(70, 30, "Template Programming in c++");
    headmaster.askProfToAttendClass(&prof);

    student.subscribe(prof.getCurrentCourse());
    headmaster.commandStudentToAttendClass(&student, prof.getCurrentClassroom());

    headmaster.addBellObserver(&prof);
    headmaster.addBellObserver(&student);

    headmaster.doEvent(RingBell);

    if (prof.room() == NULL && student.room() == NULL) {
        std::cout << "Both Students and Professor exited the classroom for a break." << std::endl;
    }

    headmaster.doEvent(RingBell);

    if (prof.room() == student.room() && prof.room() != NULL) {
        std::cout << "Students and Professor are in the classroom, to resume the class." << std::endl;
    }
}

int main() {
    try {
        test1();
    }
    catch (const std::out_of_range &e) {
        std::cout << "Out of range: " << e.what() << std::endl;
    }
    return (0);
}
