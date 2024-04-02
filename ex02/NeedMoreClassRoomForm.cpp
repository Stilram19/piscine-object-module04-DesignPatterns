# include "NeedMoreClassRoomForm.hpp"
# include "Classroom.hpp"
# include "singletons.hpp"

void NeedMoreClassRoomForm::execute() {
    if (this->classroom != NULL) {
        return ;//form has already been executed
    }

    // adding the Class room to the RoomList
    RoomList &instance_ref = RoomList::get_instance();

    instance_ref.addItem(new Classroom());
}
