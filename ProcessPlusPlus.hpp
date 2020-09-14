/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef PROCESS_PLUS_PLUS_HPP
#define PROCESS_PLUS_PLUS_HPP

#include <iostream>
#include <sys/stat.h>
#include <dirent.h>
#include <bits/stdc++.h> 
#include <list>


namespace procplusplus {
        std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list) {
            for (auto &i : list) 
                ostr << i << "\n";
            
            return ostr;
        }

        /*std::list<int>&*/void GetPID() {
                struct dirent *entryname;
                struct stat filestat;
                std::list<int> pid;
                int line =0;
                DIR *directory;
                directory = opendir("/proc");
    
                if(directory == NULL) {
                        std::cout << "Directory not found.\n";
                }
    
                while ((entryname = readdir(directory))) {
                        stat(entryname->d_name, &filestat);
                        if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
                                if(strstr(entryname->d_name, ".")) {
                                        // Null
                                } else if(strstr(entryname->d_name, "..")){
	                                // Null
                        	} else {
                        	    	int a = atoi(entryname->d_name);
                        	    	if(a != 0)
			                        pid.push_back(a);
                                }
                        }
                }
    
                pid.sort(std::less<int>());
    
                std::cout << pid;
    
                closedir(directory);
        }
}

#endif /* PROCESS_PLUS_PLUS_HPP */