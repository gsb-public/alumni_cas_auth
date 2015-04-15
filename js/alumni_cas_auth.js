(function ($) {

Drupal.behaviors.alumni_case_auth = {
  attach: function (context, settings) {
    if (jQuery('.cas-login').length > 0) {
      // Check if user is authenticated with Cas
      jQuery.getJSON( settings.alumni_cas_auth.cas_getLogin_type_url, function(data) {
        if (data.loginState == "CAS") {
          jQuery('.cas-login').hide();
        }
        else {
          jQuery('.cas-logout').hide();
        }
      })
      .fail(function() {
        jQuery('.cas-logout').hide();
      });
    }
  }
};

})(jQuery);
