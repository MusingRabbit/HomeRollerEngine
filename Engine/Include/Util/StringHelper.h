#pragma once
#include <string>
#include <vector>

using namespace std;

namespace Engine {

	class StringHelper {
	public :
		inline static void SplitString(const string& value, char delim, vector<string>& result) {
			result.clear();

			const char* cstr = value.c_str();
			unsigned int strLength = value.length();
			unsigned int start = 0;
			unsigned int end = 0;

			while (end <= strLength)
			{
				while (end <= strLength)
				{
					if (cstr[end] == delim)
						break;

					end++;
				}
				result.push_back(value.substr(start, end - start));
				start = end + 1;
				end = start;
			}

		}

	};

}