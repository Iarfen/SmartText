#include "paragraph.hpp"
#include "text.hpp"

#include "boost/algorithm/string.hpp"

using namespace std;

namespace smarttext
{
	paragraph::paragraph(string paragraph_content,const text* new_text) : lines(),raw_content(paragraph_content),text_container(new_text)
	{
		vector<string> new_lines;
		boost::split(new_lines,paragraph_content,boost::is_any_of(".:?!"));
		for (const string& new_line : new_lines)
		{
			if (new_line != "")
			{
				line final_paragraph (new_line,text_container);
				lines.push_back(final_paragraph);
			}
		}
	}

	wstring paragraph::display() const
	{
		wstring raw_content2 (raw_content.length(),L' ');
		copy(raw_content.begin(),raw_content.end(),raw_content2.begin());
		return raw_content2;
	}

	vector<word> paragraph::get_words() const
	{
		vector<word> out_words;
		for (const line& text_line : lines)
		{
			for (const word& text_word : text_line.get_words())
			{
				out_words.push_back(text_word);
			}
		}
		return out_words;
	}
}

wostream& operator <<(wostream& os, const smarttext::paragraph& x)
{
	return os << x.display();
}
