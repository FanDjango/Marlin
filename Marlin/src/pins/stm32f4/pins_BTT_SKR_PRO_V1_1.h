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
// Swap the Runout pins - it is connected to PE10
//
#define FIL_RUNOUT_PIN                      PE10   // ���� was PE15
#define FIL_RUNOUT2_PIN                     PE15   // ���� was PE10

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
#undef X_MAX_PIN
#define X_MAX_PIN                           PB10
#undef X_MIN_PIN
//#define X_MIN_PIN                           PE15 // free for use, it is the X_MAX socket

// Y homes to the MAX end.
// The YMAX switch is plugged in to the YMIN socket on the board, so LED indicators work
// Thus Y_MAX_PIN is set to PE12, physically the Y_MIN socket.
// The Y_MAX socket, PE10, is free and can be used for anything.
#undef Y_MAX_PIN
#define Y_MAX_PIN                           PE12
#undef Y_MIN_PIN
//#define Y_MIN_PIN                           PE10 // used by FILAMENT_RUNOUT_SENSOR, it is the Y_MAX socket

// Z homes to the MAX end. Currently not used becasue homing to min with probe
// The ZMAX switch is plugged in to the ZMIN socket on the board, so LED indicators work
// Thus Z_MAX_PIN is set to PG8, physically the Z_MIN socket.
// The Z_MAX socket, PG5, is free and can be used for anything.
#undef Z_MAX_PIN
//#define Z_MAX_PIN                           PG8
#undef Z_MIN_PIN
//#define Z_MIN_PIN                           PG5  // free for use, it is the Z_MAX socket

// My board, I don't use the on-board lcd
#undef  SDCARD_CONNECTION
#define SDCARD_CONNECTION                  LCD

// My board, wired differently by me, somehow the pin headers are different too...
// ...compared with the definitions in pins_BTT_SKR_PRO_common.h
/*
 * (BEEPER) PG4  |10  9 | PA8  (BTN_ENC)         (MISO) PB14 |10  9 | PB13 (SCK)
 * (LCD_EN) PD11 | 8  7 | PD10 (LCD_RS)       (BTN_EN1) PG10 | 8  7 | PB12 (SD_SS)
 * (LCD_D4) PG2    6  5 | PG3  (LCD_D5)       (BTN_EN2) PF11   6  5 | PB15 (MOSI)
 * (LCD_D6) PG6  | 4  3 | PG7  (LCD_D7)     (SD_DETECT) PF12 | 4  3 | RESET
 *          GND  | 2  1 | 5V                            GND  | 2  1 | NC
 *                ------                                      ------
 *                 EXP1                                        EXP2
 */
#undef  EXP1_03_PIN
#define EXP1_03_PIN                         PG7

#undef  EXP1_04_PIN
#define EXP1_04_PIN                         PG6

#undef  EXP1_05_PIN
#define EXP1_05_PIN                         PG3

#undef  EXP1_06_PIN
#define EXP1_06_PIN                         PG2

#undef  EXP1_07_PIN
#define EXP1_07_PIN                         PD10

#undef  EXP1_08_PIN
#define EXP1_08_PIN                         PD11

#undef  EXP1_09_PIN
#define EXP1_09_PIN                         PA8

#undef  EXP1_10_PIN
#define EXP1_10_PIN                         PG4


#undef  EXP2_03_PIN
#define EXP2_03_PIN                         -1

#undef  EXP2_04_PIN
#define EXP2_04_PIN                         PF12

#undef  EXP2_05_PIN
#define EXP2_05_PIN                         PB15

#undef  EXP2_06_PIN
#define EXP2_06_PIN                         PF11

#undef  EXP2_07_PIN
#define EXP2_07_PIN                         PB12

#undef  EXP2_08_PIN
#define EXP2_08_PIN                         PG10

#undef  EXP2_09_PIN
#define EXP2_09_PIN                         PB13

#undef  EXP2_10_PIN
#define EXP2_10_PIN                         PB14

#undef  SD_DETECT_PIN
#define SD_DETECT_PIN              EXP2_04_PIN

#undef  SDSS
#define SDSS                       EXP2_07_PIN







#define DIAG_PINS_REMOVED
#define NO_AUTO_ASSIGN_WARNING