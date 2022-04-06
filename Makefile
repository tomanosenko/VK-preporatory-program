TARGET = ./main.out
TARGET_TEST = ./main_test.out
HDRS_DIR = project/include
HDRS_DIR_TEST = test/include

SRCS = \
       project/src/main.c \
	   project/src/personal_data_write.c \
	   project/src/transaction_write.c \
	   project/src/update_transaction_data.c 

SRCS_TEST = \
      mytests/src/main.c \
      mytests/src/my_test_utils.c \
	  mytests/src/is_equal.c

.PHONY: all build rebuild check test memtest clean

all: clean check test memtest

$(TARGET_TEST): $(SRCS_TEST)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR_TEST) -o $(TARGET_TEST) $(CFLAGS) $(SRCS_TEST)

$(TARGET): $(SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS)

build: $(TARGET)

rebuild: clean build

check:
	./run_linters.sh

test: $(TARGET)
	./btests/run.sh $(TARGET)

memtest: $(TARGET)
	./btests/run.sh $(TARGET) --memcheck

clean:
	rm -rf $(TARGET) *.dat

mytest: $(TARGET_TEST)
	./main_test.out $(TARGET_TEST)
	