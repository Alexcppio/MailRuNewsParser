#define CURL_STATICLIB
#include <iostream>
#include <string>
#include "curl/curl.h"
using std::string;
using std::cout;
using std::endl;


static char errorBuffer[CURL_ERROR_SIZE];
static int writer(char* data, size_t size, size_t nmemb, string* sourceText)
{
	int result = 0;
	if (sourceText != NULL)
	{
		sourceText->append(data, size * nmemb);
		result = size * nmemb;
	}
	return result;
}

void getURL(string &sourceText) {
	CURL* curl;
	CURLcode result;
	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
		curl_easy_setopt(curl, CURLOPT_URL, "https://news.mail.ru/society/41450130/?frommail=1");
		curl_easy_setopt(curl, CURLOPT_HEADER, 1);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &sourceText);
		result = curl_easy_perform(curl);
		if (result == CURLE_OK) {
		}
		else {
			cout << "Îøèáêà! " << errorBuffer << endl;
		}
	}
	curl_easy_cleanup(curl);
}


