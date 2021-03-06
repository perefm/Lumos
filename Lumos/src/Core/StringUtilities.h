#pragma once

#ifdef LUMOS_PLATFORM_ANDROID
template<typename T>
std::string to_string(const T& n)
{
	std::ostringstream stm;
	stm << n;
	return stm.str();
}
#endif

namespace Lumos
{
	 namespace StringUtilities
	{
		template<typename T>
		static std::string ToString(const T& input)
		{
#ifdef LUMOS_PLATFORM_ANDROID
			return to_string(input);
#else
			return std::to_string(input);
#endif
		}

		std::string GetFilePathExtension(const std::string& FileName);
        std::string RemoveFilePathExtension(const std::string& FileName);
		std::string GetFileName(const std::string& FilePath);
		std::string RemoveName(const std::string& FilePath);
        std::string GetFileLocation(const std::string& FilePath);

        std::vector<std::string> LUMOS_EXPORT SplitString(const std::string& string, const std::string& delimiters);
        std::vector<std::string> LUMOS_EXPORT SplitString(const std::string& string, const char delimiter);
        std::vector<std::string> LUMOS_EXPORT Tokenize(const std::string& string);
        std::vector<std::string> GetLines(const std::string& string);

        const char* FindToken(const char* str, const std::string& token);
        const char* FindToken(const std::string& string, const std::string& token);
        i32 FindStringPosition(const std::string& string, const std::string& search, u32 offset = 0);
        std::string StringRange(const std::string& string, u32 start, u32 length);
        std::string RemoveStringRange(const std::string& string, u32 start, u32 length);

        std::string GetBlock(const char* str, const char** outPosition = nullptr);
        std::string GetBlock(const std::string& string, u32 offset = 0);

        std::string GetStatement(const char* str, const char** outPosition = nullptr);

        bool StringContains(const std::string& string, const std::string& chars);
        bool StartsWith(const std::string& string, const std::string& start);
        i32 NextInt(const std::string& string);

        bool StringEquals(const std::string& string1, const std::string& string2);
        std::string StringReplace(std::string str, char ch1, char ch2);
        std::string StringReplace(std::string str, char ch);

        std::string& BackSlashesToSlashes(std::string& string);
        std::string& SlashesToBackSlashes(std::string& string);
		std::string& RemoveSpaces(std::string& string);
		std::string Demangle(const std::string& string);
	}
}
