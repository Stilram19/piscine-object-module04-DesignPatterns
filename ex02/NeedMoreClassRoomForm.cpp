# include "NeedMoreClassRoomForm.hpp"
# include "Classroom.hpp"

void NeedMoreClassRoomForm::execute() {
    if (this->classroom != NULL) {
        return ;//form has already been executed
    }

    this->classroom = new Classroom();
}

Classroom *NeedMoreClassRoomForm::get_classroom() const {
    return (this->classroom);
}