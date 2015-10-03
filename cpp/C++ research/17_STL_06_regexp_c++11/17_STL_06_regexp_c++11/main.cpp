//Examples from
//http://www.cplusplus.com/reference/regex/regex_match/
//http://www.cplusplus.com/reference/regex/regex_replace/
//http://www.cplusplus.com/reference/regex/regex_search/


// regex_match example
#include <iostream>
#include <string>
#include <regex>
#include <iterator>



void mymatch()
{
	if (std::regex_match ("subject", std::regex("(sub)(.*)") ))
		std::cout << "string literal matched\n";
	
	const char cstr[] = "subject";
	std::string s ("subject");
	std::regex e ("(sub)(.*)");
	
	if (std::regex_match (s,e))
		std::cout << "string object matched\n";
	
	if ( std::regex_match ( s.begin(), s.end(), e ) )
		std::cout << "range matched\n";
	
	std::cmatch cm;    // same as std::match_results<const char*> cm;
	std::regex_match (cstr,cm,e);
	std::cout << "string literal with " << cm.size() << " matches\n";
	
	std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
	std::regex_match (s,sm,e);
	std::cout << "string object with " << sm.size() << " matches\n";
	
	std::regex_match ( s.cbegin(), s.cend(), sm, e);
	std::cout << "range with " << sm.size() << " matches\n";
	
	// using explicit flags:
	std::regex_match ( cstr, cm, e, std::regex_constants::match_default );
	
	std::cout << "the matches were: ";
	for (unsigned i=0; i<sm.size(); ++i) {
		std::cout << "[" << sm[i] << "] ";
	}
	
	std::cout << std::endl;
}

void myreplace()
{
	std::string s ("there is a subsequence in the string\n");
	std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"
	
	// using string/c-string (3) version:
	std::cout << std::regex_replace (s,e,"sub-$2");
	
	// using range/c-string (6) version:
	std::string result;
	std::regex_replace (std::back_inserter(result), s.begin(), s.end(), e, "$2");
	std::cout << result;
	
	// with flags:
	std::cout << std::regex_replace (s,e,"$1 and $2",std::regex_constants::format_no_copy);
	std::cout << std::endl;	
}

void mysearch()
{
	std::string s ("this subject has a submarine as a subsequence");
	std::smatch m;
	std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"
	
	std::cout << "Target sequence: " << s << std::endl;
	std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
	std::cout << "The following matches and submatches were found:" << std::endl;

	while (std::regex_search (s,m,e)) {
		for (auto x:m) std::cout << x << " ";
		std::cout << std::endl;
		s = m.suffix().str();
	}
}

int main ()
{

// MATCH
	mymatch();
	std::cout << "" << std::endl;
	
// REPLACE
	myreplace();
	std::cout << "" << std::endl;

// SEARCH	
	mysearch();
	
  return 0;
}
