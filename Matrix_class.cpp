
#include <iostream>
#include "Matrix_class.h"

template <typename T>
Matrix_class<T>::Matrix_class()
{
    std::cout << "Default constructor\n";
    m_row = 0;
    m_column = 0;

    m_p = nullptr;
}

template <typename T>
Matrix_class<T>::Matrix_class(int r, int c)
{
    m_row = r;
    m_column = c;

    m_p = new T * [m_row];

    for (int i = 0; i < m_row; i++)
    {
        m_p[i] = new T[m_column];
    }
}


template <typename T>
void Matrix_class<T>::setRow(int r)
{
    if (r <= 0)
    {
        throw std::invalid_argument("Invalid size");
    }
    m_row = r;
}


template <typename T>
int Matrix_class<T>::getRow()const
{
    return m_row;
}


template <typename T>
void Matrix_class<T>::setColumn(int c)
{
    if (c <= 0)
    {
        throw std::invalid_argument("Invalid size");
    }
    m_column = c;
}


template <typename T>
int Matrix_class<T>::getColumn()const
{
    return m_column;
}


template <typename T>
Matrix_class<T>::Matrix_class(const Matrix_class& ob)
{
    std::cout << "Copy constructor\n";
    this->m_row = ob.m_row;
    this->m_column = ob.m_column;

    this->m_p = new T * [m_row];

    for (int i = 0; i < m_row; i++)
    {
        this->m_p[i] = new T[m_column];
    }

    for (int i = 0; i < ob.m_row; i++)
    {
        for (int j = 0; j < ob.m_column; j++)
        {
            this->m_p[i][j] = ob.m_p[i][j];
        }
    }
}


template <typename T>
Matrix_class<T>::Matrix_class(Matrix_class&& ob)
{
    std::cout << "Move constructor\n";

    if (this != &ob)
    {
        this->m_row = ob.m_row;
        this->m_column = ob.m_column;

        this->m_p = ob.m_p;

        ob.m_row = 0;
        ob.m_column = 0;
        ob.m_p = nullptr;
    }
}


template <typename T>
Matrix_class<T>& Matrix_class<T>::operator=(const Matrix_class& ob)
{
    std::cout << "Assignment operator\n";

    if (this != &ob)
    {
        this->m_row = ob.m_row;
        this->m_column = ob.m_column;

        delete[] m_p;
        this->m_p = new T * [m_row];

        for (int i = 0; i < m_row; i++)
        {
            this->m_p[i] = new T[m_column];
        }

        for (int i = 0; i < ob.m_row; i++)
        {
            for (int j = 0; j < ob.m_column; j++)
            {
                this->m_p[i][j] = ob.m_p[i][j];
            }
        }
    }
    return *this;
}


template <typename T>
Matrix_class<T>& Matrix_class<T>::operator=(Matrix_class&& ob)
{
    std::cout << "Move " << __func__ << "\n";

    if (this != &ob)
    {
        for (int i = 0; i < this->m_row; i++)
        {
            delete[] this->m_p[i];
        }
        delete[] this->m_p;

        this->m_row = ob.m_row;
        this->m_column = ob.m_column;

        this->m_p = ob.m_p;

        ob.m_row = 0;
        ob.m_column = 0;
        ob.m_p = nullptr;
    }
    return *this;
}


template <typename T>
Matrix_class<T>::~Matrix_class()
{
    std::cout << "Destructor\n";

    for (int i = 0; i < m_row; i++)
    {
        delete[] m_p[i];
    }
    delete[] m_p;
}


template <typename T>
void Matrix_class<T>::initializeMatrix()
{
    for (int i = 0; i < m_row; i++)
    {
        for (int j = 0; j < m_column; j++)
        {
            m_p[i][j] = rand() % 100 + 1;
        }
    }
}


template <typename T>
void Matrix_class<T>::changeRows(int k, int g)
{
    for (int i = 0; i <= m_column; i++)
    {
        T tmp = m_p[k][i];
        m_p[k][i] = m_p[g][i];
        m_p[g][i] = tmp;
    }
}


template <typename T>
void Matrix_class<T>::changeColumns(int k, int g)
{
    for (int i = 0; i < m_row; i++)
    {
        T tmp = m_p[i][k];
        m_p[i][k] = m_p[i][g];
        m_p[i][g] = tmp;
    }
}


template <typename T>
void Matrix_class<T>::printMatrix()
{
    for (int i = 0; i < m_row; i++)
    {
        for (int j = 0; j < m_column; j++)
        {
            std::cout << "p[" << i << "][" << j << "] = " << m_p[i][j] << "\n";
        }
    }
}
