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

#ifndef TYPE_HPP_
#define TYPE_HPP_

#include <cstdint>
#include <vector>
#include <iostream>

namespace libdata_cpp
{
    template <typename T, int N>
    struct Point 
    {
        T coords[N];
        static constexpr int size = N;

        void show() const
        {
            for (int i = 0; i < N; ++i)
                std::cout << coords[i] << (i < N - 1 ? ", " : "\n");
        }
    };

    template <typename T, int N>
    struct PointList
    {
        std::vector<Point<T, N>> points;

        void pushback(const T (&coords)[N])
        {
            Point<T, N> p;
            for (int i = 0; i < N; ++i) {
                p.coords[i] = coords[i];
            }
            points.push_back(p);
        }

        size_t size() const
        {
            return points.size();
        }
    };

    using Point2List = PointList<double, 2>;
    using Point3List = PointList<double, 3>;
} // namespace libdata_cpp

#endif // TYPE_HPP_
