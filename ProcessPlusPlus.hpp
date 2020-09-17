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
#include <cstring>
#include <cstdlib>

namespace procplusplus {
    	static std::string FindStringWithReturn(std::string file, std::string str) {
		std::string line;
    		std::ifstream readfile(file.c_str());
    		if(readfile.is_open()) {
        	while (std::getline(readfile, line)) {
			if(strstr(line.c_str(), str.c_str()))
				return line + "\n";
        	}
        	readfile.close();
    		} else {
        		return "error"; /* Unable to open file */
    		}
    		return "null"; /* Not found. */
    	}

        static std::string EraseAllSubString(std::string & mainString, const std::string & erase) {
    		size_t pos = std::string::npos;
   		while((pos = mainString.find(erase)) != std::string::npos) {
        		mainString.erase(pos, erase.length());
  		}
  		return mainString;
  	}

        std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list) {
            for (auto &i : list) 
                ostr << i << "\n";
            
            return ostr;
        }

        /* By PID */
        std::string GetProcessName(int pid) {
                std::string path("/proc/");
                path.append(std::to_string(pid));
                path.append("/status");
                path = FindStringWithReturn(path, "Name:");
                if(path != "null") {
                        return path.erase(0, 6);
                }
                return "null";
        }

        /* By Name */
        int GetPIDByName(std::string name) {
                const char* directory = "/proc";
                size_t      taskNameSize = 1024;
                char*       taskName = (char*)calloc(1, taskNameSize);

                DIR* dir = opendir(directory);

                if (dir) {
                        struct dirent* de = 0;

                        while ((de = readdir(dir)) != 0) {
                                if (strcmp(de->d_name, ".") == 0 || 
                                        strcmp(de->d_name, "..") == 0)
                                continue;

                                int pid = -1;
                                int res = sscanf(de->d_name, "%d", &pid);

                                if (res == 1) {
                                /* Valid PID Value */

                                char cmdline_file[1024] = {0};
                                sprintf(cmdline_file, "%s/%d/cmdline", directory, pid);

                                FILE* cmdline = fopen(cmdline_file, "r");

                                if (getline(&taskName, &taskNameSize, cmdline) > 0)
                                        if (strstr(taskName, name.c_str()) != 0)
                                                return pid;

                                        fclose(cmdline);
                                }
                        }

                        closedir(dir);
                }

                return -1;
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
                        	    	if(a != 0) {
			                        pid.push_back(a);
                                        }
                                }
                        }
                }
    
                pid.sort(std::less<int>());
    
                std::cout << pid;
        
                closedir(directory);
        }
}

#endif /* PROCESS_PLUS_PLUS_HPP */