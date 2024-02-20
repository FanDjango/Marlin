import time

FNAME = "Marlin/make_version.h"

build_num = None

DEF_BUILD_NUM = "#define BUILD_NUM "
DEF_BUILD_DATE = "#define BUILD_DATE "

def get_int(s_marker, line):
    _, _, s = line.partition(s_marker) # we want the part after the marker
    return int(s)

t = time.localtime()
date = "{0:02d}".format(t.tm_year-2000) + "{0:02d}".format(t.tm_mon) + "{0:02d}".format(t.tm_mday) 

print("Try reading make_version.h")
try:
    with open(FNAME) as f:
        print("Reading make_version.h")
        for line in f:
            if DEF_BUILD_NUM in line:
                build_num = get_int(DEF_BUILD_NUM, line)
                build_num += 1
                if build_num > 99:
                    build_num = 1
            if DEF_BUILD_DATE in line:
                build_date = get_int(DEF_BUILD_DATE, line)
                if int(date) != build_date:
                    build_num = 1
except IOError:
    print("Failed reading make_version.h")
    build_num = 1

with open(FNAME, 'w') as f:
    print("Writing make_version.h")
    f.write(DEF_BUILD_NUM + "%d\n" % build_num)
    f.write("#define BUILD_DATE %s\n" % date)
    f.write("\n")
    s = "%06s.%02d" % (date, build_num)
    f.write("#define COMPLETE_VERSION \"%s\"\n" % s)
