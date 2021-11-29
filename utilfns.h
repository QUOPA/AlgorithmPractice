#pragma once

#include <iostream>
#include <vector>

template<typename T>
void showvector(const std::vector<T>& vectoshow);

template<typename T>
inline void showvector(const std::vector<T>& vectoshow)
{
	for (size_t idx = 0; idx < vectoshow.size(); ++idx)
		std::cout << vectoshow[idx] << ", ";
	std::cout << std::endl;
}
