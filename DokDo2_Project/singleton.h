#pragma once
template <class T>

class singleton
{
private:
	static T * p;

public:
	singleton() {};
	virtual ~singleton() {};

	static T * GetInstance()
	{
		if (p == nullptr)
			p = new T;

		return p;
	}

	static void ReleaseInstance()
	{
		if (p)
			delete p;
	}

};

template<class T>

T * singleton<T> ::p = nullptr;
