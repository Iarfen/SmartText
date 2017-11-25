#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED

#include "language.hpp"
#include "word.hpp"

#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace smtext
{
	/// \class line
	/// \brief The line class represents a line of text. It distinguish punctuation and words
	class line
	{
		public:
			/// \brief Default constructor. Constructs an empty line
			line();

			/// \brief Creates a new line with the given string and the selected language
            /// \param new_line characters of the line
            /// \param new_text pointer to the text this line belongs to
			explicit line(string,const text*);

			/// \brief Returns a vector<word> of the words that compose the line
			inline const vector<word>& get_words() const
			{
				return words;
			}

			/// \brief Returns a string containing the line
			string display() const;

			/// \brief Returns the starting character punctuation, if any
			inline char get_start_punctuation() const
			{
				return start_punctuation;
			}

			/// \brief Returns the final character punctuation, if any
			inline char get_final_punctuation() const
			{
				return final_punctuation;
			}

			/// \brief Returns true if the line has a date inside
			bool has_partial_date() const;

			/// \brief Returns true if the line has a date inside
			bool has_date() const;

			/// \brief Returns true if the line has the word asked
			/// \param x string to compare the words to
			bool has_word(string) const;

			/// \brief Returns true if the line has any of the words asked
			/// \param x vector of strings of the words to test
			bool has_any_word(vector<string>) const;

			/// \brief Returns true if the line has all the words given
			/// \param x vector of strings of the words to test
			bool has_words(vector<string>) const;

			/// \brief Returns the number of words the line has
			inline int number_of_words() const
			{
				return words.size();
			}

		private:
			vector<word> words; ///< words of the line
			char start_punctuation; ///< starting punctuation of the line
			char final_punctuation; ///< final punctuation of the line
			string raw_content; ///< original content of the line
			const text* text_container; ///< parent text class of the line class
	};
}

/// \brief Returns true if the line is identical to the compared line
bool operator ==(const smtext::line&,const smtext::line&);

/// \brief Outputs the line to a ostream buffer
ostream& operator <<(ostream&, const smtext::line&);

#endif // LINE_HPP_INCLUDED
