/**
 * Simple macro based debugging library for Marduino Zero.
 * 
 * Copyright (c) 2019-2020 Steven Lietaer
 * 
 * This code is licensed under the MIT License.
 * See LICENSE file for more information.
 */

#ifndef __DEBUG_H__
#define __DEBUG_H__

// If no default debugger is defined then...
#ifndef DEBUGGER
    // Define the default debugger.
    #define DEBUGGER SerialUSB
#endif

// If no default debugger speed is defined then...
#ifndef DEBUGGER_SPEED
    // Define the default debugger speed.
    #define DEBUGGER_SPEED 9600
#endif

// Define the supported debug levels.
#define DEBUG_LEVEL_EMERGENCY       0
#define DEBUG_LEVEL_FATAL           0
#define DEBUG_LEVEL_PANIC           0
#define DEBUG_LEVEL_ALERT           1
#define DEBUG_LEVEL_CRITICAL        2
#define DEBUG_LEVEL_ERROR           3
#define DEBUG_LEVEL_WARN            4
#define DEBUG_LEVEL_WARNING         4
#define DEBUG_LEVEL_NOTICE          5
#define DEBUG_LEVEL_INFO            6
#define DEBUG_LEVEL_INFORMATIONAL   6
#define DEBUG_LEVEL_DEBUG           7
#define DEBUG_LEVEL_TRACE           8
#define DEBUG_LEVEL_VERBOSE         8
#define DEBUG_LEVEL_NONE            -1

// If no default debug level is defined then...
#ifndef DEBUG_LEVEL
    // Define the default debug level.
    #define DEBUG_LEVEL DEBUG_LEVEL_NONE
#endif

// Define debugger print millis helper macro.
#ifdef DEBUG_PRINT_MILLIS
    #define _DEBUGGER_PRINT_MILLIS() DEBUGGER.print(millis());DEBUGGER.print(" ")
#else
    #define _DEBUGGER_PRINT_MILLIS()
#endif

// Define trace macros.
#if defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_TRACE
    #define TRACE(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Trace] ");DEBUGGER.println(__VA_ARGS__)
    #define TRACE_INPUT(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Trace] < ");DEBUGGER.println(__VA_ARGS__)
    #define TRACE_OUTPUT(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Trace] > ");DEBUGGER.println(__VA_ARGS__)
#else
    #define TRACE(...)
    #define TRACE_INPUT(...)
    #define TRACE_OUTPUT(...)
#endif

// Define verbose macros.
#if defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_VERBOSE
    #define VERBOSE(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Verbose] ");DEBUGGER.println(__VA_ARGS__)
    #define VERBOSE_INPUT(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Verbose] < ");DEBUGGER.println(__VA_ARGS__)
    #define VERBOSE_OUTPUT(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Verbose] > ");DEBUGGER.println(__VA_ARGS__)
#else
    #define VERBOSE(...)
    #define VERBOSE_INPUT(...)
    #define VERBOSE_OUTPUT(...)
#endif

// Define debug macros.
#if defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_DEBUG
    #define DEBUG(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Debug] ");DEBUGGER.println(__VA_ARGS__)
    #define DEBUG_INPUT(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Debug] < ");DEBUGGER.println(__VA_ARGS__)
    #define DEBUG_OUTPUT(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Debug] > ");DEBUGGER.println(__VA_ARGS__)
#else
    #define DEBUG(...)
    #define DEBUG_INPUT(...)
    #define DEBUG_OUTPUT(...)
#endif

// Define info macros.
#if defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_INFORMATIONAL
    #define INFO(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Info] ");DEBUGGER.println(__VA_ARGS__)
    #define INFORMATIONAL(...) INFO(__VA_ARGS__)
#else
    #define INFO(...)
    #define INFORMATIONAL(...)
#endif

// Define notice macros.
#if defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_NOTICE
    #define NOTICE(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Notice] ");DEBUGGER.println(__VA_ARGS__)
#else
    #define NOTICE(...)
#endif

// Define warning macros.
#if defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_WARNING
    #define WARN(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Warning] ");DEBUGGER.println(__VA_ARGS__)
    #define WARNING(...) WARN(__VA_ARGS__)
#else
    #define WARN(...)
    #define WARNING(...)
#endif

// Define error macros.
#if defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_ERROR
    #define ERROR(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Error] ");DEBUGGER.println(__VA_ARGS__)
#else
    #define ERROR(...)
#endif

// Define critical macros.
#if defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_CRITICAL
    #define CRITICAL(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Critical] ");DEBUGGER.println(__VA_ARGS__)
#else
    #define CRITICAL(...)
#endif

// Define alert macros.
#if defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_ALERT
    #define ALERT(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Alert] ");DEBUGGER.println(__VA_ARGS__)
#else
    #define ALERT(...)
#endif

// Define emergency macros.
#if defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_EMERGENCY && defined(DEBUG_CONTINUE_ON_EMERGENCY)
    #define EMERGENCY(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Emergency] ");DEBUGGER.println(__VA_ARGS__)
#elif defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_EMERGENCY
    #define EMERGENCY(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Emergency] ");DEBUGGER.println(__VA_ARGS__);while(1)
#else
    #define EMERGENCY(...)
#endif

// Define fatal macros.
#if defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_FATAL && defined(DEBUG_CONTINUE_ON_FATAL)
    #define FATAL(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Fatal] ");DEBUGGER.println(__VA_ARGS__)
#elif defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_FATAL
    #define FATAL(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Fatal] ");DEBUGGER.println(__VA_ARGS__);while(1)
#else
    #define FATAL(...)
#endif

// Define panic macros.
#if defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_PANIC && defined(DEBUG_CONTINUE_ON_PANIC)
    #define PANIC(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Panic] ");DEBUGGER.println(__VA_ARGS__)
#elif defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_PANIC
    #define PANIC(...) _DEBUGGER_PRINT_MILLIS();DEBUGGER.print("[Panic] ");DEBUGGER.println(__VA_ARGS__);while(1)
#else
    #define PANIC(...)
#endif

// If debug level contains trace level then...
#if DEBUG_LEVEL >= DEBUG_LEVEL_TRACE
    // Define tracing macro.
    #define TRACING
#endif

// If debug level contains debug level then...
#if DEBUG_LEVEL >= DEBUG_LEVEL_DEBUG
    // Define debugging macro.
    #define DEBUGGING
#endif

// Define start debugger macro.
#if defined(DEBUGGER)
    #define START_DEBUGGER() DEBUGGER.begin(DEBUGGER_SPEED)
#else
    #define START_DEBUGGER(speed)
#endif

// Define wait for debugger macro.
#if defined(DEBUGGER) && DEBUG_LEVEL >= DEBUG_LEVEL_DEBUG
    #define WAIT_FOR_DEBUGGER() while(!DEBUGGER)
#else
    #define WAIT_FOR_DEBUGGER()
#endif

#endif // __DEBUG_H__
