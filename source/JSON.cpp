/*
	Filename: JSON.cpp
	Author: Jesse Stojan
	Copyright (c) 2020 - All Rights Reserved
*/
#include <JSON.hpp>

// JSON - ANSI
#define JSON_DBLQUOTE					'"'
#define JSON_QUOTE						'\''
#define JSON_STARTARRAY					'['
#define JSON_ENDARRAY					']'
#define JSON_STARTOBJECT				'{'
#define JSON_ENDOBJECT					'}'
#define JSON_COMMA						','
#define JSON_COLON						':'
#define JSON_TRUE						"true"
#define JSON_FALSE						"false"
#define JSON_NULL						"null"

#define JSON_ESCAPE						'\\'
#define JSON_ESCAPE_STRING				'"'
#define JSON_ESCAPE_REVERSE_SOLIDUS		'\\'
#define JSON_ESCAPE_SOLIDUS				'/'
#define JSON_ESCAPE_BACKSPACE			'b'
#define JSON_ESCAPE_FORM_FEED			'f'
#define JSON_ESCAPE_LINE_FEED			'n'
#define JSON_ESCAPE_CARRIAGE_RETURN		'r'
#define JSON_ESCAPE_HORIZONTAL_TAB		't'

// JSON - Unicode
#define JSON_DBLQUOTE_W					L'"'
#define JSON_QUOTE_W					L'\''
#define JSON_STARTARRAY_W				L'['
#define JSON_ENDARRAY_W					L']'
#define JSON_STARTOBJECT_W				L'{'
#define JSON_ENDOBJECT_W				L'}'
#define JSON_COMMA_W					L','
#define JSON_COLON_W					L':'
#define JSON_TRUE_W						L"true"
#define JSON_FALSE_W					L"false"
#define JSON_NULL_W						L"null"

#define JSON_ESCAPE_W					L'\\'
#define JSON_ESCAPE_STRING_W			L'"'
#define JSON_ESCAPE_REVERSE_SOLIDUS_W	L'\\'
#define JSON_ESCAPE_SOLIDUS_W			L'/'
#define JSON_ESCAPE_BACKSPACE_W			L'b'
#define JSON_ESCAPE_FORM_FEED_W			L'f'
#define JSON_ESCAPE_LINE_FEED_W			L'n'
#define JSON_ESCAPE_CARRIAGE_RETURN_W	L'r'
#define JSON_ESCAPE_HORIZONTAL_TAB_W	L't'

//----------------------------------------------------------------

JSON::JSON() {

}

//----------------------------------------------------------------

JSON::~JSON() {
}

//----------------------------------------------------------------

size_t JSON::stringify(const uint32_t& flags) {
	//TODO:

	return size_t();
}

//----------------------------------------------------------------

size_t JSON::stringify(char** ppDest, const uint32_t& flags) {
	//TODO:

	return size_t();
}

//----------------------------------------------------------------

size_t JSON::stringify(wchar_t** ppDest, const uint32_t& flags) {
	//TODO:

	return size_t();
}

//----------------------------------------------------------------

/*
	Object
	Array
	String
	Number
	boolean (true/false)
	"null"
*/

size_t JSON::parse(const char* str) {
	size_t slen = strnlen(str, ~(size_t()));
	//const char tokens[] = {'"', '\'', '[', ']', '{', '}', ',', ':'};

	//TODO:

	return size_t();
}

//----------------------------------------------------------------

/*
	Object
	Array
	String
	Number
	boolean (true/false)
	"null"
*/

size_t JSON::parse(const wchar_t* str) {
	size_t maxlen = wcsnlen(str, ~(size_t()));

	for (size_t i = 0; i < maxlen; ++i) {
		// Skip Line Endings
		if (str[i] == L'\r' || str[i] == L'\n') continue;
		// Skip white spacing
		if (str[i] == L'\t' || str[i] == L' ') continue;
		// Skip anything that isn't valid JSON
		if (str[i] != L'{' && str[i] != L'[') continue;

		/*
			{
				"name":"value"	//comment
			}
		*/
		wchar_t* name = nullptr;
		void* value = nullptr;
		size_t nlen = 0;
		size_t vsz = 0;

		// Check if Object
		if (str[i] == JSON_STARTOBJECT_W) {
			// Check for double quote "name"
			if (str[i] == JSON_DBLQUOTE_W) {
				// Extract "name"
				for (size_t j = (i + 1); j < maxlen; ++j) {
					if (str[j] == JSON_ESCAPE_W) continue;
					if (str[j] == JSON_DBLQUOTE_W) {
						nlen = (j - i);
						name = new wchar_t[(nlen + 1)];
						wmemset(name, L'\0', nlen + 1);
						wcsncpy(name, &str[i], nlen);
						i = (j + 1);
						break;
					}
				}
				// Check for `value`

				//TODO:

			}
			// Check for single quote 'name'
			else if (str[i] == JSON_QUOTE_W) {
				// Extract 'name'
				for (size_t j = (i + 1); j < maxlen; ++j) {
					if (str[j] == JSON_ESCAPE_W) continue;
					if (str[j] == JSON_QUOTE_W) {
						nlen = (j - i);
						name = new wchar_t[(nlen + 1)];
						wmemset(name, L'\0', nlen + 1);
						wcsncpy(name, &str[i], nlen);
						i = (j + 1);
						break;
					}
				}
				// Check for `value`

				//TODO:

			}
		}
		// JSON Array
		else if (str[i] == JSON_STARTARRAY_W) {

			//TODO:

		}
	}

	//TODO:
   
	return size_t();
}

//----------------------------------------------------------------
