/**
* Facebook Internet Explorer Toolbar Software License 
* Copyright (c) 2009 Facebook, Inc. 
*
* Permission is hereby granted, free of charge, to any person or organization
* obtaining a copy of the software and accompanying documentation covered by
* this license (which, together with any graphical images included with such
* software, are collectively referred to below as the "Software") to (a) use,
* reproduce, display, distribute, execute, and transmit the Software, (b)
* prepare derivative works of the Software (excluding any graphical images
* included with the Software, which may not be modified or altered), and (c)
* permit third-parties to whom the Software is furnished to do so, all
* subject to the following:
*
* The copyright notices in the Software and this entire statement, including
* the above license grant, this restriction and the following disclaimer,
* must be included in all copies of the Software, in whole or in part, and
* all derivative works of the Software, unless such copies or derivative
* works are solely in the form of machine-executable object code generated by
* a source language processor.  
*
* Facebook, Inc. retains ownership of the Software and all associated
* intellectual property rights.  All rights not expressly granted in this
* license are reserved by Facebook, Inc.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*/ 



#ifndef XMLUTILS_H
#define XMLUTILS_H

#include "Error.h"
#include "StringUtils.h"

#import <msxml3.dll>  named_guids

namespace facebook {

/**
 * different utility functions deal with xml are 
 * concentrated in XMLUtils namespace 
 */
namespace XMLUtils {
   
/**
 *  @param  node - source node
 *
 *  @return - text value
 */
String getNodeText(MSXML2::IXMLDOMNodePtr& node);

/**
 *  Retrieves text value  from child node
 *
 *  @param  parent - parent node
 *  @param  childNodeName - the name of target child nod
 *
 *  @return - text value of child node
 */
String getChildText(MSXML2::IXMLDOMNodePtr& parent, const String& childNodeName);


/**
 *  Creates XMLNode
 *
 *  @param  xmlDoc - source xml document
 *  @param  nodeName - the name of target child node
 *
 *  @return - created XML node 
 */
MSXML2::IXMLDOMNodePtr createNode(MSXML2::IXMLDOMDocumentPtr& xmlDoc, 
     const String& nodeName);


/**
 *  Change text of specified node
 *
 *  @param node
 *  @param  text to set to node
 *
 */
void setNodeText(MSXML2::IXMLDOMNodePtr& node, const String& text);

/**
 * Calculates children count
 *
 *  @param node - xml node to be asked for children count 
 *
 *  @return number of children of given node
 */
size_t getChildrenCount(MSXML2::IXMLDOMNodePtr& node);


/**
 * Creates XMLNode and assign given text to it
 *
 * @param xmlDoc - source xml document
 * @param nodeName - the name of target child node
 * @param text to be assigned to specified node
 *
 * @return - created XML node 
 */
MSXML2::IXMLDOMNodePtr createNodeWithText(MSXML2::IXMLDOMDocumentPtr& xmlDoc, 
  const String& nodeName, const String& text);

/**
 * Checks if given node has corresponding attribute
 *
 * @param node - node to be asked for attribute existence
 * @param attributeName
 * @param attributeNameSpace
 *
 * @return - true if requested attribute belongs to node, false - 
 *               otherwise
 */
bool hodeHasAttribute(MSXML2::IXMLDOMNodePtr& node, 
  const String& attributeName, const String attributeNameSpace);

/**
 * Creates xml attribute and add it to target node
 *
 * @param xmlDoc - source xml document
 * @param attributeName
 * @param attributeValue
 *
 */
void  addTextAttributeToNode(MSXML2::IXMLDOMDocumentPtr& xmlDoc,
     MSXML2::IXMLDOMNodePtr& targetNode, const String& attributeName, 
     const String& attributeValue);

/**
 * Create string value of XML document 
 *
 * @param xmlDoc - source xml document
 */

String xmlToString(MSXML2::IXMLDOMDocumentPtr xmlDoc);


/**
 * class ParseError
 *
 * Throwed when some errors with xml parsing occured
 *
 */
class ParseError : public facebook::Error{
};

}}// !namespace facebook::XMLUtils


#endif