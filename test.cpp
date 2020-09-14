/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <ProcessPlusPlus.hpp>

/*
        List all PIDs.
*/
int main(int argc, char** argv) {
        if(argc < 2)
                std::cout << "Use: " << argv[0] << " <PID>\n";
        else {
                //std::cout << "PID:\n";
                std::cout << procplusplus::GetProcessName(atoi(argv[1]));
                //procplusplus::GetPID();
        }
        return 0;
}