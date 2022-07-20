# Compiler Information
CC=gcc
CFLAGS=-Wall -g
EXEC=.exe

# Directories
SRC_DIR=src

BIN_DIR=bin
BIN=$(BIN_DIR)/recall$(EXEC)

DOC_DIR=docs
DOCS=$(wildcard $(docs)/*)

INCLUDE_DIR=$(SRC_DIR)/deps
INCLUDES=$(wildcard $(INCLUDE_DIR)/*.c)
HEADERS=$(patsubst $(INCLUDE_DIR)/%.c,$(INCLUDE_DIR)/%.h,$(INCLUDES))

EXT_DIR=$(SRC_DIR)/external
EXTERNALS=$(wildcard $(EXT_DIR)/*.c)
EXT_OBJS=$(patsubst $(EXT_DIR)/%.c,$(OBJ_DIR)/%.o,$(EXTERNALS))

TEST_DIR=test
TEST_BIN_DIR=$(TEST_DIR)/bin

OBJ_DIR=obj
OBJS=$(patsubst $(INCLUDE_DIR)/%.c,$(OBJ_DIR)/%.o,$(INCLUDES)) $(EXT_OBJS)

MAIN_SRC=$(SRC_DIR)/main.c

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(MAIN_SRC) $? -o $(BIN)

$(OBJ_DIR)/%.o: $(INCLUDE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(EXT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

/%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

externals: $(EXT_OBJS)

clean:
ifneq (, $(wildcard $(BIN)))
	del$(subst /,\\, $(BIN))
else 
	$(info > Binary executable already deleted)
endif

ifneq (, $(wildcard $(OBJS)))
	del$(subst /,\\, $(OBJS))
else
	$(info > Object files already deleted)
endif

ifneq (, $(wildcard *.zip))
	del $(SUBMISSION)
else
	$(info > Submission already deleted)
endif


test: $(TEST_BINS)

test__%: $(OBJ_DIR)/%.o
	$(CC) $(CFLAGS) $(EXT_OBJS) $(TEST_DIR)/$@.c -o $(TEST_BIN_DIR)/$@

submit:
	minizip -o $(SUBMISSION) $(BIN) $(INCLUDES) $(HEADERS) $(OBJS) $(MAIN_SRC) $(INCLUDED_MISC_FILES)
