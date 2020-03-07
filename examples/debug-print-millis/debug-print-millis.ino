/**
 * Example code demonstrating the use of DEBUG_PRINT_MILLIS macro.
 */

#include <Arduino.h>

#define DEBUG_LEVEL     DEBUG_LEVEL_TRACE   // Define debug level
#define DEBUG_PRINT_MILLIS                  // Add number of milliseconds to
                                            // debug messages

#include <debug.h>

void setup()
{
    START_DEBUGGER();                       // Start debugger

    WAIT_FOR_DEBUGGER();                    // Wait for debugger

    TRACE("Debugging has started.");        // Write trace message
}

void loop()
{
    DEBUG("Debugging loop.");               // Write debug message

    PANIC("Execution has stopped.");        // Write panic message
}
