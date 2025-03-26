#include "init.hpp"
#include "functions.hpp"

double front_right_heading = 1;
double front_left_heading = 1;
double back_right_heading = 1;
double back_left_heading = 1;

double k_speed = 10;

void robot_right_left(double amount) {
    front_left_heading *= amount;
    front_right_heading *= -amount;
    back_left_heading *= -amount;
    back_right_heading *= amount;
}

void robot_forward_backward(double amount) {
    front_left_heading *= amount;
    front_right_heading *= amount;
    back_left_heading *= amount;
    back_right_heading *= amount;
}

void robot_rotation(double amount) {
    front_right_heading *= -amount;
    back_right_heading *= -amount;
    back_left_heading *= amount;
    front_left_heading *= amount;
}

void robot_moveGeneral() {
    m_front_right.setVelocity(front_right_heading * k_speed, rpm);
    m_front_left.setVelocity(front_left_heading * k_speed, rpm);
    m_back_right.setVelocity(back_right_heading * k_speed, rpm);
    m_back_left.setVelocity(back_left_heading * k_speed, rpm);
}
