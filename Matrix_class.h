
#ifndef MATRIX_CLASS_H
#define MATRIX_CLASS_H

template <typename T>

class Matrix_class {

private:
    T** m_p;
    int m_row;
    int m_column;
public:
    Matrix_class();
    Matrix_class(int, int);
    Matrix_class(const Matrix_class& ob);
    Matrix_class& operator=(const Matrix_class& ob);
    Matrix_class(Matrix_class&& ob);
    Matrix_class& operator=(Matrix_class&& ob);
    ~Matrix_class();
    void changeRows(int, int);
    void changeColumns(int, int);
    void printMatrix();
    void initializeMatrix();
    void setRow(int);
    int getRow()const;
    void setColumn(int);
    int getColumn()const;
};

#endif