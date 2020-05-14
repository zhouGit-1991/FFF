#include "FileIO.h"
#include <fstream>
#include <ctime>
#include <io.h>
#include <sstream>  
 FileIO * FileIO::m_pFileIO = NULL;

 bool  fileExists (const std::string& name) 
 {
	 ifstream f(name.c_str());
	 f.close();
	 return f.good();
 }


void  createDir(const std::string &directoryPath)
{
	int dirPathLen = directoryPath.length();
	
    char tmpDirPath[256] = { 0 };
	for (int i = 0; i < dirPathLen; ++i)
	{
		tmpDirPath[i] = directoryPath[i];
		if (tmpDirPath[i] == '\\' || tmpDirPath[i] == '/')
		{
			if (access(tmpDirPath, 0) != 0)
			{
				int ret = mkdir(tmpDirPath);
				if (ret != 0)
				{
					return ;
				}
			}
		}
	}

	if (!fileExists(directoryPath))
	{
		ofstream f(directoryPath);
		if(f)
		{
			f.close();
		}
        else
        {
            cout<<"fiel creat Failed";
        }
	}
	
}

FileIO::FileIO(void)
{
	char buf1[256];
	_getcwd(buf1, sizeof(buf1));


	string fileName(buf1);
	fileName+="/log/";


	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);

	char strYeay[10];
	char strMon[10];
	char strDay[10];
	char strHour[10];
	char strMin[10];
	char strSec[10];

	itoa(p->tm_year+1900,strYeay,10);
	itoa(p->tm_mon,strMon,10);
	itoa(p->tm_mday,strDay,10);
	itoa(p->tm_hour,strHour,10);
	itoa(p->tm_min,strMin,10);
	itoa(p->tm_sec,strSec,10);

	m_strLogFileName=fileName+strYeay+"/"+strMon+"/"+strDay+"/"+strHour+"-"+strMin+"-"+strSec+".txt";
	
}


FileIO::~FileIO(void)
{
}

FileIO* FileIO::instance()
{
	if(!m_pFileIO)
	{
		m_pFileIO = new FileIO();
	}
	return m_pFileIO;
}

void FileIO::readFile(READMODE readmode,const char* fileName,char** readData,int begin ,int _length)
{
	if(fileExists(fileName))
	{
		fstream in;

		if(readmode == READMODE::MODE_TEXT)
		{
			in.open(fileName);
			if(in.is_open())
			{
				in.seekg(begin);
				*readData = new char[_length+1];
				in.get(*readData,_length+1);
				in.close();
			}
			else
			{
				std::cout<<"file Open failed";
			}
		}
		else
		{
			in.open(fileName, ios::in|ios::binary);
			if(in.is_open())
			{
				in.seekg(begin*8);
				*readData = new char[_length+1];
				if(!readData)
				{

					*readData = new char[5];
					*readData = "NULL";
					return;
				}
				//in.get(*readData,_length+1);
				char *tmp =  new char[9];
				string tmpstr;
				for( int cur = 0; cur < _length;++cur)
				{
					in.get(tmp,9);
					int i = atoi(tmp);
					char c = i;
					tmpstr+=c;
				}
				in.clear();
			
				in.seekg(begin*8,ios::beg);
				in.read(*readData,_length+1);
		
				//memcpy(*readData,tmpstr.c_str(),_length+1);
				in.close();

			}
			else
			{
				std::cout<<"file Open failed";
			}
		}
		
	}
	else
	{
        *readData = new char[17];
        memcpy(*readData,"file Open failed",17);

	}

}


bool FileIO::writeFile( const char* fileName,const char* data,bool isCreat ,WRITEMODE mode)
{
	if(!data) return false;
	if(isCreat)
	{
		createDir(fileName);
	}
	if(fileExists(fileName))
	{
		fstream out;
		
        out.open(fileName,ios::out|ios::binary);
		if(out.is_open())
		{
			if(mode == MODE_WRITE)
			{
                out<<data;
                //out.write(data,sizeof(data));
				out.flush();
				out.close();
			}
			else
			{
				out.seekg (0, ios::end);
				string strTime;
				getCurentTime(strTime);
				out<<strTime<<data<<endl;
				out.flush();
			}
		}
		else
		{
			return false;
		}
		return true;
	}
	return false;

}

void FileIO::writeLog( const char* msg )
{
	writeFile(m_strLogFileName.c_str(),msg,true,MODE_APPEND);
	
}

void FileIO::getCurentTime( string & strTime )
{
	time_t nowtime;
	struct tm* p;
	time(&nowtime);
	p = localtime(&nowtime);


	char strHour[10];
	char strMin[10];
	char strSec[10];

	
	itoa(p->tm_hour,strHour,10);
	itoa(p->tm_min,strMin,10);
	itoa(p->tm_sec,strSec,10);

	strTime = strTime+ strHour + "::" + strMin + "::" + strSec + " ";

}



