
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Matrix_class.h"
#include "Matrix_class.cpp"


int main()
{
    //read rows and columns from file
    std::ifstream fin;

    int n_file_in;
    int m_file_in;

    fin.open("input.txt", std::ifstream::in);
    if (fin.good()) {
        fin >> n_file_in >> m_file_in;
        std::cout << "n_file_in = " << n_file_in << " m_file_in = " << m_file_in << std::endl;
    }

    int n = n_file_in;
    int m = m_file_in;

    fin.close();

    //output to a file

    if (freopen("output.txt", "w", stdout))
    {
        std::cout << "Writing to a file succesfully\n";
    }
    else
    {
        std::cout << "Writing to a file failed\n";
        exit(1);
    }

    //end of writing to a file 

    Matrix_class<double> ob1(n, m);

    try {
        ob1.getRow();
        ob1.setRow(n);
    }
    catch (const std::invalid_argument ia)
    {
        std::cerr << ia.what() << std::endl;
    }

    try {
        ob1.getColumn();
        ob1.setColumn(m);
    }
    catch (const std::invalid_argument ia)
    {
        std::cerr << ia.what() << std::endl;
    }


    std::cout << "Before Swap\n";
    ob1.initializeMatrix();
    ob1.printMatrix();
    /*
    std::cout << "Swapping colums\n";
    ob1.changeColumns(0, 2);
    ob1.printMatrix();
    std::cout << "Swapping m_rows\n";
    ob1.changeRows(0, 2);
    ob1.printMatrix();*/

    Matrix_class<double> ob_cp(ob1);
    ob_cp.printMatrix();

    Matrix_class<std::string> m_ob(4, 5);
    m_ob = std::move(Matrix_class<std::string>(2, 3));

    Matrix_class<int> m_ob1 = std::move(Matrix_class<int>(6, 7));

    return 0;
}