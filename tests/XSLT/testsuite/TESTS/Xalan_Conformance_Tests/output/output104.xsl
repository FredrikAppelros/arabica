<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
  xmlns:baz="http://baz.com">

  <!-- FileName: OUTPUT104 -->
  <!-- Document: http://www.w3.org/TR/xslt -->
  <!-- DocVersion: 19991116 -->
  <!-- Section: 16.1 -->
  <!-- Creator: David Bertoni -->
  <!-- Purpose: Use cdata-section-elements with xsl:copy-of, namespaces match. -->

<xsl:output method="xml" cdata-section-elements="baz:out" encoding="UTF-8"/>

<xsl:template match="/">
  <xsl:copy-of select="*"/>
</xsl:template>

</xsl:stylesheet>