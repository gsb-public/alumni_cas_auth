<?php

class AlumniCasUser {

  private $stanford_id;
  private $user_id;
  private $timestamp;

  public function __construct() {
  }

  public function authenicate($next_url = null) {
    if ($next_url == null) {
      $next_url = $GLOBALS['base_url'] . '/' . $_SERVER['REQUEST_URI'];
      $next_url = str_replace('/', '*', $next_url);
      $next_url = str_replace('?', '$', $next_url);
      $next_url = str_replace('&', '$', $next_url);
    }
    $auth_url = 'https://alumni-gsb.stanford.edu/cas/service/checkauth?pg=yes&am=tpartyFA&exid=gsb&nu=' . $next_url;
    drupal_goto($auth_url, array(), 307);
  }

  public function is_authenicated() {
    if (cas_is_authenicated()) {
      $this->set_stanford_id(cas_get_stanford_id());
      $this->set_user_id(cas_get_user_id());
      $this->set_timestamp(cas_get_timestamp());
      return TRUE;
    }
    return FALSE;
  }

  public function returning_from_cas_login() {
    watchdog(WATCHDOG_INFO, 'in returning_from_cas_login 0');
    /*
    $cpath = current_path();
    watchdog(WATCHDOG_INFO, 'in returning_from_cas_login cpath = ' . $cpath);
    if ($cpath == 'alumni-cas-auth-check-auth') {
      watchdog(WATCHDOG_INFO, 'in returning_from_cas_login 1a');
      if (isset($_SERVER['HTTP_REFERER'])) {
        $pos = strpos($_SERVER['HTTP_REFERER'], 'uebc');
        watchdog(WATCHDOG_INFO, 'in returning_from_cas_login 1b pos = ' . $pos);
        if (strpos($_SERVER['HTTP_REFERER'], 'uebc') !== FALSE) {
          watchdog(WATCHDOG_INFO, 'in returning_from_cas_login 1c');
          return TRUE;
        }
      }
    }
    */
    if (isset($_GET['uebc'])) {
      watchdog(WATCHDOG_INFO, 'in returning_from_cas_login 1');
      return TRUE;
    }
    watchdog(WATCHDOG_INFO, 'in returning_from_cas_login 2');
    return FALSE;
  }

  public function set_stanford_id($id) {
    $this->stanford_id = $id;
  }

  public function get_stanford_id() {
    return $this->stanford_id;
  }

  public function set_user_id($id) {
    $this->user_id = $id;
  }

  public function get_user_id() {
    return $this->user_id;
  }

  public function set_timestamp($timestamp) {
    $this->timestamp = $timestamp;
  }

  public function get_timestamp() {
    return $this->timestamp;
  }

}
