#include<iostream>
#include"String.h"
#include"TokenMachine.h"
using namespace std;
unsigned int TokenMachine::_tokenNumber = 0;
const unsigned int TokenMachine::_MAX_LIVE_TOKENS = TokenMachine::setMaxLiveTokens();
const double TokenMachine::_AVERAGE_PROCESSING_TIME_IN_MINUTES = TokenMachine::setAverageProcessingTime();
unsigned int TokenMachine::_activeTokens = 0;
int TokenMachine::setMaxLiveTokens(int num )
{
	return num;
}
double TokenMachine::setAverageProcessingTime(double tm )
{
	return tm;
}
String TokenMachine::getNextToken()
{
	if(_activeTokens < _MAX_LIVE_TOKENS)
	{
		_tokenNumber++;
		String str{ "Token Id: " };
		String token;
		token.setNumber(_tokenNumber);
		str.concatEqual(token);
		String activeMemberMessage{ "\nPerson before you in Line are:  \nExpected Waiting Time:  minutes" };
		activeMemberMessage.at(32) = (char)(getActiveTokensCount() + 48);
		token.setNumber(_AVERAGE_PROCESSING_TIME_IN_MINUTES*_activeTokens);
		activeMemberMessage.insert(57, token);
		str.concatEqual(activeMemberMessage);
		_activeTokens++;
		return str;
	}
	else
	{
		String temp;
		temp.setNumber(_MAX_LIVE_TOKENS);
		String str{ "We are sorry. There can't be more than  tokens in system for service. Please wait for some clients to get serviced" };
		str.insert(39,temp);
		return str;
	}
}
unsigned int TokenMachine :: getActiveTokensCount()
{
	return _activeTokens;
}
void TokenMachine::personIsServiced()
{
	if (_activeTokens > 0)
	{
		_activeTokens--;
	}
}
unsigned int TokenMachine::getCountOfPersonsServiced()
{
	return _tokenNumber-_activeTokens;
}
void TokenMachine::resetMachine()
{
	_tokenNumber = 0;
	_activeTokens = 0;
}