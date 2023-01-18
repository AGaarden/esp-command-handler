/*
 * CommandHandler.h - Library for making commands easier to use
*/

/* Include header file */
#include "CommandHandler.h"

// This will be the container for commands and their names
std::map<String, pfunc> _funckvp{};

// This will find the command to use
// Does this just give a pointer or address or? Must research more
int RunCommand(String comm, String args) {
    if(_funckvp.find(comm) == _funckvp.end()) {
        return -1;
    }
    else {
        pfunc func = _funckvp[comm];
        return (*func)(args);
    }
}

/*
 * It is necessary add commands in a library function so I
 * avoid having someone mess with the function map
 *
 * This currently only takes int functions
*/
int AddCommand(String comm, pfunc func) {
    _funckvp.insert({comm, func});
    return 0;
}

/*
 * Having this function in the library avoids a lot of writing for every project
*/
void WaitForCommand() {
    printf("Please enter your command:\n");

    bool commandTime = false;
    String input = "";
    char inputc;
    while(!commandTime) {
        if(Serial.available()) {
            if((inputc = Serial.read()) != -1) {
                if((inputc) == '\n') {
                    // input.concat(inputc);
                    commandTime = true;
                }
                else {
                    input.concat(inputc);
                }
            }
        }
        
    }

    if(input.indexOf(',') != -1) {
        // Make a command and a command parameter and run the command
        // OBS: Update library to include a command parameter
    }
    else {
        int errCode = RunCommand(input, "");
        if(errCode == -1) {
            printf("Command not found\n");
        }
        else {
            printf("Pog it works\n");
        }
    }
}
