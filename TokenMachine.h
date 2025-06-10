#include"String.h"
#ifndef TOKEN_MACHINE_H
#define TOKEN_MACHINE_H
class TokenMachine
{
	static unsigned int _tokenNumber;
	static const unsigned int _MAX_LIVE_TOKENS;
	static const double _AVERAGE_PROCESSING_TIME_IN_MINUTES;
	static unsigned int _activeTokens;
	static int setMaxLiveTokens(int num = 5);
	static double setAverageProcessingTime(double tm = 3);
public:
	static String getNextToken();
    static unsigned int getActiveTokensCount();
	static void personIsServiced();
	static unsigned int getCountOfPersonsServiced();
	static void resetMachine();
};
#endif
