#ifndef ARABICA_XSLT_CREATE_HANDLER_HPP
#define ARABICA_XSLT_CREATE_HANDLER_HPP

#include <SAX/XMLReader.hpp>
#include <SAX/helpers/DefaultHandler.hpp>
#include <XPath/XPath.hpp>

#include "../xslt_compilation_context.hpp"
#include "../xslt_compiled_stylesheet.hpp"
#include "xslt_constants.hpp"

namespace Arabica
{
namespace XSLT
{

template<class Handler, class string_type, class string_adaptor>
SAX::DefaultHandler<string_type, string_adaptor>* CreateHandler(CompilationContext<string_type, string_adaptor>& context)
{
  return new Handler(context);
} // create

template<class string_type, class string_adaptor>
class NotImplementedYetHandler : public SAX::DefaultHandler<string_type, string_adaptor>
{
public:
  NotImplementedYetHandler(CompilationContext<string_type, string_adaptor>& /* context */) { }

  virtual void startElement(const string_type& /* namespaceURI */,
                            const string_type& /* localName */,
                            const string_type& qName,
                            const SAX::Attributes<string_type, string_adaptor>& /* atts */)
  {
    throw SAX::SAXException("Haven't implemented " + string_adaptor::asStdString(qName) + " yet");
  } // startElement
}; // NotImplementedYetHandler

template<class string_type, class string_adaptor> 
struct ChildElement
{
  typedef SAX::DefaultHandler<string_type, string_adaptor>* (*CreateHandlerPtr)(CompilationContext<string_type, string_adaptor>&);

  const string_type name;
  CreateHandlerPtr createHandler;
}; // struct ChildElement

} // namespace XSLT
} // namespace Arabica

#endif // ARABICA_XSLT_CONSTANTS_HPP

