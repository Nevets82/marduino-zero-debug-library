# Marduino Zero Debug Library

Simple macro based debugging library for Marduino Zero.

## License

```
Copyright (c) 2019-2020 Steven Lietaer

This code is licensed under the MIT License.
See LICENSE file for more information.
```

## Documentation

Simple macro based debugging library for Marduino Zero.

### Debug Macros

The following basic debug macros have been defined:

| Macro Name    | Description                                     |
| ------------- | ----------------------------------------------- |
| TRACE         | Writes a trace message to the debugger          |
| VERBOSE       | Writes a verbose message to the debugger        |
| DEBUG         | Writes a debug message to the debugger          |
| INFORMATIONAL | Writes an informational message to the debugger |
| INFO          | Same as INFORMATIONAL                           |
| NOTICE        | Writes a notice message to the debugger         |
| WARNING       | Writes a warning message to the debugger        |
| WARN          | Same as WARNING                                 |
| CRITICAL      | Writes a critical message to the debugger       |
| ALERT         | Writes an alert message to the debugger         |
| EMERGENCY     | Writes an emergency message to the debugger     |
| FATAL         | Writes a fatal message to the debugger          |
| PANIC         | Writes a panic message to the debugger          |

The following advanced debug macros have been defined:

| Macro Name          | Description                                                                         |
| ------------------- | ----------------------------------------------------------------------------------- |
| TRACE_INPUT         | Writes a trace input message to the debugger (adds < before the trace message)      |
| TRACE_OUTPUT        | Writes a trace output message to the debugger (adds > before the trace message)     |
| VERBOSE_INPUT       | Writes a verbose input message to the debugger (adds < before the verbose message)  |
| VERBOSE_OUTPUT      | Writes a verbose output message to the debugger (adds > before the verbose message) |
| DEBUG_INPUT         | Writes a debug input message to the debugger (adds < before the debug message)      |
| DEBUG_OUTPUT        | Writes a debug output message to the debugger (adds > before the debug message)     |
| DEBUGGING           | Can be use to execute debugging specific code                                       |
| TRACING             | Can be use to execute tracing specific code                                         |
| START_DEBUGGER()    | Starts the debugger ```DEBUGGER.begin(DEBUGGER_SPEED)```                            |
| WAIT_FOR_DEBUGGER() | Waits for the debugger to connect ```while(!DEBUGGER)```                            |

### Debug Level Macros

The following debug level macros have been defined:

| Debug Level               | Value | Description                                                        |
| ------------------------- | ----- | ------------------------------------------------------------------ |
| DEBUG_LEVEL_NONE          | -1    | (Default) No debug messages are written to the debugger.           |
| DEBUG_LEVEL_EMERGENCY     | 0     | Debug messages with a value of 0 are written to the debugger.      |
| DEBUG_LEVEL_FATAL         | 0     | Debug messages with a value of 0 are written to the debugger.      |
| DEBUG_LEVEL_PANIC         | 0     | Debug messages with a value of 0 are written to the debugger.      |
| DEBUG_LEVEL_ALERT         | 1     | Debug messages with a value of 0 or 1 are written to the debugger. |
| DEBUG_LEVEL_CRITICAL      | 2     | Debug messages with a value of 0 to 2 are written to the debugger. |
| DEBUG_LEVEL_ERROR         | 3     | Debug messages with a value of 0 to 3 are written to the debugger. |
| DEBUG_LEVEL_WARN          | 4     | Debug messages with a value of 0 to 3 are written to the debugger. |
| DEBUG_LEVEL_WARNING       | 4     | Debug messages with a value of 0 to 4 are written to the debugger. |
| DEBUG_LEVEL_NOTICE        | 5     | Debug messages with a value of 0 to 5 are written to the debugger. |
| DEBUG_LEVEL_INFO          | 6     | Debug messages with a value of 0 to 6 are written to the debugger. |
| DEBUG_LEVEL_INFORMATIONAL | 6     | Debug messages with a value of 0 to 6 are written to the debugger. |
| DEBUG_LEVEL_DEBUG         | 7     | Debug messages with a value of 0 to 7 are written to the debugger. |
| DEBUG_LEVEL_TRACE         | 8     | All debug messages are written to the debugger.                    |
| DEBUG_LEVEL_VERBOSE       | 8     | All debug messages are written to the debugger.                    |

### Debug Configuration Macros

The following debug configuration macros are available for declaration:

| Macro Name                  | Default Value    | Description                                                           |
| --------------------------- | ---------------- | --------------------------------------------------------------------- |
| DEBUGGER                    | SerialUSB        | The debugger interface                                                |
| DEBUGGER_SPEED              | 9600             | The debugger interface speed                                          |
| DEBUG_LEVEL                 | DEBUG_LEVEL_NONE | The debug level                                                       |
| DEBUG_PRINT_MILLIS          |                  | When defined prints the value of ```millis()``` before debug messages |
| DEBUG_CONTINUE_ON_EMERGENCY |                  | When defined continues execution after printing emergency message.    |
| DEBUG_CONTINUE_ON_FATAL     |                  | When defined continues execution after printing fatal message.        |
| DEBUG_CONTINUE_ON_PANIC     |                  | When defined continues execution after printing panic message.        |

## Usage

Before including the ```debug.h``` header file you should define some debug
configuration macros.

### Change Debug Level

The most important configuration macro is ```DEBUG_LEVEL``` which controls the
debug messages that are written to the debugger. The default is 
```DEBUG_LEVEL_NONE```, no debug messages. 

```cpp
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
```

### Change Debugger/Speed

If you wish to use another debugger than ```SerialUSB``` you need to define the
```DEBUGGER``` macro before including the ```debug.h``` header file. You can
also control the bebugger speed with ```DEBUGGER_SPEED```.

```cpp
#include <Arduino.h>

#define DEBUGGER        SerialUSB           // Define debugger stream
#define DEBUGGER_SPEED  9600                // Define debugger speed
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
```

### Continue Execution After Panic/Emergency/Fatal

To continue execution after panic, emergency or fatal debug messages you must
define the corresponding macro ```DEBUG_CONTINUE_ON_PANIC```, 
```DEBUG_CONTINUE_ON_EMERGENCY``` or  ```DEBUG_CONTINUE_ON_FATAL```.

```cpp
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
```

### Print Milliseconds

If you wish to add the number of milliseconds before the debug messages then
just define the ```DEBUG_PRINT_MILLIS``` macro.

```cpp
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
```

## Changelog

### Version 1.0.0

- Initial version
