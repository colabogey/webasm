#!/usr/bin/make -f

PROJECT_NAME = webasm
ifeq (, $(PROJECT_BASE))
PROJECTS_BASE := ${HOME}/projects
PROJECT_BASE := ${PROJECTS_BASE}/${PROJECT_NAME}
endif

include $(PROJECT_BASE)/toplevel.mk

CFLAGS = $(CFLAGSTOUSE) \
	-Wall -Wno-unknown-pragmas -Wno-sign-compare \
	-Woverloaded-virtual -Wwrite-strings -Wno-unused \
	$(INCDIRS) $(DEFS)

LIBFLAGS =	-lbasicMath \
			-L$(PROJECT_BIN_DIR)

SRC_DIR     = ./
BUILD_DIR   = ./build
BIN_DIR     = ./bin
INC_DIR     = ../include

MYAPPNAME = basicMathControl

include includes.mk

SRCS    = $(wildcard $(SRC_DIR)/*.cpp)
OBJS    = $(addprefix $(BUILD_DIR)/, $(notdir $(SRCS:.cpp=.o)))
IDEPS    = $(wildcard $(INC_DIR)/*.h)

THREADS	=#	-sUSE_PTHREADS
EXPORTNAME	=#	-sEXPORT_NAME=ZZZ
MODULARIZE	=	-sMODULARIZE
METHODS_EXPORTED	=	-s EXPORTED_RUNTIME_METHODS=[ccall,cwrap]
#FUNCTIONS_EXPORTED	=	-sEXPORTED_FUNCTIONS=[_main,_myFunction]
FUNCTIONS_EXPORTED	=#	-sEXPORTED_FUNCTIONS=[_myFunction]
NO_EXIT_RUNTIME	=#	-s NO_EXIT_RUNTIME=1
EXIT_RUNTIME	=#	-s EXIT_RUNTIME=1
SHELL_FILE	=#	--shell-file html_template/shell_minimal.html
EXTENSION	=	.js

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(IDEPS)
	$(EMCC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $< 

.PHONY: all
all:    $(BIN_DIR)/$(MYAPPNAME)

$(BIN_DIR)/$(MYAPPNAME):	$(OBJS)
	$(EMCC) $(LDFLAGS) -o $(BIN_DIR)/$(MYAPPNAME)$(EXTENSION) $(OBJS) $(LIBFLAGS) \
    $(NO_EXIT_RUNTIME) $(METHODS_EXPORTED) $(MODULARIZE)

.PHONY: coverage
coverage:
	echo "nothing to be done for coverage"

.PHONY: test
test:
	echo "nothing to be done for test"

.PHONY: testclean
testclean:
	echo "nothing to be done for testclean"

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/* 
#	rm -f $(BUILD_DIR)/* $(BIN_DIR)/*.js $(BIN_DIR)/*.html $(BIN_DIR)/*.wasm

.PHONY:	format
format:
	clang-format -i -style=file $(SRCS)
	clang-format -i -style="{IndentWidth: 4}" $(SRCS)
	clang-format -i -style=file $(IDEPS)
	clang-format -i -style="{IndentWidth: 4}" $(IDEPS)

