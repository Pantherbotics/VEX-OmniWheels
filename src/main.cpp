/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       rohan+eric                                                */
/*    Created:      3/26/2025, 3:35:08 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "functions.hpp"
#include "init.hpp"
#include "vex.h"
using namespace vex;

// Button handlings go here -- Rohan
void on_DPAD_down_pressed(){
    decrease_speed();
}
void on_DPAD_up_pressed(){
    increase_speed();
}
void on_ButtonA_pressed(){
    grab();
}
void on_ButtonB_pressed(){
    release();
}

void on_ButtonR1_pressed(){
    move_arm_up();
}
void on_ButtonR1_release(){
    m_arm.stop();
}

void on_ButtonL1_pressed(){
    move_arm_down();
}
void on_ButtonL1_release(){
    m_arm.stop();
}

int main() {
    
    // Bind buttons here and make functions under button handlings above -- Rohan
    Controller.ButtonDown.pressed(on_DPAD_down_pressed);
    Controller.ButtonUp.pressed(on_DPAD_up_pressed);
    Controller.ButtonA.pressed(on_ButtonA_pressed);
    Controller.ButtonB.pressed(on_ButtonB_pressed);
    Controller.ButtonR1.pressed(on_ButtonR1_pressed);
    Controller.ButtonR1.released(on_ButtonR1_release);
    Controller.ButtonL1.pressed(on_ButtonL1_pressed);
    Controller.ButtonL1.released(on_ButtonL1_release);

    while (true){
        robot_forward_backward((double)Controller.Axis3.position()/100.0);
        robot_right_left((double)Controller.Axis4.position()/100.0);
        robot_rotation((double)Controller.Axis1.position()/100.0);

        // Move General must be at the bottom. -- Rohan
        robot_moveGeneral();
    }
}
