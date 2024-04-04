# include "Course.hpp"
# include "Student.hpp"

void Course::subscribe(Student* p_student) {
    this->addItem(p_student);
}
