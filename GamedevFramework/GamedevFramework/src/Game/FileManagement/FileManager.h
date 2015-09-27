/***************************************************************************************
*	Title: FileManager.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef FILE_MANAGER_H_
#define FILE_MANAGER_H_

#include <iostream>
#include <fstream>


using namespace std;


class FileManager {
    private:
		ofstream inputData_;

    public:
        FileManager();
        virtual ~FileManager();

		bool openInputData();

		bool closeInputData();
};

#endif // FILE_MANAGER_H_
