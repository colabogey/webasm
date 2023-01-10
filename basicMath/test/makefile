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
LIBFLAGS = -lgtest -lgmock -lpthread -lc -lgcov -lrt

SRC_DIR     = ./
LIB_SRC_DIR     = ../src
BUILD_DIR   = ./build
BIN_DIR     = ./bin
INC_DIR		= ../include

include includes.mk

SRCS    = $(wildcard $(SRC_DIR)/*.cpp)
SRCS    += $(wildcard $(LIB_SRC_DIR)/*.cpp)
OBJS    = $(addprefix $(BUILD_DIR)/, $(notdir $(SRCS:.cpp=.o)))
IDEPS    = $(wildcard $(INC_DIR)/*.h)
MYTESTAPP	= basicMathTest

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(IDEPS)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: $(LIB_SRC_DIR)/%.cpp $(IDEPS)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

.PHONY: all
all: $(BIN_DIR)/$(MYTESTAPP)

$(BIN_DIR)/$(MYTESTAPP):	$(OBJS)
	$(CC) $(LDFLAGS) -o $(BIN_DIR)/$(MYTESTAPP) $(OBJS) $(LIBFLAGS)

.PHONY: coverage
coverage:
	$(BIN_DIR)/$(MYTESTAPP)
	lcov -c --directory $(BUILD_DIR) --output-file coverage.info
	genhtml coverage.info --output-directory coverage_out

.PHONY: test
test:
	$(BIN_DIR)/$(MYTESTAPP)

.PHONY: testclean
testclean:
	rm -f $(BUILD_DIR)/*.gcda $(BUILD_DIR)/*.gcno $(BIN_DIR)/$(MYTESTAPP)
	rm -rf coverage_out

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/* $(BIN_DIR)/*
	rm -rf coverage_out

.PHONY: format
format:
	clang-format -i -style=file $(SRCS)
	clang-format -i -style="{IndentWidth: 4}" $(SRCS)
	clang-format -i -style=file $(IDEPS)
	clang-format -i -style="{IndentWidth: 4}" $(IDEPS)

