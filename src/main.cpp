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

// A global instance of vex::brain used for printing to the V5 brain screen

// define your global instances of motors and other devices here

int main() {
    Brain.Screen.print("Hello please work");
    while (true){
        robot_forward_backward((double)Controller.Axis3.position()/100.0);
        robot_right_left((double)Controller.Axis4.position()/100.0);
        robot_rotation((double)Controller.Axis1.position()/100.0);


        // Move General must be at the bottom.
        robot_moveGeneral();
    }
}
