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
// Limit Switches fix
// (only valid if not using SENSORLESS HOMING, see included _common file)
//

// X homes to the MAX end.
// The XMAX switch is plugged in to the XMIN socket on the board, so LED indicators work
// Thus X_MAX_PIN is set to PB10, physically the X_MIN socket.
// The X_MAX socket, PE15, is free and can be used for anything.
//
// X_MAX_PIN                           PB10
// X_MIN_PIN                           PE15 // free for use, it is the X_MAX socket
#undef X_STOP_PIN
#define X_STOP_PIN                     PB10


// Y homes to the MAX end.
// The YMAX switch is plugged in to the YMIN socket on the board, so LED indicators work
// Thus Y_MAX_PIN is set to PE12, physically the Y_MIN socket.
// The Y_MAX socket, PE10, is free and can be used for anything.
//
// Y_MAX_PIN                           PE12
// Y_MIN_PIN                           PE10 // used by FILAMENT_RUNOUT_SENSOR, it is the Y_MAX socket
#undef Y_STOP_PIN
#define Y_STOP_PIN                     PE12

// Z homes to the MAX end. Currently not used because homing to min with probe
// The ZMAX switch is plugged in to the ZMIN socket on the board, so LED indicators work
// Thus Z_MAX_PIN is set to PG8, physically the Z_MIN socket.
// The Z_MAX socket, PG5, is free and can be used for anything.
//
// Z_MAX_PIN                           PG8
// Z_MIN_PIN                           PG5  // free for use, it is the Z_MAX socket
#undef Z_STOP_PIN
#define Z_STOP_PIN                     PG8
                                            // define it for M43 compile to work.

// FANx: ../..        - inside 24V power supply
// FAN0: yellow/blue  - parts cooling fan
// FAN1: red/black    - extruder fan
// FAN2: red/black    - small controller fan under chassis

#define NO_AUTO_ASSIGN_WARNING
#define DIAG_PINS_REMOVED
