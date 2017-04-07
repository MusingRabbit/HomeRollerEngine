#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <Globals.h>


using namespace std;

class File
{
public:
	inline static string LoadFile(const std::string& filepath)
	{
		string sResult;
		string sCurrLine;
		
		ifstream file;
	   
		file.open(filepath);

		uint begin = (uint)file.tellg();
		file.seekg(0, std::ios::end);
		uint end = (uint)file.tellg();
		uint size = end - begin;
		file.seekg(0);

		sResult.reserve(size);

		if (file.is_open())
		{
			while (file.good())
			{
				getline(file, sCurrLine);
				sResult.append(sCurrLine + "\n");
			}
		}
		else
		{
			std::cerr << "File load exception! Unable to open file at " << filepath << std::endl;
			throw "File load exception! Unable to open file at " + filepath;
		}


		return sResult;
	}

	inline static void ReadLines(const std::string& filePath, std::vector<std::string>& out) {
		out.clear();
		ifstream file;
		string sCurrLine;
		file.open(filePath);

		uint begin = (uint)file.tellg();
		file.seekg(0, std::ios::end);
		uint end = (uint)file.tellg();
		uint size = end - begin;
		file.seekg(0);

		if (file.is_open())
		{
			while (file.good())
			{
				getline(file, sCurrLine);
				out.push_back(sCurrLine);
			}
		}
		else 
		{
			std::cerr << "File load exception! Unable to open file at " << filePath << std::endl;
			throw "File load exception! Unable to open file at " + filePath;
		}
	}

	inline static bool GetBuffer(string filePath, vector<unsigned char>& buffer) {
		ifstream file(filePath, ios::binary);
		
		if (file.fail()) {
			perror(filePath.c_str());
			return false;
		}

		//Move file pointer to the end of file
		file.seekg(0, ios::end);
		//Get file size by calling tellg. tellg will return the index position of the file header. (bytes moved)
		uint fileSize = (uint)file.tellg();
		//Reset file pointer back to the begining of the file
		file.seekg(0, ios::beg);
		//If the file contains any header information, remove it (unlikely to be an issue)
		fileSize -= (uint)file.tellg();
		//Resize buffer to file size
		buffer.resize(fileSize);
		//Fill the buffer
		file.read((char*)&buffer[0], fileSize);
		//Close the file
		file.close();

		return true;
	}
};

