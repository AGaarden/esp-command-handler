/*
 * CommandHandler.h - Library for making commands easier to use
*/

/* Include necessary libraries */
#include <Esp.h>
#include <functional>
#include <map>

#ifndef CommandHandler_h
#define Commandhandler_h

/* Does this work? idk */
using pfunc = int (*)(String);

/* Functions */
int RunCommand(String comm, String args);
int AddCommand(String comm, pfunc func);
void WaitForCommand();

#endif