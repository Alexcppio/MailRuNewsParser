#include <iostream>
#include <string.h>
using std::string;
#ifndef ANALYZER_H
#define ANALYZER_H


void getTitle(static string sourceText, string& titleText);
void getDate(static string sourceText, string& dateText);
void getArticle(static string sourceText, string& articleText);

#endif