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
vex::brain       Brain;

// define your global instances of motors and other devices here

void axis1Changed(){
    robot_rotation((double)Controller.Axis1.position()/100);
}

int main() {
    Controller.Axis1.changed(axis1Changed);
}
