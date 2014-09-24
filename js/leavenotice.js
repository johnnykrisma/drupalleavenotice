;(function ($) {
  Drupal.behaviors.leavenotice = {
    attach: function (context, settings) {
      $("body a[href]").filter(function() {
          return !this.href.match(/^mailto\:/) && !this.href.match(/\.gov/) && !this.href.match(/addthis/) && !this.href.match(/javascript/) && !this.href.match(/10\.6028/) && this.hostname != location.hostname
      }).addClass("external");
      $(".external").leaveNotice(Drupal.settings.leavenotice);
    }
  }
})(jQuery);