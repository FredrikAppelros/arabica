<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

<xsl:output method="xml" omit-xml-declaration="yes" indent="yes"/>

<xsl:template match="book[@style='autobiography']">
    <I> 
    <xsl:value-of select="name()"/> : <xsl:value-of select="title"/>     
   
    </I> <xsl:apply-templates/>
</xsl:template>

<xsl:template match="text()" >
</xsl:template>

</xsl:stylesheet>