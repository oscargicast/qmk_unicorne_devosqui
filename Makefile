KEYBOARD = boardsource/unicorne
KEYMAP = qmk_devosqui
FIRMWARE_NAME = boardsource_unicorne_qmk_devosqui

QMK_ROOT = ~/qmk_firmware
QMK_BUILD_DIR = $(QMK_ROOT)/.build
BUILD_OUTPUT = ./build

.PHONY: all compile flash clean lint build-clean help

all: compile

compile:
	@echo "Compiling firmware..."
	cd $(QMK_ROOT) && qmk compile -kb $(KEYBOARD) -km $(KEYMAP)
	@echo "Copying build artifacts to $(BUILD_OUTPUT)..."
	@mkdir -p $(BUILD_OUTPUT)
	@cp -f $(QMK_BUILD_DIR)/$(FIRMWARE_NAME).uf2 $(BUILD_OUTPUT)/ 2>/dev/null || true
	@cp -f $(QMK_BUILD_DIR)/$(FIRMWARE_NAME).hex $(BUILD_OUTPUT)/ 2>/dev/null || true
	@cp -f $(QMK_BUILD_DIR)/$(FIRMWARE_NAME).bin $(BUILD_OUTPUT)/ 2>/dev/null || true
	@cp -f $(QMK_BUILD_DIR)/$(FIRMWARE_NAME).elf $(BUILD_OUTPUT)/ 2>/dev/null || true
	@echo "Build complete! Firmware files in $(BUILD_OUTPUT)/"

flash:
	cd $(QMK_ROOT) && qmk flash -kb $(KEYBOARD) -km $(KEYMAP)

clean:
	cd $(QMK_ROOT) && qmk clean

build-clean:
	@echo "Cleaning local build directory..."
	@rm -rf $(BUILD_OUTPUT)
	@echo "Local build directory cleaned!"

lint:
	cd $(QMK_ROOT) && qmk lint -kb $(KEYBOARD) -km $(KEYMAP)

json2c:
	qmk json2c keymaps/keymap.json -o keymap.c

help:
	@echo "Commands available:"
	@echo "  make compile     - Compile the firmware and copy to build/"
	@echo "  make flash       - Flash the firmware to the keyboard"
	@echo "  make clean       - Clean QMK build artifacts"
	@echo "  make build-clean - Clean local build/ directory"
	@echo "  make lint        - Verify the code"
	@echo "  make json2c      - Convert keymaps/keymap.json to keymap.c"
	@echo "  make help        - Show this help"
