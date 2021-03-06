#ifndef UNFL_DEBUG_H
#define UNFL_DEBUG_H

    /*********************************
             Settings macros
    *********************************/

    // Settings
    #define DEBUG_MODE        1   // Enable/Disable debug mode
    #define USE_FAULTTHREAD   1   // Create a fault detection thread 
    #define OVERWRITE_OSPRINT 1   // Replaces osSyncPrintf calls with debug_printf
    
    // Fault thread definitions
    #define FAULT_THREAD_ID    13
    #define FAULT_THREAD_PRI   251
    #define FAULT_THREAD_STACK 0x2000
    
    
    /*********************************
             Debug Functions
    *********************************/
    
    #if DEBUG_MODE
        // The accessible debug functions
        extern void debug_printf(const char* message, ...);
        extern void debug_screenshot(int size, int w, int h);
        #define debug_assert(expr) (expr) ? ((void)0) : _debug_assert(#expr, __FILE__, __LINE__)
        
        // Ignore these, use the macros instead
        extern void _debug_assert(const char* expression, const char* file, int line);
        
        // Include usb.h
        #include "usb.h"
    #else
        #define debug_printf(__VA_ARGS__) 
        #define debug_screenshot(a, b, c)
        #define debug_assert(a)
        #define usb_write(a, b, c)
        #define usb_read() 0
    #endif
    
#endif