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
	
	/*��ȡ�ļ� 
	readmode ��ȡ�ļ���ģʽ���ж����ƶ�ȡ���ı���ȡ����ģʽ 
	fileName�ļ���  
	readData���ص��ַ��� 
	begin��ȡ����ʼ�㣬
	length ��ȡ�ĳ��ȡ�
	*/
	void readFile(READMODE readmode, const char* fileName,char** readData,int _begin, int _length);
	

	/*д�ļ�
	fileNameд�ļ����ļ����ƣ�
	dataд�ļ������ݣ�
	isCreat�Ƿ񴴽�����ļ���
	modeд�ļ���ģʽ׷�ӻ�����д
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



