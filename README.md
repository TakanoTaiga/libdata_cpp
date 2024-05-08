# libdata_cpp

## Example

```C++
#include "libdata_cpp/libdata_cpp.hpp"

#include <iostream>

int main()
{
    libdata_cpp::Point2List points2;
    points2.pushback({1, 2});
    points2.pushback({3, 4});
    points2.pushback({5, 6});

    std::cout << "2D Points:" << std::endl;
    for (const auto& point : points2.points) {
        point.show();
    }

    libdata_cpp::csv::write_points_to_csv(points2, "points2.csv");

    libdata_cpp::Point3List points3;
    points3.pushback({7, 8, 9});
    points3.pushback({10, 11, 12});
    points3.pushback({13, 14, 15});

    std::cout << "3D Points:" << std::endl;
    for (const auto& point : points3.points) {
        point.show();
    }
    libdata_cpp::ngraph::write_ngraph(points3, "points3.gra");

    return 0;
}
```
