TEMPLATE = subdirs

SUBDIRS += \
    abalonecore \
    tui #\
    #tests

tui.depends = abalonecore
#src-tui.depends = src/abalonecore
#tests.depends = src/abalonecore

OTHER_FILES += config.pri
