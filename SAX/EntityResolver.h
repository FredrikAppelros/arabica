#ifndef EntityResolverH
#define EntityResolverH

// EntityResolver.h 
// $Id$

#include <string>
#include <SAX/InputSource.h>

namespace SAX
{

/**
 * Basic interface for resolving entities.
 *
 * <p>If a SAX application needs to implement customized handling
 * for external entities, it must implement this interface and
 * register an instance with the SAX driver using the
 * {@link basic_XMLReader#setEntityResolver setEntityResolver}
 * method.</p>
 *
 * <p>The XML reader will then allow the application to intercept any
 * external entities (including the external DTD subset and external
 * parameter entities, if any) before including them.</p>
 *
 * <p>Many SAX applications will not need to implement this interface,
 * but it will be especially useful for applications that build
 * XML documents from databases or other specialised input sources,
 * or for applications that use URI types other than URLs.</p>
 *
 * <p>The following resolver would provide the application
 * with a special character stream for the entity with the system
 * identifier "http://www.myhost.com/today":</p>
 *
 * <pre>
 * #include &lt;EntityResolver&gt;
 * #include &lt;InputSource&gt;
 *
 * public class MyResolver implements SAX::EntityResolver 
 * {
 *   public InputSource resolveEntity (const std::string& publicId, const std::string& systemId)
 *   {
 *     if(systemId == "http://www.myhost.com/today") 
 *     {
 *       // return a special input source
 *       MyReader reader = new MyReader();
 *       return SAX::InputSource(reader);
 *     } else {
 *       // request default behaviour
 *       return SAX::InputSource();
 *     }
 *   }
 * }
 * </pre>
 *
 * <p>The application can also use this interface to redirect system
 * identifiers to local URIs or to look up replacements in a catalog
 * (possibly by using the public identifier).</p>
 *
 * @since SAX 1.0
 * @author Jez Higgins, 
 *         <a href="mailto:jez@jezuk.co.uk">jez@jezuk.co.uk</a>
 * @version 2.0
 * @see basic_Parser#setEntityResolver
 * @see basic_InputSource
 */
template<class string_type>
class basic_EntityResolver
{
public:
  typedef string_type stringT;
  typedef basic_InputSource<stringT> InputSourceT;

	virtual ~basic_EntityResolver() { };

  /**
   * Allow the application to resolve external entities.
   *
   * <p>The Parser will call this method before opening any external
   * entity except the top-level document entity (including the
   * external DTD subset, external entities referenced within the
   * DTD, and external entities referenced within the document
   * element): the application may request that the parser resolve
   * the entity itself, that it use an alternative URI, or that it
   * use an entirely different input source.</p>
   *
   * <p>Application writers can use this method to redirect external
   * system identifiers to secure and/or local URIs, to look up
   * public identifiers in a catalogue, or to read an entity from a
   * database or other input source (including, for example, a dialog
   * box).</p>
   *
   * <p>If the system identifier is a URL, the SAX parser must
   * resolve it fully before reporting it to the application.</p>
   *
   * @param publicId The public identifier of the external entity
   *        being referenced, or null if none was supplied.
   * @param systemId The system identifier of the external entity
   *        being referenced.
   * @return An InputSource object describing the new input source,
   *         or null to request that the parser open a regular
   *         URI connection to the system identifier.
   * @exception SAXException Any SAX exception.
   * @see basic_InputSource
   */
   virtual InputSourceT resolveEntity(const stringT& publicId, const stringT& systemId) = 0;
}; // class EntityResolver

typedef basic_EntityResolver<std::string> EntityResolver;
typedef basic_EntityResolver<std::wstring> wEntityResolver;

}; // namespace SAX

#endif
// end of file
