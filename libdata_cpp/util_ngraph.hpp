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

#ifndef UTIL_NGRAPH_HPP_
#define UTIL_NGRAPH_HPP_

#include <fstream>

#include "type.hpp"

namespace libdata_cpp
{
    namespace ngraph
    {
        template <typename T, int N>
        void write_ngraph(const PointList<T, N>& points, const std::string& filename) {
            std::ofstream file(filename);
            if (!file) {
                std::cerr << "ファイルを開けませんでした: " << filename << std::endl;
                return;
            }

            file << "%Ngraph GRAF\n";
            file << "%Creator: Ngraph ver 6.00.01\n";
            
            file << "I,5,0,0,21000,29700,10000\n";
            file << "V,5,0,0,21000,29700,1\n";
            file << "G,4,0,0,0,0\n";
            file << "A,5,0,100,0,0,1000\n";
            
            if (N == 2) {
                if (!points.points.empty()) {
                    const auto& first_point = points.points[0];
                    file << "M,2," << first_point.coords[0] << "," << first_point.coords[1] << "\n";

                    for (size_t i = 1; i < points.points.size(); ++i) {
                        const auto& point = points.points[i];
                        file << "L,4,"
                            << first_point.coords[0] << "," << first_point.coords[1] << ","
                            << point.coords[0] << "," << point.coords[1] << "\n";
                    }
                }
            } else {
                for (const auto& point : points.points) {
                    file << "P,2," << point.coords[0] << "," << point.coords[1] << "\n";
                }
            }
                
            file << "E,0\n";
            
            file.close();
        }
    } // namespace ngraph
} // namespace libdata_cpp

#endif