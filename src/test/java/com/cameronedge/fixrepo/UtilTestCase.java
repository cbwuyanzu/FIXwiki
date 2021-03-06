/*
 * Copyright (c) 2009 Cameron Edge Pty Ltd. All rights reserved.
 * Reproduction in whole or in part in any form or medium without express
 * written permission of Cameron Edge Pty Ltd is strictly prohibited.
 */

package com.cameronedge.fixrepo;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import java.io.StringWriter;
import java.io.Writer;
import java.util.List;

import static com.cameronedge.fixwiki.FixwikiUtil.formatDescription;
import static com.cameronedge.fixwiki.FixwikiUtil.writeWikiTable;
import static org.junit.Assert.assertEquals;

/**
 * FixwikiUtil test case.
 *
 * @author John Cameron
 */
public class UtilTestCase {

  @Before
  public void setUp() throws Exception {
  }

  @After
  public void tearDown() throws Exception {
  }

  
  @Test
  public void textChar() {
    char c = '?';
    char c2 = '?';

    System.out.println("Arrow :" + (int) c + " ? : " + (int)c2);
  }
  
  @Test
  public void testParseMSWordTable() throws Exception {
    String pastedTable = 
    "	PartyRelationship	Applicable PartyRole	Applicable RelatedPartyRole\n" +
    "1 - Clears for	Clearing Firm\n" +
    "Prime Broker\n" +
    "Clearing Account	Executing Firm\n" +
    "Customer Account\n" +
    "Introducing Broker\n" +
    "Broker Clearing ID\n" +
    "3 - Trades for	Executing Firm\n" +
    "Executing Trader	Customer Account\n" + 
    "Clearing Account";

    List<String[]> parsedTable = RepoUtil.parseMSWordTable(pastedTable, 3);
    
    Writer writer = new StringWriter();
    writeWikiTable(writer, parsedTable, null);

    System.out.println(writer);
    
    assertEquals(3, parsedTable.size());
    
    
  }
  
  @Test
  public void testFormatDescription() {

    String s = formatDescription("*I was > than I'd thought but < than I'd wished\nPigs bum", null);
    System.out.println(s);

    s = formatDescription(":I was > than I'd thought but < than I'd wished\n Pigs bum", null);
    System.out.println(s);

    s = formatDescription(" I was > than I'd thought but < than I'd wished\n*Pigs bum\n Dogs bum", null);
    System.out.println(s);

  }

      
}
