<?php 
/**
 * @file
 * Administrative page callbacks.
 */

/**
 * Page callback.
 */
function leavenotice_admin_settings_form($form, $form_state) {
  // leavenotice global variables

  /*
  define('leavenotice_url', 'http://rewdy.com/projects/view/leavenotice/');
  define('leavenotice_sitename', 'my site');
  define('leavenotice_css_selector', 'body');
  define('leavenotice_newwindow', '');
  define('leavenotice_exit_message', '');
  define('leavenotice_linkstring', '');
  define('leavenotice_timeout', '');
  define('leavenotice_overlayid', '');
  define('leavenotice_messageboxid', '');
  define('leavenotice_messageholderid', '');
  define('leavenotice_overlayalpha', '');
  */

  $form = array(
    'leavenotice_css_selector' => array(
      '#required' => FALSE,
      '#size' => 32,
      '#title' => t('CSS / jQuery selector'),
      '#default_value' => variable_get('leavenotice_css_selector', '[rel="external"]'),
      '#description' => t('CSS/jQuery That the leave notice will apply to. Body will get everything, but may be slow on large DOMs'),
      '#type' => 'textfield',
    ),

    'leavenotice_exit_message' => array(
      '#type' => 'textarea',
      '#title' => t('Exit Message'),
      '#description' => t('This is the text you want to show in the pop-up when someone clicks on an external link. Use {SITENAME} for your site, or {URL} for the site that was clicked on.'),
      '#rows' => 3,
      '#default_value' => variable_get('leavenotice_exit_message', '<p><strong>You have requested a website outside of {SITENAME}.</strong></p><p>Thank you for visiting.</p>')
    ),

    'submit' => array( 
      '#type' => 'submit',
      '#value' => t('Save'),
    )
  );

  return $form;
}

/**
 * Submit callback for config form.
 */
function leavenotice_admin_settings_form_submit($form, $form_state) {
  variable_set('leavenotice_css_selector', $form_state['values']['leavenotice_css_selector']);
  variable_set('leavenotice_exit_message', $form_state['values']['leavenotice_exit_message']);

  drupal_set_message(t('Your configuration has been saved.'));
}