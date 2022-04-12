TARGET = ./main.out
TST_TARGET = ./tests.out
VALGRIND_LOG = "valgrind.log"

HDRS = \
	   project/include

SRCS = \
	   project/src/main.c \
	   project/src/check_for_exist.c \
	   project/src/create_matrix_from_file.c \
	   project/src/get_rows_cols.c \
	   project/src/get_set_elem.c \
	   project/src/matrix_sub.c \
	   project/src/matrix_transp.c \
	   project/src/matrix_sum.c \
	   project/src/matrix_mul.c \
	   project/src/matrix_mul_scalar.c \
	   project/src/make_matrix.c \
	   project/src/free_matrix.c
	   
	   
TST_HDRS = \
           project/include \
		   project/tests/include

TST_SRCS = \
           project/src/check_for_exist.c \
	       project/src/create_matrix_from_file.c \
	       project/src/get_rows_cols.c \
	       project/src/get_set_elem.c \
	       project/src/matrix_sub.c \
	       project/src/matrix_transp.c \
	       project/src/matrix_sum.c \
	       project/src/matrix_mul.c \
	       project/src/matrix_mul_scalar.c \
		   project/tests/src/*.c \
		   project/src/make_matrix.c

.PHONY: all check build test memtest testextra memtestextra rebuild clean

all: clean check build test memtest testextra memtestextra

check:
	./run_linters.sh

build: $(TARGET)

test: $(TST_TARGET)
	$(TST_TARGET)

memtest: $(TST_TARGET)
	./project/tests/memtest.sh ${TST_TARGET}

testextra: $(TST_TARGET)
	$(TST_TARGET) --with-extra

memtestextra: $(TST_TARGET)
	./project/tests/memtest.sh ${TST_TARGET} --with-extra

rebuild: clean build

$(TARGET): $(SRCS)
	$(CC) -Wall -Wextra -Werror $(addprefix -I,$(HDRS)) -o $(TARGET) $(CFLAGS) $(SRCS) -lm

$(TST_TARGET): $(TST_SRCS)
	$(CC) -Wall -Wextra -Werror $(addprefix -I,$(TST_HDRS)) -o $(TST_TARGET) $(CFLAGS) $(TST_SRCS) -lm

clean:
	rm -f $(TARGET) $(TST_TARGET) ${VALGRIND_LOG}
