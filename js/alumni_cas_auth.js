(function ($) {

Drupal.behaviors.color = {
  attach: function (context, settings) {
    if (jQuery('.cas-login')) {
      var pathname = window.location.pathname;
      pathname = pathname.substring(1);
      console.log('pathname = ' + pathname);
      var login_href = jQuery('.cas-login').attr('href');
      //jQuery('.cas-login').attr('href', login_href + '?goto=' + pathname);
      // Check if user is authenticated with Cas
      var check_auth =
        jQuery.getJSON( settings.alumni_cas_auth.path + "alumni-cas-auth-check-auth", function(data) {
          console.log(data.authenication_status);
          console.log(data);
          console.log( "success" );
        })
        .fail(function() {
          console.log( "error" );
        })
        .always(function() {
          console.log( "finished" );
        });
    }
  }
};

})(jQuery);
