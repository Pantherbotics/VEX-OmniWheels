#include "init.hpp"

motor m_front_right = motor(PORT10, false);
motor m_front_left = motor(PORT1, false);
motor m_back_right = motor(PORT9, false);
motor m_back_left = motor(PORT12, false);
controller Controller = controller(primary);
vex::brain       Brain;
