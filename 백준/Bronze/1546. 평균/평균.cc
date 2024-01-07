#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	vector<double> scores;

	int count;

	cin >> count;

	string str_scores;
	
	cin.ignore();
	getline(cin, str_scores);

	istringstream ss(str_scores);

	string word;
	
	double max_score = 0;
	double now_score = 0;
	
	// 전달 받은 문자열을 공백 기준으로 분리
	while (getline(ss, word, ' ')) {
		// 분리한 string을 int로 변환
		now_score = atof(word.c_str());
		scores.push_back(now_score);

		if(now_score > max_score)
			max_score = now_score;
	}

	double total_scores = 0;
	double reverse_max = 1 / max_score;

	for (int i = 0; i < count; i++)
	{
		now_score = scores[i] / max_score * 100;
		total_scores += now_score;
	}

	cout << total_scores / count;
}