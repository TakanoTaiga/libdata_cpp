// Copyright 2024 Taiga Takano
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef UTIL_CSV_HPP_
#define UTIL_CSV_HPP_

#include <fstream>

#include "type.hpp"

namespace libdata_cpp
{
    namespace csv
    {
        template <typename T, int N>
        void write_points_to_csv(const PointList<T, N>& points, const std::string& filename) {
            std::ofstream file(filename);
            if (!file) {
                std::cerr << "Failed to open the file: " << filename << std::endl;
                return;
            }

            for (const auto& point : points.points) {
                for (int i = 0; i < N; ++i) {
                    file << point.coords[i];
                    if (i < N - 1) file << ", ";
                }
                file << "\n";
            }

            file.close();
        }
    } // namespace csv
    
    
} // namespace libdata_cpp

#endif