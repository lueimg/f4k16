<?php 

/**
 * Override or insert variables into the page template for HTML output.
 */
function barrio_process_html(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($variables);
  }
}

/**
 * Override or insert variables into the page template.
 */
function barrio_process_page(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($variables);
  }
}

/**
  * modify search box using hook form alter
*
*/

function barrio_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#size'] = 25;
    $form_default = t('Search');
    $form['search_block_form']['#default_value'] = $form_default;
    $form['search_block_form']['#attributes'] = array('onblur' => "if (this.value == '') {this.value = '{$form_default}';}", 'onfocus' => "if (this.value == '{$form_default}') {this.value = '';}" );
	$form['actions']['submit']['#attributes']['type'] = 'image';
  	$form['actions']['submit']['#attributes']['src'] = path_to_theme() . '/images/search-button.png';
  }    
}

/**
 * Search block preprocessing
 
function wordtech_preprocess_search_block_form(&$vars, $hook) {
  // Modify elements of the search form
  unset($vars['form']['search_block_form']['#printed']);

  // Set a default value for the search box
  $vars['form']['search_block_form']['#value'] = $form_default;
  $vars['form']['search_block_form']['#attributes'] = array('onblur' => "if (this.value == '') {this.value = '{$form_default}';}", 'onfocus' => "if (this.value == '{$form_default}') {this.value = '';}" );

  // Rebuild the rendered version (search form only, rest remains unchanged)
  unset($vars['form']['search_block_form']['#printed']);
  $vars['search']['search_block_form'] = drupal_render($vars['form']['search_block_form']);

  // Collect all form elements to print entire form
  $vars['search_form'] = implode($vars['search']);

}
*/
?>