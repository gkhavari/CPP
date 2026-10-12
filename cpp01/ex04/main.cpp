#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	const std::string filename(argv[1]);
	const std::string s1(argv[2]);
	const std::string s2(argv[3]);
	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty." << std::endl;
		return (1);
	}
	std::ifstream input(filename.c_str());
	if (!input)
	{
		std::cerr << "Error: cannot open input file '" << filename << "'." << std::endl;
		return (1);
	}
	//                           Most vexing parse |
	//                                             v
	const std::string content((std::istreambuf_iterator<char>(input)),
		std::istreambuf_iterator<char>());
	if (input.bad())
	{
		std::cerr << "Error: failed while reading input file '" << filename << "'." << std::endl;
		return (1);
	}
	input.close();

	std::string result;
	std::string::size_type cursor = 0;
	std::string::size_type match = content.find(s1, cursor);
	while (match != std::string::npos)
	{
		result.append(content, cursor, match - cursor);
		result.append(s2);
		cursor = match + s1.length();
		match = content.find(s1, cursor);
	}
	result.append(content, cursor, std::string::npos);

	const std::string outputFilename = filename + ".replace";
	std::ofstream output(outputFilename.c_str());
	if (!output)
	{
		std::cerr << "Error: cannot open output file '" << outputFilename << "'." << std::endl;
		return (1);
	}
	output << result;
	output.close();
	if (!output)
	{
		std::cerr << "Error: failed while writing output file '" << outputFilename << "'." << std::endl;
		return (1);
		
	}
	return (0);
}
