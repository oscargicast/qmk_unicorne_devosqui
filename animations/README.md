# OLED Animations

Extensible animation system for the Unicorne split keyboard OLED displays.

## Current Animations

### Crab Animation
- **Location:** `animations/crab/`
- **Display:** Right (slave) half
- **Credit:** Original animation by [Marek Piechut](https://github.com/marekpiechut/qmk-animations)
- **Features:**
  - Idle animation when not typing
  - Running animation when typing fast (>45 WPM)
  - 12 frames total (6 idle + 6 running)
  - 72x32 pixel frames

## Folder Structure

```
animations/
├── README.md           # This file
├── crab/              # Crab animation
│   ├── crab.c
│   └── crab.h
└── utils/             # Shared animation utilities
    ├── animation-utils.c
    └── animation-utils.h
```

## How Animations Work

1. **Animation files** (`crab/crab.c`): Contains bitmap frame data and rendering logic
2. **Utility files** (`utils/`): Provides shared functions like WPM detection and frame rendering
3. **Keymap integration** (`../keymap.c`): Calls `oled_render_anim()` on slave half
4. **Configuration** (`../config.h`): OLED timeout, brightness settings
5. **Build system** (`../rules.mk`): Enables features and includes source files

## Adding New Animations

### Step 1: Create Animation Folder

```bash
mkdir animations/your_animation
```

### Step 2: Add Animation Files

Place your `.c` and `.h` files in the new folder. Your header should define:

```c
#pragma once
#define ANIM_SCROLL true
#define ANIM_FRAME_WIDTH 72
#define ANIM_SIZE 288
#define ANIM_BOUNCE true

void oled_render_anim(void);
```

### Step 3: Update rules.mk

```makefile
# Enable your animation
YOUR_ANIMATION_ENABLE = yes

# Add source files
SRC += animations/your_animation/your_animation.c

# Add to search path
VPATH += animations/your_animation
```

### Step 4: Update keymap.c

```c
#ifdef YOUR_ANIMATION_ENABLE
#include "animations/your_animation/your_animation.h"
#endif
```

### Step 5: Call in OLED Task

In `oled_task_user()`, call your animation's render function on the desired half.

## Animation Configuration

Configured in `utils/animation-utils.h`:

- `ANIM_RENDER_WPM`: Show WPM counter (default: `true`)
- `FAST_TYPE_WPM`: WPM threshold for fast animation (default: `45`)
- `ANIM_INVERT`: Invert colors (default: `false`)
- `ANIM_FRAME_TIME`: Frame duration in ms (default: `250`)

## Requirements

- `OLED_ENABLE = yes` in rules.mk
- `WPM_ENABLE = yes` for typing-aware animations
- `LTO_ENABLE = yes` recommended to reduce firmware size
- OLED displays on both keyboard halves

## Available Animations from Source Repo

From [mctechnology17/qmk-config](https://github.com/mctechnology17/qmk-config):
- **Crab** ✅ (currently enabled)
- **Luna/Dog**
- **Demon**
- **Bongocat**
- **Ocean Dream**
- **Music Bars**

To add any of these, download the files and follow the steps above.

## Credits

- Original animations: Various QMK community members
- Compilation and integration: [mctechnology17](https://github.com/mctechnology17)
- Crab/Demon/Music-bars: [Marek Piechut](https://github.com/marekpiechut/qmk-animations)

## License

All animation files inherit their original licenses (GPL-2.0+ or MIT). See individual files for details.
