#include "init.hpp"
#include "functions.hpp"


double front_right_velocity = 0;
double front_left_velocity = 0;
double back_right_velocity = 0;
double back_left_velocity = 0;

double k_speed = 100;
double k_speed_change = 1;

void robot_right_left(double amount) {
    front_left_velocity += amount;
    front_right_velocity += -amount;
    back_left_velocity += -amount;
    back_right_velocity += amount;
}

void robot_forward_backward(double amount) {
    front_left_velocity += amount;
    front_right_velocity += amount;
    back_left_velocity += amount;
    back_right_velocity += amount;
}

void robot_rotation(double amount) {
    front_right_velocity += -amount;
    back_right_velocity += -amount;
    back_left_velocity += amount;
    front_left_velocity += amount;
}

void robot_moveGeneral() {
    m_front_right.spin(reverse,front_right_velocity * k_speed, rpm);
    m_front_left.spin(forward,front_left_velocity * k_speed, rpm);
    m_back_right.spin(reverse,back_right_velocity * k_speed, rpm);
    m_back_left.spin(forward, back_left_velocity * k_speed, rpm);
    Brain.Screen.print("moveGeneral");
    front_right_velocity = 0;
    front_left_velocity = 0;
    back_right_velocity = 0;
    back_left_velocity = 0;
}

void increase_speed(){
    k_speed += k_speed_change;
}

void decrease_speed(){
    k_speed -= k_speed_change;
}