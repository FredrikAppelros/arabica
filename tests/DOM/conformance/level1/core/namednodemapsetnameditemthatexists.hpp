#ifndef test_namednodemapsetnameditemthatexists
#define test_namednodemapsetnameditemthatexists


/*
This c++ source file was generated by for Arabica
and is a derived work from the source document.
The source document contained the following notice:


Copyright (c) 2001-2004 World Wide Web Consortium,
(Massachusetts Institute of Technology, Institut National de
Recherche en Informatique et en Automatique, Keio University). All
Rights Reserved. This program is distributed under the W3C's Software
Intellectual Property License. This program is distributed in the
hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.
See W3C License http://www.w3.org/Consortium/Legal/ for more details.

*/
/**
 *     If the node to be added by the "setNamedItem(arg)" method 
 *    already exists in the NamedNodeMap, it is replaced by
 *    the new one.
 *    
 *    Retrieve the second employee and create a NamedNodeMap 
 *    object from the attributes of the last child by
 *    invoking the "getAttributes()" method.  Once the
 *    list is created an invocation of the "setNamedItem(arg)"
 *    method is done with arg=newAttr, where newAttr is a
 *    new Attr Node previously created and whose node name
 *    already exists in the map.  The "setNamedItem(arg)"
 *    method should replace the already existing node with
 *    the new one.   
 *    This node is then retrieved using the "getNamedItem(name)"
 *    method.  This test uses the "createAttribute(name)"
 *    method from the document interface
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-1025163788">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-1025163788</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-349467F9">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-349467F9</a>
*/

template<class string_type, class string_adaptor>
class namednodemapsetnameditemthatexists : public DOMTestCase<string_type, string_adaptor> 
{
    typedef DOMTestCase<string_type, string_adaptor> baseT;
   public: 
     namednodemapsetnameditemthatexists(std::string name) : baseT(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = baseT::getContentType();
    baseT::preload(contentType, "staff", true);
    }

  typedef typename Arabica::DOM::DOMImplementation<string_type, string_adaptor>  DOMImplementation;
  typedef typename Arabica::DOM::Document<string_type, string_adaptor> Document; 
  typedef typename Arabica::DOM::DocumentType<string_type, string_adaptor> DocumentType;
  typedef typename Arabica::DOM::DocumentFragment<string_type, string_adaptor> DocumentFragment; 
  typedef typename Arabica::DOM::Node<string_type, string_adaptor> Node;
  typedef typename Arabica::DOM::Element<string_type, string_adaptor> Element;
  typedef typename Arabica::DOM::Attr<string_type, string_adaptor> Attr;
  typedef typename Arabica::DOM::NodeList<string_type, string_adaptor> NodeList;
  typedef typename Arabica::DOM::NamedNodeMap<string_type, string_adaptor> NamedNodeMap;
  typedef typename Arabica::DOM::Entity<string_type, string_adaptor> Entity;
  typedef typename Arabica::DOM::EntityReference<string_type, string_adaptor> EntityReference;
  typedef typename Arabica::DOM::CharacterData<string_type, string_adaptor> CharacterData;
  typedef typename Arabica::DOM::CDATASection<string_type, string_adaptor> CDATASection;
  typedef typename Arabica::DOM::Text<string_type, string_adaptor> Text;
  typedef typename Arabica::DOM::Comment<string_type, string_adaptor> Comment;
  typedef typename Arabica::DOM::ProcessingInstruction<string_type, string_adaptor> ProcessingInstruction;
  typedef typename Arabica::DOM::Notation<string_type, string_adaptor> Notation;

  typedef typename Arabica::DOM::DOMException DOMException;
  typedef string_type String;
  typedef string_adaptor SA;
  typedef bool boolean;


   /*
    * Runs the test case.
    */
   void runTest()
   {
      Document doc;
      NodeList elementList;
      Attr newAttribute;
      Node testAddress;
      NamedNodeMap attributes;
      Attr districtNode;
      String attrValue;
      Node setNode;
      doc = (Document) baseT::load("staff", true);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("address"));
      testAddress = elementList.item(1);
      newAttribute = doc.createAttribute(SA::construct_from_utf8("street"));
      attributes = testAddress.getAttributes();
      setNode = attributes.setNamedItem(newAttribute);
      districtNode = (Attr) attributes.getNamedItem(SA::construct_from_utf8("street"));
      attrValue = districtNode.getNodeValue();
      baseT::assertEquals("", attrValue, __LINE__, __FILE__);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/namednodemapsetnameditemthatexists";
   }
};

#endif
