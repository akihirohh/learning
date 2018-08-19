#include "vectors.h"

int main(int argc, char* argv[])
{
	std::vector<double> v;
	for (int i = 0; i < 5; i++) v.push_back(i);
	Learning learn;
	learn.prev_d_vec = {v, v};
	for(int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << learn.prev_d_vec[i][j] << "\t";
		}
	}

}