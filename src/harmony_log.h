#ifndef HARMONY_LOG_H
#define HARMONY_LOG_H

/**
 * Checks for errors in the OpenGL function call.
 * This cannot be used inside of an if/while/switch statement.
 */
#define HARMONY_DEBUG
#ifdef HARMONY_DEBUG
#define harmony_checkError(x) harmony_clearErrors(); x; harmony_logErrors(#x);
#else
#define harmony_checkError(x) x;
#endif

/**
 * Clears all OpenGL errors.
 */
void harmony_clearErrors();

/**
 * Prints all OpenGL errors to the console.
 */
int harmony_logErrors(const char *message);

/**
* Prints an info message to the console.
*/
void harmony_log(const char *message);

/**
* Prints a warning message to the console.
*/
void harmony_warn(const char *message);

/**
* Prints an error message to the console.
*/
void harmony_error(const char *message);

#endif