/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <ProcessPlusPlus.hpp> /* Process library */

/* Help */
#define HELP(object) std::cout << "Usage: " << object << " [--pid | --name]\n --pid : <NAME> to <PID>\n--name : <PID> to <NAME>\n";

/*
        --name : Get Name by PID
        --pid : Get PID by Name

        Required 2 argument.
*/
int main(int argc, char** argv) {
        if(argc < 3) {
                HELP(argv[0])
                return 0;
        }
        std::string text(argv[1]);
        if(text == "--pid") {
                std::string test(argv[2]);
                std::cout << "PID:" << procplusplus::GetPIDByName(test) << "\nName: " <<
                argv[2] << "\n";
        } else if(text == "--name") {
                std::string pid_string(argv[2]);
                int pid = atoi(pid_string.c_str());
                std::cout << "Name: " << procplusplus::GetProcessName(pid) + "PID: " + 
                pid_string + "\n";
        } else
                HELP(argv[0]) 

        return 0;
}