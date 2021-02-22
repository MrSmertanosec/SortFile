#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <ctime>

//ifstream testFile("test.file", ios::binary);
//const auto begin = myfile.tellg();
//testFile.seekg(0, ios::end);
//const auto end = testFile.tellg();
//const auto fsize = (end - begin);

int main()
{
	std::srand(time(0));

	std::fstream file("test.txt");
	file.close();
	file.open("test.txt", std::ios::app);

	std::ifstream fileRead;
	fileRead.open("test.txt", std::ios::binary);
	auto begin = file.tellg();
	fileRead.seekg(0, std::ios::end);
	auto end = fileRead.tellg();
	auto fsize = (end - begin);
	
	while (fsize < 102400)
	{
		file << (rand() % 10000) + 1 << "\n";
	
		file.close();
		file.open("test.txt", std::ios::app);
	
		begin = file.tellg();
		fileRead.seekg(0, std::ios::end);
		end = fileRead.tellg();
		fsize = (end - begin);
	
		std::cout << fsize << "\n";
	}

	file.close();
	std::string line;
	std::multiset<int> ints;
	
	int fileIndex = 1;
	file.open("test.txt");
	
	while(std::getline(file, line))
	{
		if (ints.size() * 4 >= 17000)
		{
			std::stringstream ss;
			ss << "test" << fileIndex << ".txt";
			++fileIndex;
	
			std::fstream frame(ss.str(), std::ios::out);
	
			for (auto it = ints.begin(); it != ints.end(); ++it)
			{
				frame << *it << "\n";
			}
	
			ints.clear();
			frame.close();
	
		}
	
		ints.insert(std::stoi(line));
	}
	
	std::stringstream ss;
	ss << "test" << fileIndex << ".txt";
	++fileIndex;
	
	std::fstream frame(ss.str(), std::ios::out);
	
	for (auto it = ints.begin(); it != ints.end(); ++it)
	{
		frame << *it << "\n";
	}
	
	ints.clear();
	frame.close();
	file.close();

	std::fstream res;
	res.open("result.txt", std::ios::out);
	std::fstream frame1;
	frame1.open("test1.txt");
	std::string line1;
	std::fstream frame2;
	frame2.open("test2.txt");
	std::string line2;
	std::fstream frame3;
	frame3.open("test3.txt");
	std::string line3;
	std::fstream frame4;
	frame4.open("test4.txt");
	std::string line4;
	std::fstream frame5;
	frame5.open("test5.txt");
	std::string line5;
	std::getline(frame1, line1);
	std::getline(frame2, line2);
	std::getline(frame3, line3);
	std::getline(frame4, line4);
	std::getline(frame5, line5);
	
	while (1)
	{
		if (line1.empty() && line2.empty() && line3.empty()
			&& line4.empty() && line5.empty())
		{
			break;
		}
		
		int f1;
		int f2;
		int f3;
		int f4;
		int f5;
		if (line1.empty())
			f1 = 100000;
		else
			f1 = std::stoi(line1);
		if (line2.empty())
			f2 = 100000;
		else
			f2 = std::stoi(line2);
		if (line3.empty())
			f3 = 100000;
		else
			f3 = std::stoi(line3);
		if (line4.empty())
			f4 = 100000;
		else
			f4 = std::stoi(line4);
		if (line5.empty())
			f5 = 100000;
		else
			f5 = std::stoi(line5);

		if (f1 <= f2 && f1 <= f3 && f1 <= f4 && f1 <= f5)
		{
			res << f1 << "\n";
			std::getline(frame1, line1);
			continue;
		}

		if (f2 <= f1 && f2 <= f3 && f2 <= f4 && f2 <= f5)
		{
			res << f2 << "\n";
			std::getline(frame2, line2);
			continue;
		}

		if (f3 <= f2 && f3 <= f1 && f3 <= f4 && f3 <= f5)
		{
			res << f3 << "\n";
			std::getline(frame3, line3);
			continue;
		}

		if (f4 <= f2 && f4 <= f3 && f4 <= f1 && f4 <= f5)
		{
			res << f4 << "\n";
			std::getline(frame4, line4);
			continue;
		}

		if (f5 <= f2 && f5 <= f3 && f5 <= f4 && f5 <= f1)
		{
			res << f5 << "\n";
			std::getline(frame5, line5);
			continue;
		}
	}

	res.close();
	return 0;
}