#ifndef ARABICA_UTILS_ROT13_CODECVT_H
#define ARABICA_UTILS_ROT13_CODECVT_H
///////////////////////////////////////////
//
// $Id$
//
///////////////////////////////////////////

#include <locale>

class rot13_codecvt : public std::codecvt<char, char, std::char_traits<char>::state_type>
{
public:
  typedef std::char_traits<char>::state_type state_t;

protected:
  virtual ~rot13_codecvt();

  virtual result do_out(state_t& state,
                        const char* from,
                        const char* from_end,
                        const char*& from_next,
                        char* to,
                        char* to_limit,
                        char*& to_next) const 
      { return rot13(from, from_end, from_next, to, to_limit, to_next); }

  virtual result do_in(state_t& state,
                       const char* from,
                       const char* from_end,
                       const char*& from_next,
                       char* to,
                       char* to_limit,
                       char*& to_next) const
      { return rot13(from, from_end, from_next, to, to_limit, to_next); }

  virtual result do_unshift(state_t&  state,
                       char* to,
                       char* to_limit,
                       char*& to_next) const;

  virtual int do_encoding() const throw();

  virtual bool do_always_noconv() const throw();

  virtual int do_length(const state_t&,
                        const char* from,
                        const char* end,
                        size_t max) const;

  virtual int do_max_length() const throw();

private:
  result rot13(const char* from,
               const char* from_end,
               const char*& from_next,
               char* to,
               char* to_limit,
               char*& to_next) const;
}; // class rot13_codecvt

#endif
