<?php
/**
 * Page callback for leavenotice.
 */
 
function leavenotice_admin_form($form, $form_state) {
  $form = array();
  $form['leavenotice_container'] = array(
    '#required' => FALSE,
    '#size' => 32,
    '#default_value' => variable_get('leavenotice_container', ''),
    '#description' => t('the container in which to search for external links'),
    '#weight' => 0,
    '#type' => 'textfield',
    '#title' => t('Container'),
  );
  $form['leavenotice_sitename'] = array(
    '#required' => FALSE,
    '#size' => 64,
    '#default_value' => variable_get('leavenotice_sitename', ''),
    '#description' => t('The name of your site, such a Bob\'s Art Emporium'),
    '#weight' => 0,
    '#type' => 'textfield',
    '#title' => t('Site Name'),
  );
  $form['leavenotice_exit_message'] = array(
    '#required' => FALSE,
    '#default_value' => variable_get('leavenotice_exit_message', ''),
    '#description' => t('The message that is shown your visitors to let them know they are leaving'),
    '#weight' => 0,
    '#type' => 'textarea',
    '#title' => t('Exist Message'),
  );
  $form['leavenotice_pre_link_message'] = array(
    '#required' => FALSE,
    '#size' => 64,
    '#default_value' => variable_get('leavenotice_pre_link_message', ''),
    '#description' => t('the text that comes before the link, such \'as off you go to {url}\''),
    '#weight' => 0,
    '#type' => 'textfield',
    '#title' => t('Pre-Link Message'),
  );
  $form['leavenotice_new_window'] = array(
    '#type' => 'checkbox',
    '#title' => t('New Window?'),
    '#default_value' => variable_get('leavenotice_new_window', 0),
    '#description' => t("Allows the link in the dialog to open in a new window. Note: This setting automatically sets timeOut to 0 since popup blockes block windows opened automatically by JavaScript."),
  );
  $form['leavenotice_timeout'] = array(
    '#required' => FALSE,
    '#size' => 4,
    '#default_value' => variable_get('leavenotice_timeout', ''),
    '#description' => t('The length of time the dialog is shown before the user is linked to the page they are trying to access. Setting to \'0\' will disable the auto redirect and make it so the user has to explicitly click the link.'),
    '#weight' => 0,
    '#type' => 'textfield',
    '#title' => t('Delay Time'),
  );

  return system_settings_form($form);
}
