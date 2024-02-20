import re

FNAME_CONFIG     = "Marlin/configuration.h"
FNAME_CONFIG_ADV = "Marlin/configuration_adv.h"

GET_C1 = ["NOZZLE_TO_PROBE_OFFSET"] 

GET_N = ["PROBING_MARGIN", 
         "X_BED_SIZE", "Y_BED_SIZE", 
         "X_MIN_POS", "X_MAX_POS", "Y_MIN_POS", "Y_MAX_POS"]

try:
    with open(FNAME_CONFIG) as f:
        print("BED SIZE, BED POSITION and PROBING AREA")
        print("=======================================")
        print()
        for line in f:
            line = line.strip()
            if line.startswith("//"):
                continue
            words = re.split(" +", line)
            if words[0] != "#define":
                continue
            if words[1] in GET_C1:
                print(line)
                s = words[1] + "_X = " + words[3].rstrip(",")
                print(s)
                exec(s)
                s = words[1] + "_Y = " + words[4].rstrip(",")
                print(s)
                exec(s)
                continue
            if words[1] in GET_N:
                print(line)
                s = words[1] + " = " + words[2]
                print(s)
                exec(s)
except IOError:
    print("Failed reading configuration.h")
    exit

print()
print("Reachable probing points")

Xrmin = round(max(X_MIN_POS + NOZZLE_TO_PROBE_OFFSET_X - 0.001, PROBING_MARGIN), 3)
Yrmin = round(max(Y_MIN_POS + NOZZLE_TO_PROBE_OFFSET_Y - 0.001, PROBING_MARGIN), 3)

Xrmax = round(min(X_MAX_POS + NOZZLE_TO_PROBE_OFFSET_X - 0.001, X_BED_SIZE - PROBING_MARGIN), 3)
Yrmax = round(min(Y_MAX_POS + NOZZLE_TO_PROBE_OFFSET_Y - 0.001, Y_BED_SIZE - PROBING_MARGIN), 3)

print()
print("Quadrant (Xmin,Ymin): ")
print("P = (", Xrmin, ",", Yrmin, ")")

print()
print("Quadrant (Xmax,Ymin): ")
print("P = (", Xrmax, ",", Yrmin, ")")

print()
print("Quadrant (Xmax,Ymax): ")
print("P = (", Xrmax, ",", Yrmax, ")")

print()
print("Quadrant (Xmin,Ymax): ")
print("P = (", Xrmin, ",", Yrmax, ")")

print()

dist = max(Xrmin, Yrmin, X_BED_SIZE - Xrmax, Y_BED_SIZE - Yrmax)
Xsmin = round(dist, 3)
Ysmin = round(dist, 3)

Xsmax = round(X_BED_SIZE - dist, 3)
Ysmax = round(Y_BED_SIZE - dist, 3)

print("Symmetric largest rectangle")

print()
print("Quadrant (Xmin,Ymin): ")
print("P = (", Xsmin, ",", Ysmin, ")")

print()
print("Quadrant (Xmax,Ymin): ")
print("P = (", Xsmax, ",", Ysmin, ")")

print()
print("Quadrant (Xmax,Ymax): ")
print("P = (", Xsmax, ",", Ysmax, ")")

print()
print("Quadrant (Xmin,Ymax): ")
print("P = (", Xsmin, ",", Ysmax, ")")

print("Now checking probe points requested in configs")            

GET_C2 = ["Z_STEPPER_ALIGN_XY"] 

GET_C4 = ["TRAMMING_POINT_XY"] 

try:
    with open(FNAME_CONFIG_ADV) as f:
        for line in f:
            line = line.strip()
            if line.startswith("//"):
                continue
            words = re.split(" +", line)
            if words[0] != "#define":
                continue
            if words[1] in GET_C2:
                print(line)
                s = words[1] + "_X_1 = " + words[4].rstrip(",")
                print(s)
                exec(s)
                s = words[1] + "_Y_1 = " + words[5].rstrip(",")
                print(s)
                exec(s)
                s = words[1] + "_X_2 = " + words[8].rstrip(",")
                print(s)
                exec(s)
                s = words[1] + "_Y_2 = " + words[9].rstrip(",")
                print(s)
                exec(s)
                continue
            if words[1] in GET_C4:
                print(line)
                s = words[1] + "_X_1 = " + words[4].rstrip(",")
                print(s)
                exec(s)
                s = words[1] + "_Y_1 = " + words[5].rstrip(",")
                print(s)
                exec(s)
                s = words[1] + "_X_2 = " + words[8].rstrip(",")
                print(s)
                exec(s)
                s = words[1] + "_Y_2 = " + words[9].rstrip(",")
                print(s)
                exec(s)
                s = words[1] + "_X_3 = " + words[12].rstrip(",")
                print(s)
                exec(s)
                s = words[1] + "_Y_3 = " + words[13].rstrip(",")
                print(s)
                exec(s)
                s = words[1] + "_X_4 = " + words[16].rstrip(",")
                print(s)
                exec(s)
                s = words[1] + "_Y_4 = " + words[17].rstrip(",")
                print(s)
                exec(s)
                break
except IOError:
    print("Failed reading configuration_adv.h")
    exit

if Z_STEPPER_ALIGN_XY_X_1 < Xrmin:
    print("Z_STEPPER_ALIGN_XY, First X out of range:", Z_STEPPER_ALIGN_XY_X_1, "< limit(", Xrmin, ")")
    exit(8)
if Z_STEPPER_ALIGN_XY_Y_1 < Yrmin:
    print("Z_STEPPER_ALIGN_XY, First Y out of range:", Z_STEPPER_ALIGN_XY_Y_1, "< limit(", Yrmin, ")")
    exit(8)	
if Z_STEPPER_ALIGN_XY_X_2 > Xrmax:
    print("Z_STEPPER_ALIGN_XY, 2nd X out of range:", Z_STEPPER_ALIGN_XY_X_2, "> limit(", Xrmax, ")")
    exit(8)
if Z_STEPPER_ALIGN_XY_Y_2 > Yrmax:
    print("Z_STEPPER_ALIGN_XY, 2nd Y out of range:", Z_STEPPER_ALIGN_XY_Y_2, "> limit(", Yrmax, ")")
    exit(8)

if TRAMMING_POINT_XY_X_1 < Xrmin:
    print("TRAMMING_POINT_XY, First X out of range:", TRAMMING_POINT_XY_X_1, "< limit(", Xrmin, ")")
    exit(8)
if TRAMMING_POINT_XY_Y_1 < Yrmin:
    print("TRAMMING_POINT_XY, First Y out of range:", TRAMMING_POINT_XY_Y_1, "< limit(", Yrmin, ")")
    exit(8)	
if TRAMMING_POINT_XY_X_2 > Xrmax:
    print("TRAMMING_POINT_XY, 2nd X out of range:", TRAMMING_POINT_XY_X_2, "> limit(", Xrmax, ")")
    exit(8)
if TRAMMING_POINT_XY_Y_2 > Yrmax:
    print("TRAMMING_POINT_XY, 2nd Y out of range:", TRAMMING_POINT_XY_Y_2, "> limit(", Yrmax, ")")
    exit(8)	
if TRAMMING_POINT_XY_X_3 < Xrmin:
    print("TRAMMING_POINT_XY, 3rd X out of range:", TRAMMING_POINT_XY_X_3, "< limit(", Xrmin, ")")
    exit(8)
if TRAMMING_POINT_XY_Y_3 < Yrmin:
    print("TRAMMING_POINT_XY, 3rd Y out of range:", TRAMMING_POINT_XY_Y_3, "< limit(", Yrmin, ")")
    exit(8)	
if TRAMMING_POINT_XY_X_4 > Xrmax:
    print("TRAMMING_POINT_XY, 4th X out of range:", TRAMMING_POINT_XY_X_4, "> limit(", Xrmax, ")")
    exit(8)
if TRAMMING_POINT_XY_Y_4 > Yrmax:
    print("TRAMMING_POINT_XY, 4th Y out of range:", TRAMMING_POINT_XY_Y_4, "> limit(", Yrmax, ")")
    exit(8)	