#pragma once

#include <vector>


class CAutoAlloc
{
public:
	CAutoAlloc() { }

	~CAutoAlloc() { auto_clear(); }

	void* auto_alloc(size_t cb)
	{
		char*	ptr = new char[cb];

		if(ptr)
		{
			memset(ptr, 0, cb);

			m_ptrs.push_back(ptr);
		}

		return (void*)ptr;
	}

	void auto_clear()
	{
		for(std::vector<char*>::iterator it = m_ptrs.begin(); it != m_ptrs.end(); ++ it)
			delete [] (*it);

		m_ptrs.clear();
	}

protected:
	std::vector<char*>	m_ptrs;

};

