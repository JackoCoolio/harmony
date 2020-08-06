#ifndef HARMONY_LOG_H
#define HARMONY_LOG_H

/**
 * Checks for errors in the OpenGL function call.
 * This cannot be used inside of an if/while/switch statement.
 */
#ifdef HARMONY_DEBUG
#define harmony_checkError(x) harmony_clearErrors(); x; harmony_logErrors();
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
int harmony_logErrors();

#endif