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

LDFLAGS = 
LIBFLAGS = -lpthread -lc -lrt \
			-L$(PROJECT_BIN_DIR)

SRC_DIR     = ./
BUILD_DIR   = ./build
BIN_DIR     = ./bin
INC_DIR     = ../include

$(shell mkdir -p $(BIN_DIR))
$(shell mkdir -p $(BUILD_DIR))

MYAPPNAME =

include includes.mk

SRCS    = $(wildcard $(SRC_DIR)/*.cpp)
OBJS    = $(addprefix $(BUILD_DIR)/, $(notdir $(SRCS:.cpp=.o)))
IDEPS    = $(wildcard $(INC_DIR)/*.h)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(IDEPS)
	$(EMCC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

.PHONY: all
all:
	echo "nothing to be done for coverage"

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
	rm -f $(BUILD_DIR)/* $(BIN_DIR)/*

.PHONY:	format
format:
	clang-format -i -style=file $(SRCS)
	clang-format -i -style="{IndentWidth: 4}" $(SRCS)
	clang-format -i -style=file $(IDEPS)
	clang-format -i -style="{IndentWidth: 4}" $(IDEPS)

