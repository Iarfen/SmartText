#include "letter.hpp"
#include "line.hpp"
#include "text.hpp"

#include "boost/algorithm/string.hpp"

#include <iostream>

using namespace std;

namespace smtext
{
	line::line() : words(),start_punctuation(),final_punctuation(),raw_content(),text_container()
	{
	}

	line::line(string new_line,const text* new_text) : words(),start_punctuation('\0'),final_punctuation('\0'),raw_content(new_line),text_container(new_text)
	{
		string final_words;
		if (new_line[0] == ' ')
		{
			new_line = new_line.substr(1,new_line.size() - 1);
			raw_content = new_line;
		}
		if (is_starting_punctuation(new_line[0],text_container->get_current_language()))
		{
			if (is_ending_punctuation(new_line[new_line.size() - 1],text_container->get_current_language()))
			{
				final_words = new_line.substr(1,new_line.size() - 2);
				start_punctuation = new_line[0];
				final_punctuation = new_line[new_line.size() - 1];
			}
			else
			{
				final_words = new_line.substr(1,new_line.size() - 1);
				start_punctuation = new_line[0];
			}
		}
		else
		{
			if (is_ending_punctuation(new_line[new_line.size() - 1],text_container->get_current_language()))
			{
				final_words = new_line.substr(0,new_line.size() - 1);
				final_punctuation = new_line[new_line.size() - 1];
			}
			else
			{
				final_words = new_line;
			}
		}
		vector<string> new_words;
		boost::split(new_words,final_words,boost::is_any_of(" ,"));
		for (const string& new_word : new_words)
		{
			word final_word (new_word);
			words.push_back(final_word);
		}
	}

	string line::display() const
	{
		string raw_content2 (raw_content.length(),L' ');
		copy(raw_content.begin(),raw_content.end(),raw_content2.begin());
		return raw_content2;
	}

	bool line::has_partial_date() const
	{
		language current_language = text_container->get_current_language();
		for (const word& line_word : words)
		{
			if (line_word.is_month(current_language) or line_word.is_day(current_language))
			{
				return true;
			}
		}
	}

	bool line::has_date() const
	{
		language current_language = text_container->get_current_language();
		for (const word& line_word : words)
		{
			if (line_word.is_month(current_language) or line_word.is_day(current_language))
			{
				return true;
			}
		}
	}

	bool line::has_word(string x) const
	{
		for (const word& text_word : words)
		{
			if (text_word == x)
			{
				return true;
			}
		}
		return false;
	}

	bool line::has_any_word(vector<string> x) const
	{
		for (const string& test_word : x)
		{
			if (has_word(test_word))
			{
				return true;
			}
		}
		return false;
	}

	bool line::has_words(vector<string> x) const
	{
		for (const string& test_word : x)
		{
			if (!has_word(test_word))
			{
				return false;
			}
		}
		return true;
	}
}

bool operator ==(const smtext::line& x,const smtext::line& y)
{
	return (x.display() == y.display());
}

ostream& operator <<(ostream& os, const smtext::line& x)
{
	return os << x.display();
}
