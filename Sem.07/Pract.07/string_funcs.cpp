#include <iostream>

size_t myStrLen(const char* str) {
	if (!str)
		return 0;

	size_t len = 0;
	while (str[len])
	{
		len++;
	}

	return len;
}

void myStrCpy(char* dest, const char* src) {
	if (!dest || !src)
		return;

	size_t i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
}

void myStrCat(char* dest, const char* src) {
	if (!dest || !src)
		return;

	size_t write = myStrLen(dest);
	size_t read = 0;

	while (src[read])
	{
		dest[write++] = src[read++];
	}

	dest[write] = '\0';
}

int myStrCmp(const char* first, const char* second) {
	if (!first || !second)
	{
		// some value that's not on the ascii table
		return 128;
	}

	size_t i = 0;
	while (first[i] && (first[i] == second[i]))
	{
		i++;
	}

	return first[i] - second[i];
}

// not in place but more readable
void replace(const char* text, const char* where, const char* what, char* res) {
	if (!text || !where || !what || !res)
		return;

	size_t textLen = myStrLen(text);
	size_t whereLen = myStrLen(where);
	size_t whatLen = myStrLen(what);
	size_t read = 0, write = 0;

	while (text[read])
	{
		bool found = true;

		if (read + whereLen > textLen)
		{
			found = false;
		}
		else
		{
			for (size_t i = 0; i < whereLen; i++)
			{
				if (text[read + i] != where[i])
				{
					found = false;
					break;
				}
			}
		}

		if (found)
		{
			for (size_t i = 0; i < whatLen; i++)
			{
				res[write++] = what[i];
			}
			read += whereLen;
		}
		else
		{
			res[write++] = text[read++];
		}
	}

	res[write] = '\0';
}

bool isPunctuation(char c) {
	// there's probably more chars
	return c == '.' || c == '?' || c == '!';
}

size_t getWordsCount(const char* str) {
	if (!str)
		return 0;

	size_t count = 0;
	bool inWord = false;
	size_t i = 0;

	while (str[i])
	{
		if (!inWord && !isPunctuation(str[i]) && str[i] != ' ')
		{
			count++;
			inWord = true;
		}
		else if (inWord && (isPunctuation(str[i]) || str[i] == ' '))
		{
			inWord = false;
		}

		i++;
	}

	return count;
}

const size_t MAX_WORDS_COUNT = 100;
const size_t MAX_WORD_LEN = 100;

// splits string my whitespaces and punctuation
void split(const char* str, char words[MAX_WORDS_COUNT][MAX_WORD_LEN], size_t& wordsCount) {
	if (!str)
		return;

	wordsCount = 0;
	bool inWord = false;
	size_t i = 0, start = 0;

	while (true)
	{
		if (!inWord && !isPunctuation(str[i]) && str[i] != ' ')
		{
			start = i;
			inWord = true;
		}
		// \0 handles last word case
		else if (inWord && (isPunctuation(str[i]) || str[i] == ' ' || str[i] == '\0'))
		{
			size_t len = i - start;

			for (size_t j = 0; j < len; j++)
			{
				words[wordsCount][j] = str[start + j];
			}

			words[wordsCount++][len] = '\0';
			inWord = false;
		}

		if (str[i] == '\0')
		{
			break;
		}

		i++;
	}
}

const size_t MAX_SIZE = 1024;

int main()
{
	const char* text = "I am the best of the  ?           best....";
	char words[MAX_WORDS_COUNT][MAX_WORD_LEN] = { {} };
	size_t wordsCount = 0;

	split(text, words, wordsCount);

	for (size_t i = 0; i < wordsCount; i++)
	{
		std::cout << words[i] << std::endl;
	}
}

