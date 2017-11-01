#include "process.h"

// Convert 1d matrix to 2d with equal number of x and y entries.
Eigen::MatrixXd oned_to_twod(const std::vector<int> &arr)
{
    int size = sizeof(arr) / sizeof(arr[0]);
    Eigen::MatrixXd res((int)sqrt(size), (int)sqrt(size));
    for(int i=0; i<size; i++)
    {
        int row_ind = i / (int)sqrt(size);
        int col_ind = i % (int)sqrt(size);
        res(row_ind, col_ind) = arr[i];
    }
    return res;
}

// Split an interval with begin and end values evenly.
std::vector<float> linspace(const float &begin, const float &end, const int &count)
{
    std::vector<float> res(count);
    for (int i = count-1; i >= 0; i--)
    {
        res[i] = begin + i * (end-begin) / (float)count;
    }
    return res;
}

// TODO: Adapt the type of element we receive, which is
// not an integer as what we have expected.
std::vector<int> split_string(const std::string &s)
{
    if (s.length() == 0)
        throw "String length cannot be 0";
    std::istringstream is(s);
    std::vector<int> res;
    int num;
    while (is >> num)
    {
        res.push_back(num);
    }
    return res;
}

// Read data from a file line by line, then return the matrix
// Exception for different number of elements each row is
// handled.
Eigen::MatrixXd read_data(const char *file)
{
    int rows = 0;
    int cols = 0;
    std::ifstream infile;
    infile.open(file);
    std::string line;
    std::getline(infile, line);
    std::vector<std::vector<int>> copy;
    while (!line.empty())
    {
        rows++;
        std::vector<int> row = split_string(line);
        try
        {
            if (cols != 0 && cols != row.size())
                throw std::string("ERROR: Data given has different number of elements on each row");
        }
        catch (std::string &s)
        {
            std::cerr << s << std::endl;
            exit(0);
        }
        cols = row.size();
        copy.push_back(row);
        std::getline(infile, line);
    }
    infile.close();
    std::cout << "hahaha" << std::endl;
    Eigen::MatrixXd res(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            res(i, j) = copy.at(i).at(j);
    return res;
}

// Major function that transfer cartesian coordinate to
// polar coordinate, with x,y indices of each corresponding
// point.
// Return value is a vector of 3 matrices:
// 1. x_coordinates
// 2. y_coordinates
// 3. value
std::vector<Eigen::MatrixXd> cart_to_polar(Eigen::MatrixXd &matrix)
{
    int rows = matrix.rows();
    int cols = matrix.cols();
    float radius_min = 1;
    float radius_max = 300;
    float angle = 55;
    float angle_left_side = angle / -(float)2;
    float angle_right_side = angle / (float)2;

    float step_theta = angle / (float)(rows - 1);
    float step_r = (radius_max - radius_min) / (float)(cols - 1);

    std::vector<float> radius = linspace(radius_min, radius_max, rows);
    std::vector<float> angles = linspace(angle_left_side, angle_right_side, cols);

    // These two matrices are the final outcome we want.
    Eigen::MatrixXd x_coordinate(rows, cols);
    Eigen::MatrixXd y_coordinate(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            float r_val = radius[i];
            float theta_val = angles[j];
            x_coordinate(i, j) = -r_val * cos(theta_val * PI/float(180)) - radius_min;
            y_coordinate(i, j) = -r_val * sin(theta_val * PI/float(180)) - radius_min;
        }
    }
    std::vector<Eigen::MatrixXd> res;
    res.push_back(x_coordinate);
    res.push_back(y_coordinate);
    res.push_back(matrix);
    return res;
}
