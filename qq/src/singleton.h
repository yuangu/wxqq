#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#ifndef NULL
#define NULL 0
#endif

template<class T>
class CSingleton
{
public:
 
	static T& getInstance()
	{
		if(NULL == _Instance)
		{
			_Instance = new T;
		}
		return *_Instance;
	}

	static void releaseInstance()
	{
		if(_Instance != NULL)
		{
			delete _Instance;
			_Instance = NULL;
		}
	}

protected:
	CSingleton()
	{
	}
	~CSingleton()
	{
		_Instance = NULL;
	}
	static T* _Instance;
};
template<class T>
T* CSingleton<T>::_Instance = NULL;

#endif