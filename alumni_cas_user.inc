<?php 

class AlumniCasUser {

  private $stanford_id;

  public function __construct() {
  }

  public function authenicate() {
    watchdog(WATCHDOG_INFO, 'in alumni_cas_user authenicate 0');
    if (isset($GLOBALS['base_url'])) {
      watchdog(WATCHDOG_INFO, 'in alumni_cas_user authenicate 0 - is set');
    } else {
      watchdog(WATCHDOG_INFO, 'in alumni_cas_user authenicate 0 - is not set');
    }
    watchdog(WATCHDOG_INFO, 'in alumni_cas_user authenicate 0a' . $GLOBALS['base_url']);
    $next_url = $GLOBALS['base_url'] . '/' . $_SERVER['REQUEST_URI'];
    watchdog(WATCHDOG_INFO, 'in alumni_cas_user authenicate 1');
    $next_url = str_replace('/', '*', $next_url);
    watchdog(WATCHDOG_INFO, 'in alumni_cas_user authenicate 2');
    watchdog(WATCHDOG_INFO, $GLOBALS['base_url']);
    watchdog(WATCHDOG_INFO, request_path());
    $auth_url = 'https://alumni-gsb.stanford.edu/cas/service/checkauth?pg=yes&am=tpartyFA&exid=gsb&nu=' . $next_url;
    drupal_goto($auth_url, array(), 307);
  }

  public function is_authenicated() {  
    watchdog(WATCHDOG_INFO, 'in alumni_cas_user is_authenicated');
    if (cas_is_authenicated()) {
      $this->set_stanford_id(cas_get_stanford_id());
      watchdog(WATCHDOG_INFO, 'in alumni_cas_user is_authenicated - returning TRUE');
      return TRUE;
    }
    watchdog(WATCHDOG_INFO, 'in alumni_cas_user is_authenicated - returning FALSE');
    return FALSE;
  }

  public function returning_from_cas_login() {
    watchdog(WATCHDOG_INFO, 'in alumni_cas_user returning_from_cas_login');
    if (isset($_GET['uebc'])) {
      watchdog(WATCHDOG_INFO, 'in alumni_cas_user returning_from_cas_login - returning TRUE');
      return TRUE;
    }
    watchdog(WATCHDOG_INFO, 'in alumni_cas_user returning_from_cas_login - returning FALSE');
    return FALSE;
  }

  public function set_stanford_id($id) {
    watchdog(WATCHDOG_INFO, 'in alumni_cas_user set_stanford_id - id = ' . $id);
    $this->stanford_id = $id;
  }

  public function get_stanford_id() {
    watchdog(WATCHDOG_INFO, 'in alumni_cas_user get_stanford_id - id = ' . $this->stanford_id);
    return $this->stanford_id;
  }  

}