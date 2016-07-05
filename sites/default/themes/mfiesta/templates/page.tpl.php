<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
?>
<div <?php print drupal_attributes($page['attributes_array']['page']); ?>>
    <div class="header" <?php print drupal_attributes($page['attributes_array']['header']); ?>>
     <?php if(node_selection_contador_nodes() > 0 ) {
        print node_selection_block_content(); }
?>

      <a href="http://m.fiestarentals.ca/" data-role="button" class="logo" data-corners="false" style="border: 0px none; margin: 0px; padding: 0px;width: 100%;">
        <img src="/sites/default/files/logo.jpg" alt="<?php print t('Home'); ?>" style="width: 100%" />
      </a>
      </div> <!-- /#header -->


    <div class="main-content" <?php print drupal_attributes($page['attributes_array']['content']); ?>>

        <div class="content-primary">

          <?php if ($title): ?><h1 class="title" class="page-title"><?php print $title; ?></h1><?php endif; ?>
          
          <?php print render($page['content']); ?>
           
        <a href='#' data-rel='back' class='back'>Back</a>
        </div> <!-- /.content-primary -->
        
        
              
    </div>

    <div class="footer" <?php print drupal_attributes($page['attributes_array']['footer']); ?>>        
      <?php print render($page['footer']); ?>
      <nav data-role="navbar">
        <ul>
            <li><a href="/about-fiesta-4-kids" >About Us</a></li>
            <li><a href="/party-rental-toronto" >Service</a></li>
            <li><a href="/faq-page" >FAQ</a></li>
        </ul>
        </nav>
        <nav data-role="navbar">
        <ul>
            <li><a href="#" >Specials</a></li>
            <li><a href="/nselect/form" >Reserve</a></li>
            <li><a href="/form/contact-us" >Contact</a></li>
        </ul>
        </nav>
    </div> <!-- /#footer -->

</div> <!-- /#page -->
