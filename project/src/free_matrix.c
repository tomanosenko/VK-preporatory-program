
#include <stdlib.h>
#include "matrix.h"

free_matrix(Matrix* matrix) {
    free(matrix->value);
}
