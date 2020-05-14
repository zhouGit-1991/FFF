#pragma once
#include <string>
#include <iostream>
#include <direct.h>

using namespace std;


enum WRITEMODE
{
	MODE_WRITE,
	MODE_APPEND
};

enum READMODE
{
	MODE_TEXT,
	MODE_STREAM
};


class FileIO
{
public:
	static FileIO* instance();
	
	/*读取文件 
	readmode 读取文件的模式，有二进制读取和文本读取两种模式 
	fileName文件名  
	readData返回的字符串 
	begin读取的起始点，
	length 读取的长度。
	*/
	void readFile(READMODE readmode, const char* fileName,char** readData,int _begin, int _length);
	

	/*写文件
	fileName写文件的文件名称，
	data写文件的数据，
	isCreat是否创建这个文件，
	mode写文件的模式追加还是重写
	*/
	bool writeFile(const char* fileName,const char* data,bool isCreat = false,WRITEMODE mode= MODE_WRITE);
	
	
	void writeLog(const char *msg); 

	~FileIO(void);
private:
	FileIO(void);
	void getCurentTime(string & strTime);

	string m_strLogFileName;

	static FileIO * m_pFileIO;
};



