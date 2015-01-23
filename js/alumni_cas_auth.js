(function ($) {

Drupal.behaviors.color = {
  attach: function (context, settings) {
    if (jQuery('.cas-login')) {
      // Check if user is authenticated with Cas
      jQuery.ajax({
        url: "https://pgnet13.stanford.edu/cas/pgjsonp.jsp?callback=getLoginType",
        // The name of the callback parameter
        jsonp: "callback",
        // Tell jQuery we're expecting JSONP
        dataType: "jsonp",
        data: {
          format: "json"
        },
        // Work with the response
        success: function(response) {
          //console.log( response );
        }
      });
    }
  }
};

})(jQuery);

function getLoginType(data) {
  if (data.loginState == "REME") {
    jQuery('.cas-login').hide();
    console.log('hiding login');
  }
  else {
    jQuery('.cas-logout').hide();
    console.log('hiding logout');
  }
}
