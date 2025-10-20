# Keymap for Boardsource Unicorne with 4 layers

Custom keymap for the Boardsource Unicorne split keyboard (3x6+3 layout).

## Why This Keymap?

The default Unicorne configuration has a critical issue: **`POINTING_DEVICE_ENABLE` and `ANALOG_JOYSTICK_ENABLE` are enabled by default**, causing the mouse pointer to move diagonally by itself even without a pointing device connected.

Additionally, the default firmware only supports 3 layers (0, 1, 2), and **the [QMK online configurator](https://config.qmk.fm/#/boardsource/unicorne/LAYOUT_split_3x6_3) cannot disable these features**.

#### This keymap solves both problems:
✅ Disables pointing device and joystick features in `rules.mk`
✅ Adds a 4th layer for system controls (RGB, media keys)
✅ Provides a clean, fully functional 4-layer layout

## Build & Flash

From this directory:

```bash
make compile     # Compile firmware (saves to build/)
make flash       # Flash to keyboard
make clean       # Clean QMK build artifacts
make build-clean # Clean local build/ directory
make help        # Show all commands
```

Compiled files (.uf2, .hex, .bin, .elf) are automatically copied to `build/` after compilation.

## Bootloader Mode

Enter bootloader to flash firmware:
1. **Bootmagic reset**: Hold top-left key and plug in keyboard
2. **Physical reset button**: Press button on back of PCB
3. **Keycode reset**: Press `QK_RBT` key (Layer 3, top-left)

## Layer Diagrams

### Layer 0: Base (QWERTY)
```
┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ ESC │  Q  │  W  │  E  │  R  │  T  │       │  Y  │  U  │  I  │  O  │  P  │BSPC │
├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
│SHIFT│  A  │  S  │  D  │  F  │  G  │       │  H  │  J  │  K  │  L  │  ;  │  '  │
├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
│CTRL │  Z  │  X  │  C  │  V  │  B  │       │  N  │  M  │  ,  │  .  │  /  │ TAB │
└─────┴─────┴─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │ GUI │ MO1 │ SPC │       │ ENT │ MO2 │ ALT │
                  └─────┴─────┴─────┘       └─────┴─────┴─────┘
```

### Layer 1: Numbers & Navigation (Hold left thumb key)
```
┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
│  `  │  1  │  2  │  3  │  4  │  5  │       │  6  │  7  │  8  │  9  │  0  │     │
├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │ F12 │     │       │ ←   │ ↓   │ ↑   │ →   │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │       │     │     │     │     │     │     │
└─────┴─────┴─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │ ### │     │       │     │ MO3 │     │
                  └─────┴─────┴─────┘       └─────┴─────┴─────┘
```

### Layer 2: Symbols (Hold right thumb key)
```
┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
│  ~  │  !  │  @  │  #  │  $  │  %  │       │  ^  │  &  │  *  │  (  │  )  │     │
├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │       │  -  │  +  │  [  │  ]  │  \  │     │
├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │       │  =  │  _  │  {  │  }  │  |  │     │
└─────┴─────┴─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │ MO3 │     │       │     │ ### │     │
                  └─────┴─────┴─────┘       └─────┴─────┴─────┘
```

### Layer 3: System Controls (Hold both MO1 + MO2)
```
┌─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┐
│UGTOG│UGNXT│UGHUE│UGSAT│UGVAL│UGSPD│       │     │BRI- │BRI+ │VOL- │VOL+ │MUTE │
├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
│RESET│UGPRV│UGHUD│UGSAD│UGVAD│UGSPD│       │     │     │     │     │STOP │PLAY │
├─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┤
│RMTOG│RMNXT│RMHUE│RMSAT│RMVAL│RMSPD│       │     │     │     │     │PREV │NEXT │
└─────┴─────┴─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │     │     │       │     │     │     │
                  └─────┴─────┴─────┘       └─────┴─────┴─────┘
```

**Legend:**
- `MO1/MO2/MO3` = Momentary layer activation
- `###` = Current layer hold key
- `UGTOG/NEXT/etc` = Underglow RGB controls
- `RMTOG/NEXT/etc` = RGB Matrix controls
- Empty cells = Transparent (passes through to lower layer)

## Features

- 4 customizable layers
- RGB underglow & matrix support
- Media controls on Layer 3
- Navigation arrows on Layer 1
- Complete symbol set on Layer 2

## Files

- `keymap.c` - Layout definition
- `keymaps/keymap.json` - JSON layout format
- `rules.mk` - Feature configuration
