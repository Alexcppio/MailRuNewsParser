# MailRuNewsParser
Get article by adress

Main function is in file easyParser.cpp.

String variable sourceText gets content from URL, using getUrl function in curlTransfer.cpp file. The getUrl get adress from path.txt, where it is necessary to write, before using the program.

Then, in analyzer.cpp it gives titleText, articleText and dateText, accordingly by their names, parts of article. The articleText is also cleans from links and no brackets markup.

Then all finished parts of titleText, articleText and dateText writing into test.txt file on top of previous content. Another use of exe file cleans previous result and add new one.

Program is written to work on news section of mail.ru site. Therefore adapting it for another resource requires studying markup and putting changes into variables, which names starts from header, article, href and date. Then it works just fine.
