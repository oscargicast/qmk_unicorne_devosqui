# Disable pointing device and analog joystick to fix cursor drift bug
# (Default unicorne firmware has these enabled causing diagonal cursor movement)
POINTING_DEVICE_ENABLE = no
ANALOG_JOYSTICK_ENABLE = no

# =============================================================================
# Display and Visual Features
# =============================================================================
OLED_ENABLE = yes  # Enable OLED displays on both halves
WPM_ENABLE  = yes  # Enable words-per-minute calculation for animations

# =============================================================================
# Build Optimization
# =============================================================================
LTO_ENABLE = yes  # Link Time Optimization to reduce firmware size

# =============================================================================
# Animation Source Files
# =============================================================================
SRC += animations/crab/crab.c
SRC += animations/utils/animation-utils.c
