#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[]) {
	std::cout << "value in argc:" << argc << std::endl;

	std::string input_file, output_file;

	for(int i=0;i<argc;i++){
		if(std::string(argv[i])=="-i"){
			input_file=argv[i+1];
		}

		if(std::string(argv[i])=="-o"){
			output_file=argv[i+1];
		}
	}

	std::cout<<"input file: "<<input_file<<std::endl;
	std::cout<<"output file: "<<input_file<<std::endl;

	std::ifstream source(input_file);

	std::vector<std::string> lines;
	std::string tmp;
	if(source.is_open()){
		while(getline(source,tmp)){
			lines.push_back(tmp);
		}
		source.close();
	}

	std::ofstream destination(output_file);

	if(destination.is_open()){
		for(int i=0;i<lines.size();i++){
			destination<<lines[i]<<"\n";
		}
		destination.close();
	}

	return 0;
}
