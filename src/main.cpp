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

int main() {
    Brain.Screen.print("Hello please work");

    // Bind buttons here and make functions under button handlings above -- Rohan
    Controller.ButtonDown.pressed(on_DPAD_down_pressed);
    Controller.ButtonUp.pressed(on_DPAD_up_pressed);

    while (true){
        robot_forward_backward((double)Controller.Axis3.position()/100.0);
        robot_right_left((double)Controller.Axis4.position()/100.0);
        robot_rotation((double)Controller.Axis1.position()/100.0);

        // Move General must be at the bottom. -- Rohan
        robot_moveGeneral();
    }
}
