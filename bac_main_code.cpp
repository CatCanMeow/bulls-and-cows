#include <iostream>
#include <string>
#include <random>
#include <cctype>
// #include <set>
#include <algorithm>
#include <utility>
#include <chrono>
using namespace std;
using namespace std::chrono;
const string INDENT = "   << ";
const string HintF = "HintFlag", LenErr = "Length Error: You must give 4 character", 
			 ChErr = "Character Error: Every character must be number from 0 to 9", 
			 RepErr = "Repeat Error: The characters must be different to another", 
			 OK = string();
string answer;
string generateRandomStart()
{
	string result, range = "0123456789";
	mt19937 gnr(random_device{}());
	shuffle(range.begin(), range.end(), gnr);
	result = range.substr(0, 4);
	return result;
}
string checkGuessValid(string userGuess)
{
	if (userGuess == "h" || userGuess == "H")
		return /* "HintFlag" */ HintF;
	if (userGuess.size() != 4)
		return /* Length Error: You must give 4 character */ LenErr;
	for (int i = 0; i < userGuess.size(); i++)
		if (!isdigit(userGuess[i]))
			return /* "Character Error: Every character must be number from 0 to 9" */ ChErr;
	/*
	set<char> tmp;
	for (int i = 0; i < userGuess.size(); i++)
		tmp.insert(userGuess[i]);
	if (tmp.size() != userGuess.size())
		return "Repeat Error: The characters must be different to another";
	*/
	string :: iterator ip = unique(userGuess.begin(), userGuess.end());
	if (string(userGuess.begin(), ip).size() < userGuess.size())
		return /* "Repeat Error: The characters must be different to another" */ RepErr;
	return /* string() */ OK;
}
pair<int, int> getResult(string userGuess)
{
	int As = 0, Bs = 0;
	for (int i = 0; i < userGuess.size(); i++)
		if (userGuess[i] == answer[i])
			As++;
	for (int i = 0; i < userGuess.size(); i++)
	{
		int location = (int)answer.find(userGuess[i]);
		if (location > -1 && location != i)
			Bs++;
	}
	return pair<int, int>(As, Bs);
}
string getHint()
{
	unsigned randomSeed = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
	mt19937 randomNum(randomSeed);
	string result = "****";
	int position = randomNum() % 4;
	result[position] = answer[position];
	return result;
}
void doGuess()
{
	for (int i = 1; i <= 10; /* i++ */)
	{
		loop_begin: ;
		string userGuess, report;
		pair<int, int> result;
		cout << "[" << i << "]" << ">> ";
		cin >> userGuess;
		report = checkGuessValid(userGuess);
		if (report == "HintFlag")
		{
			cout << INDENT << getHint() << endl;
			// goto loop_begin;
			continue;
		}
		if (!report.empty())
		{
			cout << INDENT << report << endl;
			// goto loop_begin;
			continue;
		}
		result = getResult(userGuess);
		cout << INDENT << result.first << "A" << result.second << "B" << endl;
		if (result.first == 4 && result.second == 0)
		{
			cout << INDENT << "You guessed right" << endl;
			return;
		}
		i++;
	}
	cout << INDENT << "You lost! The correct answer is: " << answer << endl;
}
int main()
{
	answer = generateRandomStart();
	doGuess();
	return 0;
}
