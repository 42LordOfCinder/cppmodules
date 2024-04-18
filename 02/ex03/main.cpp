#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main( void ) {
	std::cout << "Triangle {(1, 1); (3, 1); (1, 3)}:" << std::endl;
	std::cout << "\tPoint(4, 1) (Outside): " << bsp(Point(1, 1), Point(3, 1), Point(1, 3), Point(4, 1)) << std::endl;
	std::cout << "\tPoint(3, 1) (Vertex): " << bsp(Point(1, 1), Point(3, 1), Point(1, 3), Point(3, 1)) << std::endl;
	std::cout << "\tPoint(1, 2) (Edge): " << bsp(Point(1, 1), Point(3, 1), Point(1, 3), Point(1, 2)) << std::endl;
	std::cout << std::endl;
	std::cout << "Triangle {(2, 2); (4, 5); (8, 2)}:" << std::endl;
	std::cout << "\tPoint(1, 2) (Outside): " << bsp(Point(2, 2), Point(4, 5), Point(8, 2), Point(1, 2)) << std::endl;
	std::cout << "\tPoint(4, 3) (Inside): " << bsp(Point(2, 2), Point(4, 5), Point(8, 2), Point(4, 3)) << std::endl;
	std::cout << "\tPoint(6, 3) (Inside): " << bsp(Point(2, 2), Point(4, 5), Point(8, 2), Point(6, 3)) << std::endl;
	std::cout << std::endl;
	std::cout << "Triangle {(0, 0); (0, 5); (5, 0)}:" << std::endl;
	std::cout << "\tPoint(0, 2) (Edge): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 2)) << std::endl;
	std::cout << "\tPoint(2, 2) (Inside): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(2, 2)) << std::endl;
	std::cout << "\tPoint(3, 3) (Outside): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(3, 3)) << std::endl;
	return 0;
}
