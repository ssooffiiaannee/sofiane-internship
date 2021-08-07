#include <iostream>
#include <fstream>
#include "include/nlohmann/json.hpp"

using json = nlohmann::json;
using std::cout;
using std::endl;


int main(int argc, char const *argv[])
{
	std::ifstream i("ex.json");        // create an input file stream reading the file ex.json
	json j;                                // create a json container
	i >> j;                                // deserialize from input file stream
	cout << j["data_1"] << endl;       // output: 4
    cout << j["data_array"][2] << endl; // output: 5

	return 0;
}
