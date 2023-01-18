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
using pfunc = int (*)();

/* Functions */
int RunCommand(String comm);
int AddCommand(String comm, pfunc func);
void WaitForCommand();

#endif