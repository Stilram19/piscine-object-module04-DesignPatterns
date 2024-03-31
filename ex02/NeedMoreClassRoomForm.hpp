#ifndef NEED_MORE_CLASS_ROOM_FORM_HPP
# define NEED_MORE_CLASS_ROOM_FORM_HPP

# include "Form.hpp"
# include <iostream>

class Classroom;

class NeedMoreClassRoomForm : public Form {
    private:
        Classroom *classroom;

    public:
        NeedMoreClassRoomForm() : classroom(NULL), Form(FormType::NeedMoreClassRoom) {}
        ~NeedMoreClassRoomForm() {}

    public:
        virtual void execute();
        Classroom *get_classroom() const;
};

#endif