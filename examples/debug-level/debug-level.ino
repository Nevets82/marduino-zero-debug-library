/**
 * Example code demonstrating the use of the DEBUG_LEVEL macro.
 */

#include <Arduino.h>

#define DEBUG_LEVEL     DEBUG_LEVEL_TRACE   // Define debug level

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
