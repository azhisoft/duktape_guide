#pragma once

#include <windows.h>

#include "autoalloc.h"


class CStrEncoding : public CAutoAlloc
{
public:
	CStrEncoding(CAutoAlloc* allocator = NULL) { m_allocator = allocator ? allocator : this; }

	~CStrEncoding() { }

	virtual LPCSTR UniToAnsi(LPCWSTR pszUni)
	{
		LPCSTR	retVal = "";
		long	size = WideCharToMultiByte(CP_ACP, 0, pszUni, -1, NULL, 0, 0, 0);
		LPSTR	buf = (LPSTR)m_allocator->auto_alloc(size);

		if(buf)
		{
			WideCharToMultiByte(CP_ACP, 0, pszUni, -1, buf, size, 0, 0);

			retVal = (LPCSTR)buf;
		}

		return retVal;
	}

	virtual LPCSTR UniToUtf8(LPCWSTR pszUni)
	{
		LPCSTR	retVal = "";
		long	size = WideCharToMultiByte(CP_UTF8, 0, pszUni, -1, NULL, 0, 0, 0);
		LPSTR	buf = (LPSTR)m_allocator->auto_alloc(size);

		if(buf)
		{
			WideCharToMultiByte(CP_UTF8, 0, pszUni, -1, buf, size, 0, 0);

			retVal = (LPCSTR)buf;
		}

		return retVal;
	}

	virtual LPCWSTR AnsiToUni(LPCSTR pszAnsi)
	{
		LPCWSTR	retVal = L"";
		long	size = MultiByteToWideChar(CP_ACP, 0, pszAnsi, -1, NULL, 0);
		LPWSTR	buf = (LPWSTR)m_allocator->auto_alloc(size * sizeof(WCHAR));

		if(buf)
		{
			MultiByteToWideChar(CP_ACP, 0, pszAnsi, -1, buf, size);

			retVal = (LPCWSTR)buf;
		}

		return retVal;
	}

	virtual LPCSTR AnsiToUtf8(LPCSTR pszAnsi)
	{
		return UniToUtf8(AnsiToUni(pszAnsi));
	}

	virtual LPCWSTR Utf8ToUni(LPCSTR pszUtf8)
	{
		LPCWSTR	retVal = L"";
		long	size = MultiByteToWideChar(CP_UTF8, 0, pszUtf8, -1, NULL, 0);
		LPWSTR	buf = (LPWSTR)m_allocator->auto_alloc(size * sizeof(WCHAR));

		if(buf)
		{
			MultiByteToWideChar(CP_UTF8, 0, pszUtf8, -1, buf, size);

			retVal = (LPCWSTR)buf;
		}

		return retVal;
	}

	virtual LPCSTR Utf8ToAnsi(LPCSTR pszUtf8)
	{
		return UniToAnsi(Utf8ToUni(pszUtf8));
	}

protected:
	CAutoAlloc*	m_allocator;

};

