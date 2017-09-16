#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED

#include "language.hpp"
#include "word.hpp"

#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace smarttext
{
	/// \class line
	/// \brief The line class represents a line of text. It distinguish punctuation and words
	class line
	{
		public:
			/// \brief Creates a new line with the given string and the selected language
            /// \param new_line characters of the line
            /// \param new_text pointer to the text this line belongs to
			explicit line(string,const text*);

			/// Returns a vector<word> of the words that compose the line
			inline const vector<word>& get_words() const
			{
				return words;
			}

			/// Returns a wstring containing the line
			wstring display() const;

			/// Returns the starting character punctuation, if any
			inline char get_start_punctuation() const
			{
				return start_punctuation;
			}

			/// Returns the final character punctuation, if any
			inline char get_final_punctuation() const
			{
				return final_punctuation;
			}

			/// Returns true if the line has a date inside
			bool has_partial_date() const;

			/// Returns true if the line has a date inside
			bool has_date() const;

		private:
			vector<word> words;
			char start_punctuation;
			char final_punctuation;
			string raw_content;
			const text* text_container;
	};
}

/// Outputs the line to a wostream buffer
wostream& operator <<(wostream&, const smarttext::line&);

#endif // LINE_HPP_INCLUDED
