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
        std::cout << "PID:\n";
        procplusplus::GetPID();
    	return 0;
}