#
# global definitions
PROJECT_NAME = webasm
ifeq (, $(PROJECTS_BASE))
PROJECT_BASE = ${HOME}/projects/${PROJECT_NAME}
else
PROJECT_BASE = ${PROJECTS_BASE}/${PROJECT_NAME}
endif

PROJECT_BIN_DIR = $(PROJECT_BASE)/bin
PROJECT_INCLUDE_DIR = $(PROJECT_BASE)/include

BASICMATH_INTERFACE_DIR = $(PROJECT_INCLUDE_DIR)/basicMath

$(info PROJECT_BASE="$(PROJECT_BASE)")
$(info PROJECT_BIN_DIR="$(PROJECT_BIN_DIR)")
$(info PROJECT_INCLUDE_DIR="$(PROJECT_INCLUDE_DIR)")
$(info BASICMATH_INTERFACE_DIR="$(BASICMATH_INTERFACE_DIR)")

##
#global (common) settings
SHELL = /bin/sh
AR = ar
EMAR = emar
CC = g++
EMCC = emcc

DEFS =  -DLINUX=1
CFLAGSDEBUG = -std=c++2a -O0 -g3 -fmessage-length=0 -MMD -MP -fprofile-arcs -ftest-coverage
CFLAGSRELEASE = -std=c++2a -O0 -g3 -fmessage-length=0 -MMD -MP
#CFLAGSRELEASE = -std=c++2a -O0 -g3 -MMD -MP

$(info DEBUG="$(DEBUG)")
ifeq (TRUE, $(DEBUG))
CFLAGSTOUSE = $(CFLAGSDEBUG)
else
CFLAGSTOUSE = $(CFLAGSRELEASE)
endif
$(info CFLAGSTOUSE="$(CFLAGSTOUSE)")


