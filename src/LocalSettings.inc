<?php

#$wgReadOnly = "Backing up FIXwiki";

$wgEnableUploads = true;

#Enable short urls.
# See http://www.mediawiki.org/wiki/Manual:Short_URL. 
# The following assumes that you are using an Apache server.
# See http://www.mediawiki.org/wiki/Manual:Short_URL/Apache
#
#The following only works if...
# 1. Apache's rewrite module is loaded (it isn't by default). 
#    See, for example, http://www.ducea.com/2006/05/30/managing-apache2-modules-the-debian-way/ 
# 2. you have installed MediaWiki into "w" 
# 3. your Apache .htaccess file has the following lines in it:
#RewriteEngine On
#RewriteRule ^/?fixwiki(/.*)?$ %{DOCUMENT_ROOT}/w/index.php [L]
#RewriteRule ^/*$ %{DOCUMENT_ROOT}/w/index.php [L]

$wgArticlePath = "/fixwiki/$1";
$wgUsePathInfo = true;

$wgUseAjax = true;
$wgEnableMWSuggest = true;
$wgLogo = "$wgScriptPath/images/FIX_logo.146px.png" ;
$wgFavicon = "$wgScriptPath/images/favicon.ico";
$wgRightsIcon = "$wgScriptPath/images/cameronedge_logo_blueSmall.png";
$wgRightsUrl = "http://cameronedge.com/";
$wgRightsText = "FIXwiki copyrights";
$wgRightsPage = "FIXwiki:Copyrights";
$wgEmailConfirmToEdit = true;

$wgFileExtensions[] = 'txt'; //Used for FIXnames.txt file

$wgNamespacesWithSubpages[NS_MAIN] = true;
$wgNamespacesWithSubpages[NS_TALK] = true;
$wgNamespacesWithSubpages[NS_CATEGORY] = true;
$wgNamespacesWithSubpages[NS_CATEGORY_TALK] = true;

#Wiki requires login to read or edit
$wgGroupPermissions['*']['edit'] = false;
$wgGroupPermissions['*']['read'] = true;
$wgWhitelistRead = array(
  'FIXwiki',
  'FIXwiki:About',
  'FIXwiki:Copyrights',
  'FIXwiki:Structure',
  'FIXwiki:Use',
  'Special:RecentChanges',
  'MediaWiki:Common.css',
  'MediaWiki:Monobook.css',
  'MediaWiki:Modern.css',
  '-',
  'Special:RequestAccount',
);

#Add FPL namespace
define("NS_FPL", 100);
define("NS_FPL_TALK", 101);
$wgExtraNamespaces = array(
  NS_FPL => 'FPL',
  NS_FPL_TALK => 'FPL_talk'
);

$wgNamespacesWithSubpages[NS_FPL] = true;
$wgNamespacesWithSubpages[NS_FPL_TALK] = true;

#Namespace protection
$wgNamespaceProtection[NS_PROJECT] = array('editinterface');
$wgNamespaceProtection[NS_FPL] = array('editinterface');
$wgNamespaceProtection[NS_TEMPLATE] = array('editinterface');
$wgNamespaceProtection[NS_HELP] = array('editinterface');
$wgNamespaceProtection[NS_CATEGORY] = array('editinterface');

$wgExternalLinkTarget = '_blank';

require_once( "$IP/extensions/ParserFunctions/ParserFunctions.php" );
require_once("$IP/extensions/SubPageList/SubPageList.php"); // for SubPageList extension

##Confirm account edit stuff
require_once("$IP/extensions/ConfirmAccount/ConfirmAccount.php");
$wgAccountRequestToS = true;
$wgUseRealNamesOnly = true;
$wgRequestExtraInfo = false;
$wgAccountRequestMinWords = 10;
$wgAllowAccountRequestFiles = false;
$wgConfirmAccountContact = "fpl@fixprotocol.org" ;

$wgSMTP = array(
 'host'     => "mail.fixwiki.org",
 'IDHost'   => "fixwiki.org",
 'port'     => 26,
 'auth'     => true,
 'username' => "admin@fixwiki.org",
 'password' => "qmc]Kps43)TQ"
);

$wgPasswordSender = "admin@fixwiki.org";
$wgPasswordSenderName = "FIXwiki administrator";

# Added by nic@angel.net on 23 Feb 2011
function lessSpecialPages (&$list) {
	global $wgUser;
	if ( ! $wgUser->isAllowed('editinterface') ) { 
		unset( $list['Listusers'] );
		unset( $list['Listgrouprights'] );
		unset( $list['Activeusers'] );
	}
	return true;
}
$wgHooks['SpecialPage_initList'][] = 'lessSpecialPages';

# Added by nic@angel.net on 23 Feb 2011
$wgConfirmAccountRejectAge = 5 * 24 * 3600; // 5 days

# Added by nic@angel.net on 24 Feb 2011
$wgRightsPage = 'FIXwiki:Terms_of_Use';

# Specify standard FIXwiki style
$wgDefaultSkin = 'monobook';
