# Progress Log for Matrix Project

## Reading Project Description

`@2024-10-09`

> A **matrix** is a collection of numbers arranges in a fixed number of rows and columns


```
    1 2 3
A = 4 5 6
    7 8 9
```

A[1,1]=1

> The first index is the ROW number
> The second index is the COLUMN number

> **The order*** of the matrix is the number of its rows or columns | *размер матрицы* |

> **The main diagonal** of a square matrix is the diagonal from the upper left to the lower right corner | *главная диагональ* |

> **A rectangular matrix** is a matrix with the number of rows not equal to the number of columns

> **A square matrix** is a matrix with the number of rows equal to the number of columns

> **A column matrix** is a matrix with only one column | *строчный вектор* |:


```
    (1,1)
A = (2,1)
    (n,1)
```

> **A row matrix** is a matrix that has only one row:

```
A = (1,1) (1,2) (1,m)
```

> 💡 *a column matrix and a row matrix are also often called **vectors***

> **A diagonal matrix** is a square matrix in which all elements outside the main diagonal are zero.

> **An identity matrix** is a diagonal matrix with all diagonal elements equal to one:

```
    1 0 0
A = 0 1 0
    0 0 1
```

> **A triangular matrix** is a square matrix with all elements on one side of the main diagonal equal to zero:

```
    1 2 3
A = 0 4 5
    0 0 6
```

### Matrix structure in C language

```c
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
```

### Matrix operations

All operations (except matrix comparison) should return the resulting code:

* 0 - OK
* 1 - Error, incorrect matrix
* 2 - Calculation error (mismatched matrix sizes; matrix for which calculations cannot be performed)

### Creating matrices (create_matrix)

```c
int s21_create_matrix(int rows, int columns, matrix_t *result);
```
