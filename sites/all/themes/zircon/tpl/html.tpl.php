<?php

/**
 * @file html.tpl.php
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 * @see nucleus_preprocess_html()
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
  <head>
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
	<!-- META FOR IOS & HANDHELD -->
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=yes"/>
    <meta name="HandheldFriendly" content="true" />
    <meta name="apple-touch-fullscreen" content="YES" />    
<script language="javascript" type="text/javascript">
function showHide(shID) {
   if (document.getElementById(shID)) {
      if (document.getElementById(shID+'-show').style.display != 'none') {
         document.getElementById(shID+'-show').style.display = 'none';
         document.getElementById(shID).style.display = 'block';
      }
      else {
         document.getElementById(shID+'-show').style.display = 'inline';
         document.getElementById(shID).style.display = 'none';
      }
   }
}

</script>
<style type="text/css">
   .more {
      display: none; }
   a.showLink, a.hideLink {
      text-decoration: none;
      color: #36f;
      padding-left: 8px;}
#page-title {
height: auto;
padding-bottom: 25px;
}
#article-815 > div > div.field.field-name-field-addthis.field-type-addthis.field-label-hidden > div > div > div {
width: 108px;
}


#article-815 > div > div.field.field-name-body.field-type-text-with-summary.field-label-hidden > div > div > p:nth-child(1) > img{margin-left: 14% !important }

#block-block-30--2 .sb.circle.glossy.gray.no-border.no-shadow.instagram{
margin-right:100px
}

</style>

    <!-- //META FOR IOS & HANDHELD -->
     <link rel="publisher" href="https://plus.google.com/110081187329690512195/about " />
     
     <script src="/sites/all/themes/zircon/js/jquery.min.js"></script>
    <?php  #if (drupal_is_front_page()) { ?>    
   
    
 <?php # } ?>
    <?php print $styles; ?>
    <?php print $scripts; ?>    
    
    <script>
		$(document).ready(function(){
		  /*$(".taxonomy_term").attr("href", "http://www.fiesta4kids.com/catalog/interactive-games-sports");*/
		  $('.field-content').html(function(i, v) {
		    return v.replace(/-%26/g, '');    
			});
		});
	</script>
	<!-- Google Code for Remarketing Tag -->
	<!--------------------------------------------------
	Remarketing tags may not be associated with personally identifiable information or placed on pages related to sensitive categories. See more information and instructions on how to setup the tag on: http://google.com/ads/remarketingsetup
	--------------------------------------------------->
	<script type="text/javascript">
	/* <![CDATA[ */
	var google_conversion_id = 1039154613;
	var google_custom_params = window.google_tag_params;
	var google_remarketing_only = true;
	/* ]]> */
	</script>
	<script type="text/javascript" src="//www.googleadservices.com/pagead/conversion.js">
	</script>
	<noscript>
	<div style="display:inline;">
	<img height="1" width="1" style="border-style:none;" alt="" src="//googleads.g.doubleclick.net/pagead/viewthroughconversion/1039154613/?value=0&amp;guid=ON&amp;script=0"/>
	</div>
	</noscript>
  </head>

  <body class="<?php print $classes; ?>"<?php print $attributes;?>>
    <div id="skip-link"><a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a></div>
    <?php print $page_top; ?>
    <?php print $page; ?>
    <?php print $page_bottom; ?>

<!-- Google Code for Thank you for contacting us ! Conversion Page -->
<?php if($_SERVER['REQUEST_URI'] == '/node/51/done') { ?>
<script type="text/javascript">
/* <![CDATA[ */
var google_conversion_id = 1039154613;
var google_conversion_language = "en";
var google_conversion_format = "2";
var google_conversion_color = "ffffff";
var google_conversion_label = "gg8RCK-60gQQtfvA7wM";
var google_conversion_value = 1.000000;
var google_remarketing_only = false;
/* ]]> */
</script>
<script type="text/javascript" src="//www.googleadservices.com/pagead/conversion.js">
</script>
<noscript>
<?php } ?>
<div style="display:inline;">
<img height="1" width="1" style="border-style:none;" alt="" src="//www.googleadservices.com/pagead/conversion/1039154613/?value=1.000000&amp;label=gg8RCK-60gQQtfvA7wM&amp;guid=ON&amp;script=0"/>
</div>
</noscript>

  </body>
</html>
