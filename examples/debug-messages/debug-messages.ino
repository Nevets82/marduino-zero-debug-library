/**
 * Example code demonstrating the use of the debug macros.
 */

#include <Arduino.h>

#define DEBUGGER        SerialUSB           // Define debugger stream
#define DEBUGGER_SPEED  9600                // Define debugger speed
#define DEBUG_LEVEL     DEBUG_LEVEL_TRACE   // Define debug level
#define DEBUG_PRINT_MILLIS                  // Add number of milliseconds to
                                            // debug messages
#define DEBUG_CONTINUE_ON_EMERGENCY         // Define continue on emergency
#define DEBUG_CONTINUE_ON_FATAL             // Define continue on fatal
#define DEBUG_CONTINUE_ON_PANIC             // Define continue on panic

#include <debug.h>

void setup()
{
    START_DEBUGGER();                       // Start debugger

    WAIT_FOR_DEBUGGER();                    // Wait for debugger
    
    DEBUGGER.println("------------------------------------ SETUP -------------------------------------");

    TRACE("Trace message from setup.");

    delay(1000);

    VERBOSE("Verbose message from setup.");

    delay(1000);

    DEBUG("Debug message from setup.");

    delay(1000);

    INFO("Informational message from setup.");

    delay(1000);

    NOTICE("Notice message from setup.");
    
    delay(1000);

    WARN("Warning message from setup.");

    delay(1000);

    ERROR("Error message from setup.");

    delay(1000);

    CRITICAL("Critical message from setup.");

    delay(1000);

    ALERT("Alert message from setup.");

    delay(1000);

    EMERGENCY("Emergency message from setup.");

    delay(1000);

    FATAL("Fatal message from setup.");

    delay(1000);

    PANIC("Panic message from setup.");

    delay(1000);
}

void loop()
{
    DEBUGGER.println("------------------------------------- LOOP -------------------------------------");
    
    TRACE("Trace message from loop.");

    delay(1000);

    VERBOSE("Verbose message from loop.");

    delay(1000);

    DEBUG("Debug message from loop.");

    delay(1000);

    INFO("Informational message from loop.");

    delay(1000);

    NOTICE("Notice message from loop.");

    delay(1000);

    WARNING("Warning message from loop.");

    delay(1000);

    ERROR("Error message from loop.");

    delay(1000);
    
    CRITICAL("Critical message from loop.");

    delay(1000);

    ALERT("Alert message from loop.");

    delay(1000);

    EMERGENCY("Emergency message from loop.");

    delay(1000);

    FATAL("Fatal message from loop.");

    delay(1000);

    PANIC("Panic message from loop.");

    delay(1000);
}
