<?php

// Put the logo path into JavaScript for the live preview.
drupal_add_js(array('color' => array('logo' => theme_get_setting('logo', 'barrio'))), 'setting');

$info = array(
  // Available colors and color labels used in theme.
  'fields' => array(
    'top' => t('Header top'),
    'bottom' => t('Header bottom'),
    'bg' => t('Main background'),
	'bgcontent'  => t('Content background'),
    'sidebar' => t('Sidebar block background'),
    'sidebarborders' => t('Sidebar block borders'),
    'footer' => t('Footer background'),
    'titleslogan' => t('Title and slogan'),
    'text' => t('Text color'),
    'link' => t('Link color'),
	'linkactive' => t('Link active color'),
	'pagerborder' => t('Pager border'),
    'pagertext' => t('Pager text'),
    'pagerbg' => t('Pager background'),
    'menu' => t('Menu text'),
    'menuhover' => t('Menu text hover'),
    'menubg' => t('Menu background'),
  ),
  // Pre-defined color schemes.
  'schemes' => array(
    'default' => array(
      'title' => t('Ice (default)'),
      'colors' => array(
        'top' => '#d0d0d0',
        'bottom' => '#c2c4c5',
        'bg' => '#eeeeee',
		'bgcontent'  => '#f5f5f5',
        'sidebar' => '#ffffff',
        'sidebarborders' => '#cccccc',
        'footer' => '#24272c',
        'titleslogan' => '#000000',
        'text' => '#4a4a4a',
        'link' => '#019dbf',
		'linkactive' => '#018fe2',
		'pagerborder' => '#333333',
		'pagertext' => '#777777',
		'pagerbg' => '#ffffff',
		'menu' => '#333333',
		'menuhover' => '#111111',
		'menubg' => '#f5f5f5',
      ),
    ),
    'bluelagoon' => array(
      'title' => t('Blue Lagoon'),
      'colors' => array(
        'top' => '#0779bf',
        'bottom' => '#48a9e4',
        'bg' => '#ffffff',
		'bgcontent'  => '#f5f5f5',
        'sidebar' => '#f6f6f2',
        'sidebarborders' => '#f9f9f9',
        'footer' => '#292929',
        'titleslogan' => '#ffffff',
        'text' => '#3b3b3b',
        'link' => '#0071B3',
		'pagerborder' => '#333333',
		'pagertext' => '#777777',
		'pagerbg' => '#ffffff',
		'menu' => '#333333',
		'menuhover' => '#111111',
		'menubg' => '#ffffff',
      ),
    ),
    'firehouse' => array(
      'title' => t('Firehouse'),
      'colors' => array(
        'top' => '#cd2d2d',
        'bottom' => '#cf3535',
        'bg' => '#ffffff',
		'bgcontent'  => '#f5f5f5',
        'sidebar' => '#f1f4f0',
        'sidebarborders' => '#ededed',
        'footer' => '#1f1d1c',
        'titleslogan' => '#fffeff',
        'text' => '#3b3b3b',
        'link' => '#d6121f',
		'linkactive' => '#018fe2',
		'pagerborder' => '#333333',
		'pagertext' => '#777777',
		'pagerbg' => '#ffffff',
		'menu' => '#333333',
		'menuhover' => '#111111',
		'menubg' => '#ffffff',
      ),
    ),
    'plum' => array(
      'title' => t('Plum'),
      'colors' => array(
        'top' => '#4c1c58',
        'bottom' => '#593662',
        'bg' => '#fffdf7',
		'bgcontent'  => '#f5f5f5',
        'sidebar' => '#edede7',
        'sidebarborders' => '#e7e7e7',
        'footer' => '#2c2c28',
        'titleslogan' => '#ffffff',
        'text' => '#301313',
        'link' => '#9d408d',
		'linkactive' => '#018fe2',
		'pagerborder' => '#333333',
		'pagertext' => '#777777',
		'pagerbg' => '#fffdf7',
		'menu' => '#333333',
		'menuhover' => '#111111',
		'menubg' => '#ffffff',
      ),
    ),
    'slate' => array(
      'title' => t('Slate'),
      'colors' => array(
        'top' => '#4a4a4a',
        'bottom' => '#4e4e4e',
        'bg' => '#ffffff',
		'bgcontent'  => '#f5f5f5',
        'sidebar' => '#ffffff',
        'sidebarborders' => '#d0d0d0',
        'footer' => '#161617',
        'titleslogan' => '#ffffff',
        'text' => '#3b3b3b',
        'link' => '#0073b6',
		'linkactive' => '#018fe2',
		'pagerborder' => '#333333',
		'pagertext' => '#777777',
		'pagerbg' => '#ffffff',
		'menu' => '#333333',
		'menuhover' => '#111111',
		'menubg' => '#ffffff',
      ),
    ),
  ),
  
  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => array(
    'css/colors.css',
  ),

  // Files to copy.
  'copy' => array(
    'logo.png',
  ),

  // Gradient definitions.
  'gradients' => array(
    array(
      // (x, y, width, height).
      'dimension' => array(0, 0, 0, 0),
      // Direction of gradient ('vertical' or 'horizontal').
      'direction' => 'vertical',
      // Keys of colors to use for the gradient.
      'colors' => array('top', 'bottom'),
    ),
  ),

  // Color areas to fill (x, y, width, height).
  'fill' => array(),

  // Coordinates of all the theme slices (x, y, width, height)
  // with their filename as used in the stylesheet.
  'slices' => array(),

  // Reference color used for blending. Matches the base.png's colors.
  'blend_target' => '#ffffff',

  // Preview files.
  'preview_css' => 'color/preview.css',
  'preview_js' => 'color/preview.js',
  'preview_html' => 'color/preview.html',

  // Base file for image generation.
  'base_image' => 'color/base.png',
);
