<?php

/**
 * @file barrio.skinr.inc
 * Implementation of a Skinr plugin.
 */
 
/**
 * Implements hook_skinr_group_info().
 *
 * Optional. Defines group(s) that will contain skins. Groups are form element
 * containers used to organize skins categorically using vertical_tabs. If you
 * don't define a group, your skins will appear in Skinr's default group, which
 * is labeled "General."
 *
 * Group name(s):
 * Each group name must be unique. It is recommended to prefix the name of each
 * group with the name of the theme or module name implementing it, followed by
 * the name of the group. Note that you cannot define 2 groups with the same
 * the same name, even if they are in different plugins.
 *
 * Group properties:
 * - title (required): Brief title of the tab.
 * - description (optional): Description of the tab group.
 * - weight (discouraged): Weight of the tab group; NULL by default.
 *
 * The "hook" prefix is substituted with the name of the module or theme that
 * implements it, followed by the plugin name, e.g.
 * THEMENAME_PLUGINNAME_skinr_group_info(), or
 * MODULENAME_PLUGINNAME_skinr_group_info().
 */
function barrio_skinr_group_info() {
  $groups['barrio_links'] = array(
    'title' => t('Links and Menus'),
    'description' => t('Choose one or more styles to apply to links and menus.'),
  );
  return $groups;
}

/**
 * Implements hook_skinr_skin_info().
 *
 * Required. Define the skin(s) for this Skinr plugin. Each skin definition
 * consists of properties that define its form element and settings that are
 * needed to make it work, such as the class(es) Skinr should apply, which files
 * it should load, whether or not it should be disabled by default and which
 * theme hook(s) it was designed to work with.
 *
 * Skin name(s):
 * Each skin name must be unique. It is recommended to prefix the name of each
 * skin with the name of the theme or module name implementing it, followed by
 * the name of the skin. Note that you cannot define 2 skins with the same
 * the same name, even if they are in different plugins.
 *
 * Skin settings:
 * - title (required): Title of the skin form element.
 * - description (optional): Description of the skin form element.
 * - group (optional): The group the skin is attached to; defaults to a Skinr
 *   provided group labeled "General."
 * - type (optional): The type of form element. Allowed values:
 *   - checkboxes (default): Useful when single or multiple options can be
 *     chosen.
 *     Does not need to be set manually, as Skinr will apply this by default.
 *   - select: Useful when a single option can be chosen, but many exist.
 *   - radios: Useful when a single option can be chosen and only a few options
 *     exist.
 * - weight (discouraged): Sets the weight of the skin inside the group; NULL
 *   by default. weight should not be set on each individual skin. Instead 
 * - attached (optional): A array containing information about CSS and
 *   JavaScript files the skin requires. Each entry is an array keyed by type:
 *   - css (optional): Maps to the functionality of drupal_add_css() with one
 *     exception: paths are automatically assumed relative to the plugin
 *     directory, unless external. Examples:
 *     - Simple:
 *       'css' => array('css/skin-name.css')
 *     - Advanced:
 *       'css' => array(
 *         array('css/skin-name-ie.css', array(
 *           'media' => 'screen',
 *           'browsers' => array('IE' => 'lte IE 8'),
 *         ),
 *       )
 *   - js (optional): Maps to the functionality of drupal_add_js() with one
 *     exception: paths are automatically assumed as relative to the plugin
 *     directory, unless external. Examples:
 *     - Simple:
 *       'js' => array('js/skin-name.js')
 *     - Advanced:
 *       'js' => array(
 *         array(
 *           'js/skin-name-advanced.js',
 *           array(
 *             'scope' => 'footer',
 *             'group' => JS_THEME,
 *         ),
 *       )
 * - options (required): An array containing one or more options (also arrays)
 *   for the user to choose from when applying skins. Each option key should be
 *   a machine name describing the option. An option should including the
 *   following keys:
 *   - label (required): The option label.
 *   - class (required): An array containing one or more classes the skin
 *     should apply. All classes should be entered as an array: For example:
 *       'class' => array('class-b', 'class-b')
 *   - attached (optional): Same syntax as above, but applies to a specific
 *     option only.
 * - theme hooks (optional): An array containing certain allowed hooks, which
 *   allow you to limit where the skin can be used. Allowed options include:
 *   block, block__MODULE, comment, comment__NODETYPE, comment_wrapper,
 *   comment__wrapper_NODETYPE, node, node__NODETYPE, region,
 *   region__REGIONNAME, panels_display, panels_region, panels_pane, views_view,
 *   views_view__STYLENAME, views_view__DISPLAY_NAME, views_view__VIEWNAME, and
 *   views_view__VIEWNAME_DISPLAYNAME.
 * - default_status (optional): Skins are disabled by default to keep UI
 *   clutter to a minimum. In some cases, like contrib themes, it makes sense to
 *   enable skins which are required to make the theme work properly by default.
 *   Setting this property to 1, will cause it to be enabled it by default for
 *   all installed themes.
 *
 * The "hook" prefix is substituted with the name of the module or theme
 * implementing it, followed by the plugin name, e.g.
 * THEMENAME_PLUGINNAME_skinr_skin_info(), or
 * MODULENAME_PLUGINNAME_skinr_skin_info().
 * 
 */
function barrio_skinr_skin_info() {
  $skins['barrio_skins_general_styles'] = array(
    'title' => t('Rounded Corners'),
    // 'description' => t('These control rounded corners for block'),
    'theme hooks' => array('block'),
    'type' => 'checkboxes',
    'group' => 'general',
    'default status' => TRUE,
    'options' => array(
      'barrio-border' => array(
        'title' => t('Block: rounded corners'),
        'class' => array('gborder'),
      ),
      'barrio-border-top' => array(
        'title' => t('Block: rounded corners top'),
        'class' => array('gborder-top'),
      ),
      'barrio-shadow' => array(
        'title' => t('Block: box shadow'),
        'class' => array('gboxshadow'),
      ),
      'barrio-border-top-menu' => array(
        'title' => t('Main Menu Item: rounded corners top'),
        'class' => array('gborder-top-menu'),
      ),
    ),
  );  
  $skins['barrio_align'] = array(
    'title' => t('Content alignment'),
    'type' => 'select',
    'group' => 'layout',
    'default status' => '1',
    'options' => array(
      'left' => array(
        'title' => 'Left',
        'class' => array('left'),
      ),
      'center' => array(
        'title' => 'Center',
        'class' => array('center'),
      ),
      'right' => array(
        'title' => 'Right',
        'class' => array('right'),
      ),
    ),
  );
  $skins['barrio_margin'] = array(
    'title' => t('Margins'),
    'group' => 'layout',
    'default status' => '1',
    'theme hooks' => array('block', 'panels_pane', 'views_view', 'node', 'region'),
    'options' => array(
      'top-10' => array(
        'title' => t('Add 10px to top'),
        'class' => array('top-10'),
      ),
      'right-10' => array(
        'title' => t('Add 10px to right'),
        'class' => array('right-10'),
      ),
      'bottom-10' => array(
        'title' => t('Add 10px to bottom'),
        'class' => array('bottom-10'),
      ),
      'left-10' => array(
        'title' => t('Add 10px to left'),
        'class' => array('left-10'),
      ),
    ),
  );
  $skins['barrio_fontcase'] = array(
    'title' => t('Alter text case'),
    'type' => 'select',
    'group' => 'typography',
    'default status' => '1',
    'options' => array(
      'uppercase' => array(
        'title' => t('Uppercase'),
        'class' => array('uppercase'),
      ),
      'lowercase' => array(
        'title' => t('Lowercase'),
        'class' => array('lowercase'),
      ),
      'capitalize' => array(
        'title' => t('Capitalize'),
        'class' => array('capitalize'),
      ),
    ),
  );
  $skins['barrio_fontsize'] = array(
    'title' => t('Page font size'),
    'type' => 'select',
    'group' => 'typography',
    'default status' => '1',
    'options' => array(
      'sm-font' => array(
        'title' => t('Small'),
        'class' => array('sm-font'),
      ),
      'md-font' => array(
        'title' => t('Medium'),
        'class' => array('md-font'),
      ),
      'lg-font' => array(
        'title' => t('Large'),
        'class' => array('lg-font'),
      ),
      'ex-font' => array(
        'title' => t('Extra Large'),
        'class' => array('ex-font'),
      ),
      'giant-font' => array(
        'title' => t('Giant (use with caution)'),
        'class' => array('giant-font'),
      ),
    ),
  );
  $skins['barrio_headings'] = array(
    'title' => t('Headings'),
    'description' => t('This option will only change the heading font on this element.'),
    'type' => 'select',
    'group' => 'typography',
    'default status' => '1',
    'options' => array(
      'serif-heading' => array(
        'title' => t('Serif headings'),
        'class' => array('serif-heading'),
      ),
      'lucida-heading' => array(
        'title' => t('Lucida sans headings'),
        'class' => array('lucida-heading'),
      ),
      'mono-heading' => array(
        'title' => t('Monospace headings'),
        'class' => array('mono-heading'),
      ),
      'verdana-heading' => array(
        'title' => t('Verdana headings'),
        'class' => array('verdana-heading'),
      ),
    ),
  );
  $skins['barrio_fontstack'] = array(
    'title' => t('Font stacks'),
    'description' => t('This option will change the font stack for this element.'),
    'type' => 'select',
    'group' => 'typography',
    'default status' => '1',
    'options' => array(
      'serif-all' => array(
        'title' => t('Big Caslon, Book Antiqua, Palatino Linotype, Georgia, serif'),
        'class' => array('serif-all'),
      ),
      'lucida-all' => array(
        'title' => t('Lucida Grande, Lucida Sans Unicode, Lucida Sans, Geneva, Verdana, sans-serif'),
        'class' => array('lucida-all'),
      ),
      'mono-all' => array(
        'title' => t('Consolas, Courier New, Courier, mono'),
        'class' => array('mono-all'),
      ),
      'verdana-heading' => array(
        'title' => t('Verdana, Geneva, sans-serif'),
        'class' => array('verdana-all'),
      ),
    ),
  );
  $skins['barrio_lists'] = array(
    'title' => t('List styles'),
    'type' => 'select',
    'group' => 'barrio_links',
    'default status' => '1',
    'theme hooks' => array('block', 'panels_pane', 'views_view', 'node', 'region'),
    'options' => array(
      'img' => array(
        'title' => t('List style with image'),
        'class' => array('img'),
      ),
      'blocky' => array(
        'title' => t('Blocky list with barrio hover'),
        'class' => array('blist'),
      ),
      'grey' => array(
        'title' => t('Blocky list with grey hover'),
        'class' => array('blist', 'grey'),
      ),
    ),
  );
  
  $skins['barrio_block_positioning'] = array(
    'title' => t('Block position'),
    'type' => 'select',
    'description' => t('Change the position of this block (default is to float to the left)'),
    'group' => 'layout',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => array(
      'fusion-right' => array(
        'title' => 'Float block to the right',
        'class' => array('fusion-right'),
      ),
      'fusion-center' => array(
        'title' => 'Position block in the center',
        'class' => array('fusion-center'),
      ),
      'fusion-clear' => array(
        'title' => 'Clear floats (block drops to a new line)',
        'class' => array('fusion-clear'),
      ),      
    ),
  );
  
  $skins['barrio_content_alignment'] = array(
    'title' => t('Content alignment'),
    'description' => t('Default is left aligned content'),
    'type' => 'select',
    'group' => 'layout',
    'default status' => TRUE,
    'options' => array(
      'fusion-right' => array(
        'title' => 'Center align content within its container',
        'class' => array('fusion-center-content'),
      ),
      'fusion-center' => array(
        'title' => 'Right align content within its container',
        'class' => array('fusion-right-content'),
      ),   
    ),
  );  
  
  $skins['barrio_general_styles'] = array(
    'title' => t('General styles'),
    // 'description' => t('These are some generally useful options for blocks'),
    'theme hooks' => array('block'),
    'type' => 'checkboxes',
    'group' => 'general',
    'default status' => TRUE,
    'options' => array(
      'fusion-callout' => array(
        'title' => t('Text: large, bold callout style'),
        'class' => array('fusion-callout'),
      ),
      'fusion-bold-links' => array(
        'title' => t('Links: bold all links'),
        'class' => array('fusion-bold-links'),
      ),
      'fusion-padding' => array(
        'title' => 'Padding: add 30px extra padding inside block',
        'class' => array('fusion-padding'),
      ),
      'fusion-border' => array(
        'title' => 'Border: add 1px border and 10px padding',
        'class' => array('fusion-border'),
      ),
    ),
  );  
  
  $skins['barrio_equal_heights'] = array(
    'title' => t('Equal heights'),
    'description' => t('Make blocks in a region the same height'),
    'theme hooks' => array('block', 'panels_display', 'panels_pane', 'panels_panel'),
    'type' => 'checkboxes',
    'group' => 'layout',
    'default status' => TRUE,
    'attached' => array(
       'js' => array('js/jquery.equalheights.js'), 
    ),
    'options' => array(
      'equal-heights' => array(
        'title' => 'Equal heights: equalize the heights of blocks with this style in the same region',
        'class' => array('equal-heights'),
      ),
    ),
  );    
  
  $skins['barrio_multicol'] = array(
    'title' => t('List columns'),
    'type' => 'select',
    'description' => t('Put items in lists (menus, list views, etc.) in multiple columns'),    
    'theme hooks' => array('block', 'panels_display', 'panels_pane', 'panels_panel', 'views_view'),    
    'group' => 'general',
    'default status' => TRUE,
    'options' => array(
      'fusion-2-col-list' => array(
        'title' => '2-column list/menu (50%/50%)',
        'class' => array('fusion-2-col-list', 'clearfix'),
      ),
      'fusion-3-col-list' => array(
        'title' => '3-column list/menu (33%/33%/33%)',
        'class' => array('fusion-3-col-list', 'clearfix'),      
      )
    ),
  );   
  
  $skins['barrio_menu'] = array(
    'title' => t('Menu Layout'),
    'type' => 'select',
    'description' => t('Different layouts and alignment options for your menus'),    
    'theme hooks' => array('block', 'panels_display', 'panels_pane', 'panels_panel'),    
    'group' => 'barrio_links',
    'default status' => TRUE,
    'options' => array(
      'fusion-inline-menu' => array(
        'title' => 'Single line menu with separators',
        'class' => array('fusion-inline-menu'),
      ),
      'fusion-multicol-menu' => array(
        'title' => t('Multi-column menu with bold headers (set menu items to Expanded)'),
        'class' => array('fusion-multicol-menu', 'clearfix')
      )
    ),
  );  
  
  $skins['barrio_list_styles'] = array(
    'title' => t('List/menu styles'),
    'type' => 'checkboxes',
    'theme hooks' => array('block', 'panels_display', 'panels_pane', 'panels_panel', 'views_view'),    
    'group' => 'barrio_links',
    'default status' => TRUE,
    'options' => array(
      'fusion-list-bottom-border' => array(
        'title' => t('Bottom border (no bullets)'),
        'class' => array('fusion-list-bottom-border'),
      ),
      'fusion-multicol-menu' => array(
        'title' => t('Extra vertical spacing (no bullets)'),
        'class' => array('fusion-list-vertical-spacing')
      )
    ),
  );  
    
  $skins['barrio_float_imagefield'] = array(
    'title' => t('Image floating styles'),
    'type' => 'select',
    'description' => t('These options will float ImageField images in content to the left or right and add margins'),
    'theme hooks' => array('block', 'node', 'views_view'),    
    'group' => 'layout',
    'default status' => TRUE,
    'options' => array(
      'fusion_float_imagefield_left' => array(
        'title' => t('Float ImageField left'),
        'class' => array('fusion-float-imagefield-left'),
      ),
      'fusion_float_imagefield_right' => array(
        'title' => t('Float ImageField right'),
        'class' => array('fusion-float-imagefield-right'),
      ),
    ),
  );   
  
  $skins['barrio_login'] = array(
    'title' => t('User login block styles'),
    'theme hooks' => array('block', 'panels_display', 'panels_pane', 'panels_panel'),
    'group' => 'box',
    'default status' => TRUE,
    'attached' => array(
       'js' => array('js/jquery.overlabel.js'), 
    ),
    'options' => array(
      'fusion_float_imagefield_left' => array(
        'title' => t('Horizontal: puts user login block on a single line with label overlays (good for Header Top region)'),
        'class' => array('fusion-horiz-login'),
      ),
    ),
  );
  
  // @todo: detect current grid, and add column settings accordingly.
  $skins['barrio_grid16_width'] = array(
    'title' => t('Width (16 column grid)'),
    'description' => t("Change the width of this block. Fluid grid % widths are relative to the parent region's width. Default widths: sidebar blocks default to the sidebar width; in other regions width is divided equally among all blocks."),    
    'type' => 'select',
    'group' => 'layout',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => _barrio_grid_options(16, 960),   
  );  
  
  $skins['barrio_grid12_width'] = array(
    'title' => t('Width (12 column grid)'),
    'description' => t("Change the width of this block. Fluid grid % widths are relative to the parent region's width. Default widths: sidebar blocks default to the sidebar width; in other regions width is divided equally among all blocks."),
    'type' => 'select',
    'group' => 'layout',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => _barrio_grid_options(12, 960),   
  );     
 
  return $skins;
}

/**
 * Generates fusion_apply options based on Fusion grid parameters.
 * Assists in hook_fusion_apply_skin_PLUGIN_info() implementation.
 * @return array
 */
function _barrio_grid_options($units, $width) {
  $options = array();
  $unit_width = floor($width / $units);
  for ($i = 1; $i <= $units; $i++) {
    $plural = ($i == 1) ? '' : 's';
    $this_width = $i * $unit_width;
    $this_percentage = round($i * (100 / $units), 2);
    $options["grid{$units}-{$i}"] = array(
      'title' => "$i unit{$plural} wide ({$this_width}px/{$this_percentage}%)",
      'class' => "grid{$units}-{$i}"
    );
  }
  return $options;
}
