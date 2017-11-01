#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <Eigen>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

#define PI 3.1415926
#define MAXBUFSIZE ((int) 1e6)

Eigen::MatrixXd oned_to_twod(const std::vector<int>&);

std::vector<float> linspace(const float&, const float&, const int&);

std::vector<int> split_string(const std::string&);

Eigen::MatrixXd read_data(const char*);

std::vector<Eigen::MatrixXd> cart_to_polar(Eigen::MatrixXd&);

#endif // PROCESS_H
