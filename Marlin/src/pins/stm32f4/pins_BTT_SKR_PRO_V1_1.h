/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#if HOTENDS > 3 || E_STEPPERS > 3
  #error "BIGTREE SKR Pro V1.1 supports up to 3 hotends / E steppers."
#endif

#define BOARD_INFO_NAME "BTT SKR Pro V1.1"

//
// Relay V1.2 Power Signal Set to LOW for Power OFF
//
#define PS_ON_PIN                           PF5    // This is the T2 Pin

//
// I2C EEPROM AT24C256
//
#define I2C_EEPROM
#define MARLIN_EEPROM_SIZE 0x7FFF                  // EEPROM end address AT24C256 (32kB)
#undef NO_EEPROM_SELECTED

#include "pins_BTT_SKR_PRO_common.h"

//
// Limit Switches on my printer
//

// X homes to the MAX end.
// The XMAX switch is plugged in to the XMIN socket on the board, so LED indicators work
//
// X MIN SOCKET used for x_max_switch  PB10
// X MAX SOCKET used for ____free____  PE15 // free for use
//
#undef X_OTHER_PIN

// Y homes to the MAX end.
// The YMAX switch is plugged in to the YMIN socket on the board, so LED indicators work
//
// Y MIN SOCKET used for y_max_switch  PE12
// Y MAX SOCKET used for ____free____  PE10 // free for use
//
#undef Y_OTHER_PIN

// Z used to home to the MAX end. Currently not used because homing to min with probe
// The ZMAX switch is still plugged in to the ZMIN socket on the board, so LED indicators work
//
// Z MIN SOCKET used for z_max_switch  PG8
// Z MAX SOCKET used for ____free____  PG5 // free for use
//
#undef Z_OTHER_PIN

#undef FIL_RUNOUT2_PIN
#undef FIL_RUNOUT3_PIN


// FANx: ../..        - inside 24V power supply
// FAN0: yellow/blue  - parts cooling fan
// FAN1: red/black    - extruder fan
// FAN2: red/black    - small controller fan under chassis

// Second Z stepper is on the E1 stepper port, so no need to define Z2_STEP_PIN, Z2_DIR_PIN, Z2_ENABLE_PIN
#define NO_AUTO_ASSIGN_WARNING

// We don't use the DIAG pins for sensorless homing
#define DIAG_PINS_REMOVED
