#pragma once
#include<iostream>


/// <summary>
/// �Զ����쳣��
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
