#ifndef WORD_HPP_INCLUDED
#define WORD_HPP_INCLUDED

#include "language.hpp"

#include <iostream>
#include <map>
#include <string>

using namespace std;

namespace smtext
{
	extern map<string,string> common_chat_conversions;

	class text;

	/// \class word
	/// \brief The word class creates a word. It detects the category of the word, if it's well written, among more characteristics of it
	class word
	{
		public:
			/// \brief Default constructor. Constructs an empty word
			word();

			/// \brief Constructs a new word with the given characters
			/// \param new_chars characters that compose the new word
			explicit word(const string&);

			/// \brief Returns the chars that compose the word
			inline const string& get_chars() const
			{
				return chars;
			}

			/// \brief Returns true if the first word is ordered before the second word
			bool operator <(const smtext::word&) const;

			/// \brief Returns true if the first word is ordered after the second word
			bool operator >(const smtext::word&) const;

			/// \brief Returns true if the first word is ordered before or equal than the second word
			bool operator <=(const smtext::word&) const;

			/// \brief Returns true if the first word is ordered after or equal than the second word
			bool operator >=(const smtext::word&) const;

			/// \brief Returns a string containing the word
			string display() const;

			/// \brief Returns true if the word is a number
			bool is_number() const;

			/// \brief Returns true if the word is composed by letters and not by numbers
			bool is_letter_word() const;

			/// \brief Returns true if the word is composed only by characters of the language
			bool is_language_word() const;

			/// \brief Returns true if the word is a normal word related to the rules of the language, or a chat word with common characters switched
			bool is_chat_word() const;

			/// \brief Returns true if all the characters of the word are lowercase
			bool is_lowercase() const;

			/// \brief Returns true if all the characters of the word are uppercase
			inline bool is_uppercase() const
			{
				return !is_lowercase();
			}

			/// \brief Returns true if the first character is capitalized and all the others are lowercase
			bool is_capitalized() const;

			/// \brief Returns true if the word is not a chat word (or a language word)
			inline bool is_incorrect_word() const
			{
				return !is_chat_word();
			}

			/// \brief Returns true if the word is a day
			/// \param current_language language of the day
			bool is_day(language) const;

			/// \brief Returns true if the word is a month
			/// \param current_language language of the month
			bool is_month(language) const;

			bool is_improper(language) const;

			/// \brief Returns true if the word is an insult
			/// \param current_language language of the insult
			bool is_insult(language) const;
			bool is_sexual(language) const;
			bool is_sexual_insult(language) const;

			bool is_polytical(language) const;
			bool is_polytical_insult(language) const;

		private:
			string chars; ///< characters of the word
	};
}

/// \brief Returns true if the word is identical to the compared string
bool operator ==(string, const smtext::word&);

/// \brief Returns true if the word is different to the compared string
bool operator !=(string, const smtext::word&);

/// \brief Returns true if the word is identical to the compared string
bool operator ==(const smtext::word&,string);

/// \brief Returns true if the word is different to the compared string
bool operator !=(const smtext::word&,string);

/// \brief Returns true if the word is identical to the compared word
bool operator ==(const smtext::word&,const smtext::word&);

/// \brief Returns true if the word is different to the compared word
bool operator !=(const smtext::word&,const smtext::word&);

/// \brief Outputs the word to a ostream buffer
ostream& operator <<(ostream&, const smtext::word&);

#endif // WORD_HPP_INCLUDED
