#include <perlin/perlin.h>

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
    if(argc < 3){
        std::cout << "Usage is " << argv[0] << " Octaves Dimension1 Dimension2 Dimension3..." << std::endl;
        return 0;
    }
    std::vector<std::string> args{argv+2, argv+argc};
    std::vector<int> dims;
    dims.resize(args.size());
    std::transform(args.begin(), args.end(), dims.begin(), [] (auto a) { return std::stoi(a);});
    Perlin ng{dims, std::stoi(argv[1])};
    std::string in;
    while(getline(std::cin, in)){
        std::istringstream numstring{in};
        std::vector<double> nums;
        nums.resize(dims.size());
        for(auto &num : nums)
            if(numstring)
                numstring >> num;
            else 
                num = 0;
        std::cout << ng(nums) << std::endl;
    }
    return 0;
}
