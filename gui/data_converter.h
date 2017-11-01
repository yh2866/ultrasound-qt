#ifndef DATA_CONVERTER_H
#define DATA_CONVERTER_H

#include "process.h"

void write_data(const char*, const char*);

std::vector<std::vector<int>> read_uint8_data(const char*);

Eigen::MatrixXd two_d_array_to_matrix(std::vector<std::vector<int>>& two_d_array);

#endif // DATA_CONVERTER_H
