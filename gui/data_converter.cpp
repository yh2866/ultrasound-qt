#include "data_converter.h"
#include <QDebug>


void write_data(const char *file1, const char *file2)
{
    std::ifstream in_file;
    in_file.open(file1);
    std::ofstream out_file;
    out_file.open(file2);
    char buff;
    while (in_file.get(buff))
    {
        out_file << (uint8_t)buff;
    }
    in_file.close();
    out_file.close();
}

// read the file and return a 2d array of numbers.
std::vector<std::vector<int>> read_uint8_data(const char *file)
{
    std::vector<std::vector<int>> res;
    std::ifstream in_file;
    in_file.open(file);
    if(!in_file)
        qInfo() << "AAHAHHAHA!";
    char c;
    std::string line;
    // an extra get line to get rid of the starting "start data"
    std::getline(in_file, line);
    std::getline(in_file, line);
    int col = 0;
    int row = 0;
    while (!line.empty())
    {
        std::vector<int> v;
        int temp = 0;
        for (char& c : line)
        {
            v.push_back((int)c);
            temp++;
        }

        if (col != 0 && col != temp)
            break;
        col = temp;
        res.push_back(v);
        std::getline(in_file, line);
        row++;
    }
    in_file.close();
    return res;
}

Eigen::MatrixXd two_d_array_to_matrix(std::vector<std::vector<int>>& two_d_array)
{
    int row = two_d_array.size();
    int col = two_d_array[0].size();
    Eigen::MatrixXd m(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            m(i, j) = two_d_array[i][j];
    return m;
}
