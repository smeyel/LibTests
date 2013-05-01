#include <iostream>
#include "Logger.h"
#include "FileLogger.h"
#include "StdOutLogger.h"
#include "SimpleIniConfigReader.h"

using namespace LogConfigTime;

void main()
{
	// ============= Direct test of logger

	Logger *logger = new StdoutLogger();
	logger->SetLogLevel(Logger::LOGLEVEL_INFO);

	logger->Log(Logger::LOGLEVEL_INFO,"DirectTest","DirectTest message on info level.\n",1);
	logger->SetLogLevel(Logger::LOGLEVEL_VERBOSE);
	logger->Log(Logger::LOGLEVEL_INFO,"DirectTest","Not appearing DirectTest message on info level.\n",1);

	Logger::getInstance()->Log(Logger::LOGLEVEL_VERBOSE,"SingletonTest","Appearing singleton test...\n");


	int i=12;

	FileLogger loggerF("d:\\e3.txt");

	Logger::getInstance()->Log(Logger::LOGLEVEL_ERROR,"TAG","Szam:%d %d %s %d\n",1,2,"Hello",3);

	loggerF.close();


	// ============ Direct test of ConfigReader

	SimpleIniConfigReader *SIreader = new SimpleIniConfigReader("test.ini");
	ConfigReader *reader = SIreader;

	bool boolean1 = reader->getBoolValue("main","boolean1");
	bool boolean2 = reader->getBoolValue("main","boolean2");
	bool boolean3 = reader->getBoolValue("main","boolean3");
	const char *str = reader->getStringValue("main","string");
	int integer1 = ConfigReader::getInstance()->getIntValue("main","integer");

	std::cout << "Bools: " << boolean1 << ", " << boolean2 << ", " << boolean3 << std::endl;
	std::cout << "Integer: " << integer1 << std::endl;
	std::cout << "String: " << str << std::endl;

}
