<?php

/**
 * @file
 * Alumni Cas Auth module settings UI.
 */

/**
 * Provides settings pages.
 */
function alumni_cas_auth_admin_settings() {

  $form['account'] = array(
    '#type' => 'fieldset',
    '#title' => t('User accounts'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['account']['alumni_cas_auth_user_register'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatically create Drupal accounts'),
    '#default_value' => variable_get('alumni_cas_auth_user_register', 1),
    '#description' => t('Whether a Drupal account is automatically created the first time a alumni cas user logs into the site. If disabled, you will need to pre-register Drupal accounts for authorized users.'),
  );

  $form['account']['alumni_cas_auth_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail address'),
    '#field_prefix' => t('username@'),
    '#default_value' => variable_get('alumni_cas_auth_domain', ''),
    '#size' => 30,
    // Hostnames can be 255 characters long.
    '#maxlength' => 255,
    '#description' => t("If provided, automatically generate each new user's e-mail address. If omitted, the e-mail field will not be populated. Other modules may be used to populate the e-mail field from CAS attributes or LDAP servers."),
  );

  $form['account']['alumni_cas_auth_hide_email'] = array(
    '#type' => 'checkbox',
    '#title' => t('Users cannot change email address'),
    '#default_value' => variable_get('alumni_cas_auth_hide_email', 0),
    '#description' => t('Hide email address field on the edit user form.'),
  );

  $form['account']['alumni_cas_auth_hide_password'] = array(
    '#type' => 'checkbox',
    '#title' => t('Users cannot change password'),
    '#default_value' => variable_get('alumni_cas_auth_hide_password', 0),
    '#description' => t('Hide password field on the edit user form. This also removes the requirement to enter your current password before changing your e-mail address.'),
  );

  $form['pages'] = array(
    '#type' => 'fieldset',
    '#title' => t('Redirection'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['pages']['alumni_cas_auth_access'] = array(
    '#type' => 'radios',
    '#title' => t('Require alumni cas login for'),
    '#default_value' => variable_get('alumni_cas_auth_access', 0),
    '#options' => array(t('specific pages'), t('all pages except specific pages')),
  );

  $form['pages']['alumni_cas_auth_pages'] = array(
    '#type' => 'textarea',
    '#title' => t('Specific pages'),
    '#default_value' => variable_get('alumni_cas_auth_pages', ''),
    '#cols' => 40,
    '#rows' => 5,
    '#description' => t("Enter one page per line as Drupal paths. The '*' character is a wildcard. Example paths are '<em>blog</em>' for the blog page and '<em>blog/*</em>' for every personal blog. '<em>&lt;front&gt;</em>' is the front page."),
  );

  $form['pages']['alumni_cas_auth_exclude'] = array(
    '#type' => 'textarea',
    '#title' => t('Excluded Pages'),
    '#default_value' => variable_get('alumni_cas_auth_exclude', ALUMNI_CAS_AUTH_EXCLUDE),
    '#cols' => 40,
    '#rows' => 5,
    '#description' => t("Indicates which pages will be ignored (no login checks). Enter one page per line as Drupal paths. The '*' character is a wildcard. Example paths are '<em>blog</em>' for the blog page and '<em>blog/*</em>' for every personal blog. '<em>&lt;front&gt;</em>' is the front page."),
  );

  $form['private_files'] = array(
    '#type' => 'fieldset',
    '#title' => t('Private Files'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['private_files']['alumni_cas_auth_private_files_base_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Private Files Base Path'),
    '#default_value' => variable_get('alumni_cas_auth_private_files_base_path', ''),
    '#size' => 30,
    '#maxlength' => 255,
    '#description' => t("Indicates the private files base path"),
  );

  $form['private_files']['alumni_cas_auth_check_private_file_access'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enforce Authentication for Private Files'),
    '#default_value' => variable_get('alumni_cas_auth_check_private_file_access', 1),
  );

  $form['misc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Login/Logout Destinations'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Settings for redirection upon first login
  $form['misc']['alumni_cas_auth_first_login_destination'] = array(
    '#type' => 'textfield',
    '#title' => t('Initial login destination'),
    '#default_value' => variable_get('alumni_cas_auth_first_login_destination', ''),
    '#size' => 40,
    '#maxlength' => 255,
    '#description' => t("Drupal path or URL. Enter a destination if you want the user to be redirected to this page on their first alumni cas login. An example path is <em>blog</em> for the blog page, <em>&lt;front&gt;</em> for the front page, or <em>user</em> for the user's page."),
  );

  // Setting for page to return to after an alumni cas logout
  $form['misc']['alumni_cas_auth_logout_destination'] = array(
    '#type' => 'textfield',
    '#title' => t('Logout destination'),
    '#default_value' => variable_get('alumni_cas_auth_logout_destination', ''),
    '#size' => 40,
    '#maxlength' => 255,
    '#description' => t("Drupal path or URL. Enter a destination if you want a user to be directed to this page after logging out of simplesaml, or leave blank to direct users back to the previous page. An example path is <em>blog</em> for the blog page or <em>&lt;front&gt;</em> for the front page."),
  );

  // Auth url
  $form['misc']['alumni_cas_auth_auth_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Auth Url'),
    '#default_value' => variable_get('alumni_cas_auth_auth_url', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => t("URL. Enter a Auth Url"),
  );

  // Cas
  $form['misc']['cas_getLogin_type_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Cas Login Url'),
    '#default_value' => variable_get('cas_getLogin_type_url', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => t("URL. Enter a Cas login type Url"),
  );

  return system_settings_form($form);
}
