TEMPLATE = subdirs

SUBDIRS += \
    abalone-core \
    abalone-GUI \
    abalone-TUI
    #tests

#abalone-GUI.depends = abalone-core
#abalone-TUI.depends = abalone-core

#src-tui.depends = src/abalonecore
#tests.depends = src/abalonecore

OTHER_FILES += config.pri
