#ifndef ARABICA_XSLT_MESSAGE_HANDLER_HPP
#define ARABICA_XSLT_MESSAGE_HANDLER_HPP

#include "../xslt_message.hpp"
#include "xslt_item_container_handler.hpp"

namespace Arabica
{
namespace XSLT
{

template<class string_type, class string_adaptor>
class MessageHandler : public ItemContainerHandler<Message<string_type, string_adaptor> >
{
  typedef ItemContainerHandler<Message<string_type, string_adaptor> > baseT;
  typedef StylesheetConstant<string_type, string_adaptor> SC;
public:
  MessageHandler(CompilationContext<string_type, string_adaptor>& context) :
      baseT(context)
  {
  } // MessageHandler

protected:
  virtual Message<string_type, string_adaptor>* createContainer(const string_type& /* namespaceURI */,
                                   const string_type& /* localName */,
                                   const string_type& qName,
                                   const SAX::Attributes<string_type, string_adaptor>& atts)
  {
    static const ValueRule<string_type> rules[] = { { SC::terminate, false, SC::no, SC::AllowedYesNo },
                                                    { string_adaptor::empty_string(), false, 0, 0 } };
    return new Message<string_type, string_adaptor>(gatherAttributes(qName, atts, rules)[SC::terminate] == SC::yes);
  } // createContainer
}; // class MessageHandler

} // namespace XSLT
} // namespace Arabica

#endif 

