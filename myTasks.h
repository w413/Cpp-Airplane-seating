/*****************************/
/** Programmer: Wayne Benge **/
/** IDE: Dev-C++ 5.11		**/
/*****************************/

/***********************************************************************************************/
/***********************************************************************************************/
/**** Here are some development tools given to me by Professor Bhan.						****/
/**** I've adapted them to C++, they're a massive help for debugging code.					****/
/**** However, they are macros which can have unintuitive consequences.						****/
/***********************************************************************************************/
/**** These macros should only be used in the following ways								****/
/***********************************************************************************************/
/**** TASK																					****/
/****	Should be used in place of comments inside of functions.							****/
/**** 	Should always be passed a string " "												****/
/**** 	Should always be called by itself													****/
/**** 		Don't use it in another function or macro call									****/
/****		Don't call TASK inside of TASK i.e. TASK(TASK("Some task"))						****/
/**** 	Should never be used in the global scope											****/
/**** DEBUG																					****/
/****	Can be used anywhere the passed code is valid										****/
/**** 	Should always be called by itself													****/
/**** 		Don't use it in another function or macro call									****/
/****		Don't call DEBUG inside of DEBUG i.e. DEBUG(DEBUG(<some code>))					****/
/***********************************************************************************************/
/***********************************************************************************************/


// TASK
/***********************************************************************************************/
/**** Used in place of comments inside of functions											****/
/**** #define TASK_PRINT before #include "myTasks.h" to print TASK to standard out			****/
/***********************************************************************************************/
#ifdef TASK_PRINT
#define TASK(INFO) std::cout << INFO << std::endl;
#else
#define TASK(INFO)
#endif


// DEBUG
/***********************************************************************************************/
/**** Used to turn debugging code snippets on or off										****/
/**** #define DEBUG_ON before #include "myTasks.h" to run code snippets						****/
/***********************************************************************************************/
#ifdef DEBUG_ON
#define DEBUG(CODE) CODE
#else
#define DEBUG(CODE)
#endif
