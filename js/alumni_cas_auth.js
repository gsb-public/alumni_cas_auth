(function ($) {

Drupal.behaviors.alumni_case_auth = {
  attach: function (context, settings) {
    if (jQuery('.cas-login')) {
      // Check if user is authenticated with Cas
      jQuery.getJSON( settings.alumni_cas_auth.cas_getLogin_type_url, function(data) {
        console.log(data);
        if (data.loginState == "CAS") {
          jQuery('.cas-login').hide();
          console.log('hiding login');
        }
        else {
          jQuery('.cas-logout').hide();
          console.log('hiding logout');
        }
      })
      .fail(function() {
        jQuery('.cas-logout').hide();
        console.log('hiding logout');
      });
    }
  }
};

})(jQuery);
