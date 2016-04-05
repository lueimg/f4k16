(function($) {
	$(document).ready(function(){
		$(window).bind("scroll", function(){
			if ($("#menu-bar-wrapper").css("position") == "fixed") {
				$("#block-block-31").css("margin-top", "55px");
			}
			else {
				$("#block-block-31").css("margin-top", "0");
			}
		});		
	});		
})(jQuery);