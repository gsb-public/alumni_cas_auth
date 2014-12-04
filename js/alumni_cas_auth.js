(function ($) {

Drupal.behaviors.color = {
  attach: function (context, settings) {
    console.log(settings);
    //var query = window.location.search;
    //console.log('qstring = ' + query);
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
};

})(jQuery);