#ifndef NEED_MORE_CLASS_ROOM_FORM_HPP
# define NEED_MORE_CLASS_ROOM_FORM_HPP

# include "Form.hpp"
# include <iostream>

class Classroom;

// This class is a concrete Command, implementing the Command "Form"

class NeedMoreClassRoomForm : public Form {
    private:
        Classroom *classroom;

    public:
        NeedMoreClassRoomForm() : Form(NeedMoreClassRoom), classroom(NULL) {}
        ~NeedMoreClassRoomForm() {}

    public:
        virtual void execute();
};

#endif