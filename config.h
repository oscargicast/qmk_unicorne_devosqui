#pragma once

#ifdef OLED_ENABLE
    #define OLED_TIMEOUT 30000      // Screen timeout after 30 seconds of inactivity
    #define OLED_BRIGHTNESS 160     // Brightness level (0-255)
    #define SPLIT_OLED_ENABLE       // Enable OLED on both keyboard halves
    #define SPLIT_WPM_ENABLE        // Sync WPM data between master and slave
#endif
