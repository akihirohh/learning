#include<iostream>
#include<vector>

int main(int argc, char* argv[])
{
    std::cout << "Learning\n";
    std::vector< std::vector<double> > vec(4, std::vector<double>(20));

    vec[0][1] = 100;
    vec[1][2] = 100;
    vec[2][3] = 100;
    vec[3][4] = 100;
    for (int row = 0; row < vec.size(); row++)
    {
        std::cout << "\nRow: " << row << "\t";
        for (int col = 0; col < vec[0].size(); col++)
        {
            std::cout << vec[row][col] << "|";
        }
    }
    std::cout << std::endl;
}
