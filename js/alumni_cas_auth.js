(function ($) {

Drupal.behaviors.color = {
  attach: function (context, settings) {
    if (jQuery('.cas-login')) {
      // Check if user is authenticated with Cas
      var check_auth =
        jQuery.getJSON( settings.alumni_cas_auth.path + "alumni-cas-auth-check-auth", function(data) {
          if (data.authenication_status) {
            jQuery('.cas-login').hide();
          }
        })
        .fail(function() {
          jQuery('.cas-logout').hide();
        });
    }
  }
};

})(jQuery);
