#ifndef JEZUK_SimpleDOM_DOCUMENTFRAGMENTIMPL_H
#define JEZUK_SimpleDOM_DOCUMENTFRAGMENTIMPL_H

#include <DOM/DocumentFragment.h>

namespace SimpleDOM
{

template<class stringT, class string_adaptorT>
class DocumentFragmentImpl : public DOM::DocumentFragment_impl<stringT>,
                             public NodeImplWithChildren<stringT, string_adaptorT>
{
  public:
    DocumentFragmentImpl(DocumentImpl<stringT, string_adaptorT>* ownerDoc) : 
        DOM::DocumentFragment_impl<stringT>(),
        NodeImplWithChildren<stringT, string_adaptorT>(ownerDoc)
    { 
    } // DocumentFragmentImpl

    virtual ~DocumentFragmentImpl() { }

    ///////////////////////////////////////////////////////
    // DOM::Node methods
    virtual DOM::Node_base::Type getNodeType() const 
    { 
      return DOM::Node_base::DOCUMENT_FRAGMENT_NODE; 
    } // getNodeType

    virtual DOM::Node_impl<stringT>* cloneNode(bool deep) const
    {
      DOM::Node_impl<stringT>* clone = ownerDoc_->createDocumentFragment();
      if(deep)
        for(DOM::Node_impl<stringT>* c = getFirstChild(); c != 0; c = c->getNextSibling())
          clone->appendChild(c->cloneNode(true));
      return clone;
    } // cloneNode

    virtual stringT getNodeName() const 
    {
      string_adaptorT SA;
      return SA.makeStringT("#document-fragment");
    } // getNodeName

    virtual DOM::Node_impl<stringT>* getParentNode() const 
    { 
      return 0; 
    } // getParentNode

  private:
    virtual void checkChildType(DOM::Node_impl<stringT>* child)
    {
      DOM::Node<stringT>::Type type = child->getNodeType();
      if((type != DOM::Node<stringT>::ELEMENT_NODE) && 
         (type != DOM::Node<stringT>::PROCESSING_INSTRUCTION_NODE) && 
         (type != DOM::Node<stringT>::COMMENT_NODE) && 
         (type != DOM::Node<stringT>::TEXT_NODE) && 
         (type != DOM::Node<stringT>::CDATA_SECTION_NODE) && 
         (type != DOM::Node<stringT>::ENTITY_REFERENCE_NODE)) 
        throw DOM::DOMException(DOM::DOMException::HIERARCHY_REQUEST_ERR);
    } // checkChildType
}; // class DocumentFragmentImpl


} // namespace SAX2DOM

#endif

