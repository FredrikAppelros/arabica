#ifndef Attributes2H
#define Attributes2H

// Attributes2.h
// $Id$

#include <SAX/Attributes.h>

namespace SAX
{

/**
 * SAX2 extension to augment the per-attribute information provided though Attributes. 
 *
 * If an implementation supports 
 * this extension, the attributes provided in 
 * ContentHandler.startElement()  will implement this 
 * interface, and the http://xml.org/sax/features/use-attributes2  
 * feature flag will have the value true.
 *
 * @since SAX 2.0
 * @author Jez Higgins, 
 *         <a href="mailto:jez@jezuk.co.uk">jez@jezuk.co.uk</a>
 * @version 2.0
 * @see basic_Attributes
 * @see basic_Attributes2Impl
 */
template<class string_type>
class basic_Attributes2 : public basic_Attributes<string_type>
{

public:
  typedef string_type stringT;
  virtual ~basic_Attributes2() { }

  /**
   *  Returns true unless the attribute value was provided by DTD defaulting.
   *
   * @param index - The attribute index (zero-based).
   * @return true if the value was found in the XML text, 
   *         false if the value was provided by DTD defaulting.
   * @throws std::out_of_range exception when the supplied index
   *         does not identify an attribute
   */
  virtual bool isSpecified(unsigned int index) const = 0;
  /**
   *  Returns true unless the attribute value was provided by DTD defaulting.
   *
   * @param index - The attribute index (zero-based).
   * @return true if the value was found in the XML text, 
   *         false if the value was provided by DTD defaulting.
   * @throws std::invalid_argument exception when the supplied name
   *         does not identify an attribute
   */
  virtual bool isSpecified(const stringT& qName) const = 0;
  /**
   *  Returns true unless the attribute value was provided by DTD defaulting.
   *
   * @param index - The attribute index (zero-based).
   * @return true if the value was found in the XML text, 
   *         false if the value was provided by DTD defaulting.
   * @throws std::invalid_argument exception when the supplied names
   *         does not identify an attribute
   */
  virtual bool isSpecified(const stringT& uri, const stringT& locaName) const = 0;
}; // class basic_Attributes2

typedef basic_Attributes2<std::string> Attributes2;
typedef basic_Attributes2<std::wstring> wAttributes2;

}; // namespace SAX

#endif
// end of file
