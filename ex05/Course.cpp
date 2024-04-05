# include "Course.hpp"
# include "Student.hpp"
# include "Professor.hpp"
# include "CourseFinishedForm.hpp"
# include "singletons.hpp"

const std::string &Course::get_name() { return (this->_name); }

void Course::assign(Professor* p_professor) {
    if (this->_responsable == p_professor) {
        return ;
    }

    this->_responsable = p_professor;

    if (this->_responsable != NULL) {
        this->_responsable->assignCourse(this);
    }
}

void Course::subscribe(Student* p_student) {
    this->addItem(p_student);
}

void Course::close() {
    // demanding from the responsable to close the course
    int mandatoryNumberOfClasses = 0;

    if (this->_responsable != NULL) {
        mandatoryNumberOfClasses = this->_responsable->getNumberOfClasses();
        this->_responsable = NULL;
    }

    // anouncing the end of the course for all subscribed students
    std::vector<Student *>::iterator student = this->items.begin();

    while (student != this->items.end()) {
        if ((*student)->getNumberOfAttendedClasses(this) >= mandatoryNumberOfClasses) {
           (*student)->graduate(this);

            std::cout << "Student graduated the course " << this->get_name() << "!" << std::endl;
            if ((*student)->getCoursesCount() == 0) {
                // StudentList &instance_ref = StudentList::get_instance();

                std::cout << "Student graduated!" << std::endl;
                // instance_ref.removeItem(*student);
            }
        }
        student = this->items.erase(student);
    }
}
