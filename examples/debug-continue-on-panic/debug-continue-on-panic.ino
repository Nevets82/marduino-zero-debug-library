/**
 * Example code demonstrating the use of the DEBUG_CONTINUE_ON_PANIC macro.
 */

#include <Arduino.h>

#define DEBUG_LEVEL     DEBUG_LEVEL_TRACE   // Define debug level
#define DEBUG_CONTINUE_ON_PANIC             // Define continue on panic

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

    PANIC("Execution will continue.");      // Write panic message

    delay(1000);
}
