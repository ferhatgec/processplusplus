# ProcessPlusPlus
## Single header process &amp; system information library. Written in C++17.

```cpp
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
```

#### ProcessPlusPlus licensed under the terms of MIT License.
