#define CURL_STATICLIB
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
#include "curl/curl.h"
#include "curlTransfer.h"
#include "analyzer.h"


int main() {
	setlocale(LC_ALL, "Russian");
	string sourceText;
	string titleText;
	string articleText;
	string dateText;
	getURL(sourceText);
	std::ofstream fin("test.txt");
	getTitle(sourceText, titleText);
	fin << titleText << endl;
	getDate(sourceText, dateText);
	fin << dateText << endl;
	getArticle(sourceText, articleText);
	fin << articleText << endl;
	fin.close();

	return 0;
}