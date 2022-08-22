#pragma once
#include<iostream>


/// <summary>
/// 自定义异常类
/// </summary>
class illegalParameterValue{
private:
	std::string message;
public:
	illegalParameterValue() :
		message("Illegal arameter value") {}
	illegalParameterValue(std::string theMessage) {
		message = theMessage;
	}
	void outputMessage() {
		std::cout << message << "\n";
	}

};
